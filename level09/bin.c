void	secret_backdoor()
{
	char buf[128];

	fgets(buf, 128, stdin);
	system(buf);
}

void	set_msg(char *buf)
{
	char msg[1024];

	memset(msg, 0, 128);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(msg, 1024, stdin);
	strncpy(buf, msg, (size_t)buf[180]);
}

void	set_username(char *buf)
{
	int	i;
	char	username[140];

	memset(username, 0, 16);

	puts(">: Enter your username");
	print(">>: ");

	fgets(username, 128, stdin);

	i = 0;
	while (i <= 40 && username[i] != 0) {
		buf[i + 140] = username[i];
		i++;
	}

	printf(">: Welcome, %s", &buf[140])
}

void	handle_msg()
{
	char buf[192];

	buf[140] = 0;
	buf[148] = 0;
	buf[154] = 0;
	buf[160] = 0;
	buf[168] = 0;

	buf[180] = 140;

	set_username(buf);
	set_msg(buf);
	puts(">: Msg sent!");
}

int	main()
{
	puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
	handle_msg();
	return 0;
}
