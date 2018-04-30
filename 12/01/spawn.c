#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char** av)
{
	pid_t pid;
	if(ac != 3)
	{
		fprintf(stderr, "usage: %s <command> <arg>\n", av[0]);
		exit(1);
	}

	pid = fork();
	if(pid < 0)
	{
		fprintf(stderr, "fork(2) failed\n");
		exit(1);
	}

	/* 子プロセス */
	if(pid == 0)
	{
		execl(av[1], av[1], av[2], NULL);
		perror(av[1]);
		exit(99);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		printf("child (pid=%d) finished", pid);
		if(WIFEXITED(status))
		{
			printf("exit status=%d\n", WEXITSTATUS(status));
		}
		else if(WIFSIGNALED(status))
		{
			printf("signal sig=%d\n", WTERMSIG(status));
		}
		else
		{
			printf("abnormal exit\n");
		}
		exit(0);
	}
}
