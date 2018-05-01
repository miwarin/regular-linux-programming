#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef void (*signalhandler_t)(int);

static signalhandler_t trap_signal(int sig, signalhandler_t handler)
{
	struct sigaction act, old;

	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	if(sigaction(sig, &act, &old) < 0)
	{
		perror("sigaction");
		return NULL;
	}

	return old.sa_handler;
}

static void signal_handler(int sig)
{
	printf("%s %d\n", __func__, sig);
}

int main(int ac, char** av)
{
	trap_signal(SIGINT, signal_handler);
	pause();
	exit(0);
}
