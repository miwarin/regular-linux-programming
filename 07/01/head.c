#include <stdio.h>
#include <stdlib.h>

#define _GNU_SOURCE
#include <getopt.h>

#define DEFAULT_N_LINES 10

static void do_head(FILE* f, long nlines);

static struct option longopts[] =
{
	{"lines", required_argument, NULL, 'n'},
	{"help",  no_argument,       NULL, 'h'},
	{0, 0, 0, 0},
};


int main(int ac, char** av)
{
	int opt;
	long nlines = DEFAULT_N_LINES;

	while((opt = getopt_long(ac, av, "n:", longopts, NULL)) != -1)
	{
		switch(opt)
		{
			case 'n':
				nlines = atol(optarg);
				break;
			case 'h':
				fprintf(stdout, "usage: %s n [file file...]\n", av[0]);
				exit(1);
				break;
			case '?':
				fprintf(stderr, "usage: %s n [file file...]\n", av[0]);
				exit(1);
				break;
		}
	}

	if(optind == ac)
	{
		do_head(stdin, nlines);
	}
	else
	{
		int i;
		for(i = optind; i < ac; i++)
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



