#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char** av)
{
	if(ac != 3)
	{
		fprintf(stderr, "%s: wrong arguments\n", av[0]);
		exit(1);
	}

	if(symlink(av[1], av[2]) < 0)
	{
		perror(av[1]);
		exit(1);
	}
	exit(0);
}
