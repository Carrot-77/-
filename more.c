/*************************************************************************
    > File Name: more.c
    > Author: 冲鸭！小星星
    > Mail: N0 Mail! 
    > Created Time: 2020年03月21日 星期六 19时29分05秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>
#define LENLINE 512
int Row;

void do_more(FILE *fp);

int main(int argc, char **argv) {
	FILE *fp;
	struct winsize size;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	Row = size.ws_row;
	if (argc == 1) 
		do_more(stdin);
	else 
		while (--argc) {
			if ((fp = fopen(*++argv, "r")) != NULL) {
				do_more(fp);
			}
		}
	return 0;
}

void do_more(FILE *fp) {
	char line[LENLINE] = {0};
	FILE *cmd = fopen("/dev/tty", "r");
	int num_line = 0, reply, get_cmd(FILE *);
	while (fgets(line, LENLINE, fp)) {
		if (num_line == Row) {
			reply = get_cmd(cmd);
			if (reply == 0) break;
			num_line -= reply;
		}

		if (fputs(line, stdout) == EOF) {
			perror("fputs");
			exit(1);
		}
		num_line++;
	}
}

int get_cmd(FILE *fp) {
	printf("more:");
	int c;
	while ((c = fgetc(fp)) != EOF) {
		if (c == 'q') return 0;
		if (c == ' ') return Row;
		if (c == '\n') return 1;
	}
	return -1;
}
