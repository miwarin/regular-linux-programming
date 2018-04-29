#include <stdio.h>
#include <stdlib.h>

static void do_head(FILE* f, long nlines);

int main(int ac, char** av)
{
	long nlines;

	if(ac < 2)
	{
		fprintf(stderr, "usage: %s n [file file...]\n", av[0]);
		exit(1);
	}
	nlines = atol(av[1]);
	if(ac == 2)
	{
		do_head(stdin, atol(av[1]));
	}
	else
	{
		int i;
		for(i = 2; i < ac; i++)
		{
			FILE* f;
			if((f = fopen(av[i], "r")) == NULL)
			{
				perror(av[i]);
				exit(1);
			}
			do_head(f, nlines);
			fclose(f);
		}
	}
	exit(0);
}

static void do_head(FILE* f, long nlines)
{
	int c;
	if(nlines <= 0)
		return;
	
	while((c = getc(f)) != EOF)
	{
		if(putchar(c) < 0)
			exit(1);
		if(c == '\n')
		{
			nlines--;
			if(nlines == 0)
				return;
		}
	}
}



