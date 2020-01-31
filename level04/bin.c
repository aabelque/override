#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
	int	status;
	char	buf[128];
	int	z;
	int	w;
	long	ptrace_ret;
	pid_t	child;

	child = fork();
	status = 0;
	ptrace_ret = 0;
	memset(buf, 0, 32);

	if (child == 0) {
		prctl(1, 1);
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(buf);
		return 0;
	}

	while (ptrace_ret != 11) {
		wait(&status);

		z = status & 0x7f;
		w = ((status & 0x7f) + 1) >> 1;

		if (z == 0 || w > 0) {
			puts("child is exiting...");
			return 0;
		}

		ptrace_ret = ptrace(PTRACE_PEEKUSER, child, 44, 0);
	}

	puts("no exec() for you");
	kill(child, 9);
	return 0;
}
