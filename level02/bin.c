int	main()
{
	char	buf_username[112];
	char	password[48];
	char	buf_password[112];
	int 	len;
	int	num_read;
	FILE	*pass;

	pass = fopen("/home/users/level03/.pass", "r");
	if (pass == NULL) {
	     fwrite("ERROR: failed to open password file\n", 36, 1, stderr);
	     exit(1);
	}

	num_read = fread(password, 1, 41, pass);
	len = strcspn(password, "\n");
	password[len] = 0;

	if (num_read != 41) {
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		exit(1);
	}

	fclose(pass);

	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");

   	fgets(buf_username, 100, stdin);
	len = strcspn(buf_username, "\n");
	buf_username[len] = 0;

   	printf("--[ Password: ");

   	fgets(buf_password, 100, stdin);
   	len = strcspn(buf_password, "\n");
	buf_password[len] = 0;

	puts("************************************************");

	if (strncmp(password, buf_password, 41) == 0) {
	        printf("Greetings, %s!\n", buf_username);
	        system("/bin/sh");
	        return (0);
	}

   	printf(buf_username);
	puts(" does not have access!");
	exit(1);
}
