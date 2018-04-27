#include <stdio.h>
#include <stdlib.h>

int main(int ac, char** av)
{
	int i;
	for(i = 1; i < ac; i++)
	{
		FILE* f;
		int c;
		if((f = fopen(av[i], "r")) == NULL)
		{
			perror(av[i]);
			exit(1);
		}
		while((c = fgetc(f)) != EOF)
		{
			if(putchar(c) < 0) exit(1);
		}
		fclose(f);
	}
	exit(0);
}


