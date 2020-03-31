/*************************************************************************
    > File Name: exec.c
    > Author: 冲鸭！小星星
    > Mail: N0 Mail! 
    > Created Time: 2020年03月26日 星期四 18时13分23秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

int main(int argc, char **argv) {
	pid_t pid;
	char filename[512] = {0};

	if (argc < 2) {
		fprintf(stderr, "Usage: %s filename arg...\n", argv[0]);
		return 1;
	}

	strcpy(filename, argv[1]);

	char *sub;

	sub = strstr(filename, ".");
	strncpy(o_name, filename, sun - filename);
	strncpy();


}
