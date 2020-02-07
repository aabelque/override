void	auth(char *login, unsigned int pass)
{
	unsigned int	v;
	unsigned int	i;

	login[strcspn(login, "\n")] = 0;

	if (strnlen(login, 32) <= 5) {
		return 1;
	}

	if (ptrace(0, 0, 1, 0) == 0xffffffff) {
		puts("\033[32m.---------------------------.");
		puts("\033[31m| !! TAMPERING DETECTED !!  |");
		puts("\033[32m'---------------------------'");
		return 1;
	}


	v = (login[2] ^ 0x1337) + 6221293;
	i = 0;

	while (i < v) {
		if (login[i] <= 31) {
			return 1;
		}

		ecx = login[i] ^ v;
		eax = (2284010283 * login[i]) ^ v - (((((ecx - edx) >> 1) + edx) >> 10) * 1337);

		v += eax;
		i++;
	}

	if (pass != v) {
		return 1;
	}

	return 0;
}

int	main()
{
	char		buf[32];
	unsigned int	pass;

	puts("***********************************");
	puts("*               level06           *");
	puts("***********************************");
	printf("-> Enter Login: ");

	fgets(buf, 32, stdin);

	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");

	scanf("%u", &pass);

	if (auth(buf, pass) != 0) {
		return 1;
	}

	puts("Authenticated!");
	system("/bin/sh");
	return 0;
}
