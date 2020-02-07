char 	*a_user_name = "";

int	verify_user_name()
{
	puts("verifying username....\n");
	return memcmp(a_user_name, "dat_wil", 7);
}

int	verify_user_pass(char *pass)
{
	return memcmp(pass, "admin", 5);
}

int	main()
{
	// to overflow:
	// buf + 64 + is_user_valid + edi + ebx + ebp = 80
	// so to override eip, we must write 4 bytes after the 80 bytes 
	// after the start of the buffer
	char buf[64];
	int is_user_valid;

	memset(buf, 0, 16);
	is_user_valid = 0;

	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin);

	if (verify_user_name() != 0) {
		puts("nope, incorrect username...\n");
		return 1;
	}

	puts("Enter Password: ");

	fgets(buf, 100, stdin);

	is_user_valid = verify_user_pass(buf);

	if (is_user_valid == 0) {
		return 0;
	}
	puts("nope, incorrect password...\n");
	return 1;

} 
