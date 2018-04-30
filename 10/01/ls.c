#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

static void do_ls(char* path);

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
		do_ls(av[i]);
	}
	exit(0);
}

static void do_ls(char* path)
{
	DIR* d;
	struct dirent* ent;
	if((d = opendir(path)) == NULL)
	{
		perror(path);
		exit(1);
	}

	while(ent = readdir(d))
	{
		puts(ent->d_name);
	}
	closedir(d);
}
