/*************************************************************************
    > File Name: ls.c
    > Author: 冲鸭！小星星
    > Mail: N0 Mail! 
    > Created Time: 2020年03月17日 星期二 11时08分16秒
 ************************************************************************/
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <termios.h>
#include <sys/ioctl.h>

#define BLUE(s) printf("\033[34m%s\033[0m", s);//目录
#define WHITE(s) printf("\033[37m%s\033[0m", s);//普通文件
#define GREEN(s) printf("\033[32m%s\033[0m", s);//可执行文件
#define RED(s) prinntf("\033[31m%s\033[0m", s);//压缩文件
#define BBLUE(s) printf("\033[36m%s\033[0m", s);//链接文件
#define YELLOW(s) printf("\033[33m%s\033[0m", s);//设备文件

#define ls_l 101
#define ls_al 102
void ErrorPrint(char* errorname) {
	perror(errorname);
	return;
}

// -普通文件 d目录文件 c字设备文件
// p管道文件 l连接文件 ssocket文件
char FileType(const struct stat* file_message) {
	mode_t mode = file_message->st_mode;

	if (S_ISREG(mode)) {
		return '-';
	} else if (S_ISDIR(mode)) {
		return 'd';
	} else if (S_ISCHR(mode)) {
		return 'c';
	} else if (S_ISBLK(mode)) {
		return 'b';
	} else if (S_ISFIFO(mode)) {
		return 'p';
	} else if (S_ISLNK(mode)) {
		return 'l';
	} else {
		return 's';
	}
}

void FileMode(const struct stat* file_message) {
	mode_t mode = file_message->st_mode;
	char str[] = "---------.";
	if (S_IRUSR & mode) str[0] = 'r';
	if (S_IWUSR & mode) str[1] = 'w';
	if (S_IXUSR & mode) str[2] = 'x';
	if (S_IRGRP & mode) str[3] = 'r';
	if (S_IWGRP & mode) str[4] = 'w';
	if (S_IXGRP & mode) str[5] = 'x';
	if (S_IROTH & mode) str[6] = 'r';
	if (S_IWOTH & mode) str[7] = 'w';
	if (S_IXOTH & mode) str[8] = 'x';
	printf("%s", str);
}

void FileId(const struct stat* file_message) {
	struct passwd* uidstr;
	uidstr = getpwuid(file_message->st_uid);
	printf("%s ", uidstr->pw_name);

	struct group* gidstr;
	gidstr = getgrgid(file_message->st_gid);
	printf("%s ", gidstr->gr_name);

}

void FileTime(const struct stat* file_message) {
	struct tm* t = localtime(&file_message->st_mtime);
	printf("%2d月 %2d %02d:%02d ", t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min);
}

void FileLink(const char* filename) {
	char buf[1024] = "123";
	if (0 == readlink(filename, buf, sizeof(buf)))
		ErrorPrint("readlink");
	printf("-> %s ", buf);
}

// -普通文件 d目录文件 c字设备文件
// p管道文件 l连接文件 ssocket文件
void PrintColor(const char *filename, const char col) {
	switch (col) {
		case 'd': BLUE(filename); break;
		case 'c': YELLOW(filename); break;
		case 'l': BBLUE(filename); break;
		default: printf("%s ", filename);
	}
}

void list_message(const char* filename, const struct stat* file_message) {
	char color;
	color = FileType(file_message);
	printf("%c", color);
	FileMode(file_message);
	printf(" %d ", file_message->st_nlink);
	FileId(file_message);
	printf("%5ld ", file_message->st_size);
	FileTime(file_message);
	PrintColor(filename, color);
	//printf("%s ", filename);
	if (S_ISLNK(file_message->st_mode))
		FileLink(filename);
	puts("");
}

void DirInfo(const char* pathname, int c) {
	DIR* ret_opendir = opendir(pathname);
	int ret_chdir = chdir(pathname);
	if (ret_opendir == NULL)
		ErrorPrint("opendir");
	if (ret_chdir == -1)
		ErrorPrint("chdir");
	struct dirent* ret_readdir = NULL;
	while (ret_readdir = readdir(ret_opendir)) {
		char* filename = ret_readdir->d_name;
		struct stat file_message = {};
		int ret_stat = lstat(filename, &file_message);
		if (ret_stat == -1)
			printf("%s error!", filename);
		else if (c = ls_l) {
			if (strcmp(filename, ".") && strcmp(filename, ".."))
				list_message(filename, &file_message);
		} else 
			list_message(filename, &file_message);
	}
	//closedir(ret_opendir);
}

int FindMax(int *num, int start, int end) {
	int max = num[start];
	int s = start;
	while (s <= end) {
		if (num[s] > max) max = num[s];
		s++;
	}
	return max;
}

int Dj(int weith, int endsize, int *sum, int k) {
	int col = ((k / endsize) == ((double)k / (double)endsize) ? (k / endsize) : (k / endsize + 1));
	for (int i = 0; i < endsize; i++) {
		if (FindMax(sum, i * col, (i + 1) * col - 1) > weith / endsize) {
			return 0;
		}
	}
	return 1;
}

void FileName(const char *pathname) {
	char *name[100];
	int k = 0, sum[10000];
	struct winsize size;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	int weith = size.ws_col;
	DIR* ret_opendir = opendir(pathname);
	if (ret_opendir == NULL)
		ErrorPrint("opendir");

	int ret_chdir = chdir(pathname);
	if (ret_chdir == -1)
		ErrorPrint("chdir");

	struct dirent* ret_readdir = NULL;
	while (ret_readdir = readdir(ret_opendir)) {
		char* filename = ret_readdir->d_name;
		struct stat file_message = {};
		int ret_stat = lstat(filename, &file_message);
		if (ret_stat == -1)
			printf("%s error!", filename);
		else if (strcmp(filename, ".") && strcmp(filename, "..")) {
			name[k] = filename;
			sum[k] = strlen(filename);
			k++;
		}
	}
	//printf("k = %d\n", k);
	//printf("%d", k / endsize);
	int endsize = 1;
	while (Dj(weith, endsize, sum, k)) {
		endsize++;
	}
	int col = ((k / endsize) == ((double)k / (double)endsize) ? (k / endsize) : (k / endsize + 1));
	for (int i = 0; i <= k / 2; i++) {
		printf("%s", name[i]);
		for (int j = 0; j < weith / endsize - sum[i] - sum[i]; j++) 
			printf(" ");
		printf("%s", name[i + k / endsize]);
		printf("\n");
	}
	printf("\n");
	closedir(ret_opendir);

}


int main(const char argc, const char** argv) {
	char path[1024] = {};
	if (argc == 1) {
		strcpy(path, "./");
		FileName(path);
		return 0;
	}
	else if (argc == 2 ) {
		if (!strcmp(argv[1], "-l") || !strcmp(argv[1], "-a") || !strcmp(argv[1], "-al")) {
			strcpy(path, "./");
		}
	}
	else if (argc != 3) {
		printf("usage:ls -l pathname. \n");
		return 0;
	} else
		strcpy(path, argv[2]);

	struct stat file_message = {};
	int ret_stat = lstat(path, &file_message);
	if (ret_stat == -1)
		ErrorPrint("stat");

	if (!(strcmp(argv[1], "-l"))) {
		if (S_ISDIR(file_message.st_mode)){
			DirInfo(path, ls_l);
		}
		else {
			list_message(path, &file_message);
		}
	} else if (!(strcmp(argv[1], "-a"))) {
		FileName(path);
	} else if (!(strcmp(argv[1], "-al"))) {
		if (S_ISDIR(file_message.st_mode))
			DirInfo(path, ls_al);
		else
			list_message(path, &file_message);
	}
	return 0;
}


