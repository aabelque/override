int	main()
{
	int	x;
	char	buf[128];
	int	z;
	int	w;
	int	y;
	pid_t	child;

	child = fork();
	x = 0;
	y = 0;
	memset(buf, 0, 32);

	if (child == 0) {
		prctl(1, 1);
		ptrace(0, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(buf);
		return 0;
	}

	while (y != 11) {
		wait(x);

		z = x;
		z &= 0x7f;
		w = x;
		w &= 0x7f;
		w += 1;
		w = w >> 1;

		if (z == 0 || w > 0) {
			puts("child is exiting...");
			return 0;
		}

		y = ptrace(3, child, 44, 0);
	}

	puts("no exec() for you");
	kill(child, 9);
	return 0;
}
