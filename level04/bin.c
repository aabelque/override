int	main()
{
	int	stat_loc;
	char	buf[128];
	int	z;
	int	w;
	long	ptrace_ret;
	pid_t	child;

	child = fork();
	x = 0;
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
		wait(&x);

		z = x & 0x7f;
		w = ((x & 0x7f) + 1) >> 1;

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
