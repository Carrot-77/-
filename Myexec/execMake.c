/*************************************************************************
    > File Name: execMake.c
    > Author: 冲鸭！小星星
    > Mail: N0 Mail! 
    > Created Time: 2020年03月24日 星期二 20时24分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void do_touch(char *buf) {
	int pid = fork();
	if (pid < 0) {
		perror("fork");
	} else if (!pid) {
		char *order[] = {"touch", buf, NULL};
		execv("/bin/touch", order);
	} else {
		wait(NULL);
		printf("%s was built!\n");
	}
}

void do_vim(char *buf) {
	int pid = fork();
	if (pid < 0) {
		perror("fork");
	} else if (!pid) {
		char *order[] = {"Vim", buf, NULL};
		if (execv("/usr/bin/vim", order) < 0) 
			perror("vim");
	} else {
		wait(NULL);
		printf("Edit!\n");
	}
	return;
}

void do_gcc(char *buf) {
	int len = strlen(buf);
	int pid = fork();
	if (pid < 0) {
		perror("fork");
	} else if (!pid){
		if (buf[len - 1] == 'c') {
			char *order[] = {"gcc", buf, (char*)0};
			if (execv("/bin/gcc", order) < 0) {
				perror("gcc");
				return;
			}
		} else {
			char *order[] = {"g++", buf, (char*)0};
			if (execv("/bin/g++", order) < 0) {
				perror("g++");
				return;
			}
		}
	} else {
		printf("Compile complete!\n");
		wait(NULL);
	}
	return;
}

int main(int argc, char **argv, char **environ) {
	if (argc != 2) {
		printf("Type error: format should be [out] [file]\n");
		return 0;
	}
	int pid = fork();
	int status = 0;
	if (pid < 0) perror("fork");
	else if (!pid) {
		if (access(*++argv, F_OK) == -1) {
			printf("Build %s :\n", *argv);
			do_touch(*argv);
		}
		do_vim(*argv);
		do_gcc(*argv);
		int pidout = fork();
		if (pidout < 0) {
			perror("fork");
		} else if (!pidout) {
			execve("a.out", argv, environ);
		} else {
			printf("Executed output!\n");
			wait(NULL);
		}
	} else {
		wait(&status);
		printf("Program over!\n");
	}
	return 0;
}
