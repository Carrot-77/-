/*************************************************************************
    > File Name: cp.c
    > Author: 冲鸭！小星星
    > Mail: N0 Mail! 
    > Created Time: 2020年03月22日 星期日 14时34分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 512
int main(int argc, char **argv) {
	int fd_in, fd_out;
	ssize_t nread = {0};
	char buf[BUFSIZE + 5];
	if (argc != 3) {
		printf("Usage: %s sourcefile destfile\n", argv[0]);
		exit(1);
	}

	if ((fd_in = open(argv[1],O_RDONLY)) == -1) {
		perror(argv[1]);
		exit(1);
	}

	if ((fd_out = creat(argv[2], 0644)) == -1) {
		perror(argv[2]);
		exit(1);
	}

	while ((nread = read(fd_in, buf, sizeof(buf))) > 0) {
		int nwrite;
		if ((nwrite = write(fd_out, buf, strlen(buf))) != nread) {
			perror("write");
			exit(1);
		}
		memset(buf, 0, BUFSIZE + 5);
	}
	close(fd_in);
	close(fd_out);
	return 0;
}
