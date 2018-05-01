#include <stdio.h>
#include <stdlib.h>

extern char** environ;

int main(int ac, char** av)
{
	char** p;

	for(p = environ; *p; p++)
	{
		puts(*p);
	}
	exit(0);
}
