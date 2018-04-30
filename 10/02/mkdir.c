#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int ac, char** av)
{
	int i;

	if(ac < 2)
	{
		fprintf(stderr, "%s: no arguments\n", av[0]);
		exit(1);
	}

	for(i = 1; i < ac; i++)
	{
		if(mkdir(av[i], 0777) < 0)
		{
			perror(av[i]);
			exit(1);
		}
	}
	exit(0);
}
