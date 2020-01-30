int	main()
{
   0x0000000000400814 <+0>:     push   rbp
   0x0000000000400815 <+1>:     mov    rbp,rsp
   0x0000000000400818 <+4>:     sub    rsp,0x120
   0x000000000040081f <+11>:    mov    DWORD PTR [rbp-0x114],edi
   0x0000000000400825 <+17>:    mov    QWORD PTR [rbp-0x120],rsi

   0x000000000040082c <+24>:    lea    rdx,[rbp-0x70]
   0x0000000000400830 <+28>:    mov    eax,0x0
   0x0000000000400835 <+33>:    mov    ecx,0xc
   0x000000000040083a <+38>:    mov    rdi,rdx
   0x000000000040083d <+41>:    rep stos QWORD PTR es:[rdi],rax
   0x0000000000400840 <+44>:    mov    rdx,rdi
   0x0000000000400843 <+47>:    mov    DWORD PTR [rdx],eax
   0x0000000000400845 <+49>:    add    rdx,0x4
   0x0000000000400849 <+53>:    lea    rdx,[rbp-0xa0]
   0x0000000000400850 <+60>:    mov    eax,0x0
   0x0000000000400855 <+65>:    mov    ecx,0x5
   0x000000000040085a <+70>:    mov    rdi,rdx
   0x000000000040085d <+73>:    rep stos QWORD PTR es:[rdi],rax
   0x0000000000400860 <+76>:    mov    rdx,rdi
   0x0000000000400863 <+79>:    mov    BYTE PTR [rdx],al
   0x0000000000400865 <+81>:    add    rdx,0x1
   0x0000000000400869 <+85>:    lea    rdx,[rbp-0x110]
   0x0000000000400870 <+92>:    mov    eax,0x0
   0x0000000000400875 <+97>:    mov    ecx,0xc
   0x000000000040087a <+102>:   mov    rdi,rdx
   0x000000000040087d <+105>:   rep stos QWORD PTR es:[rdi],rax
   0x0000000000400880 <+108>:   mov    rdx,rdi
   0x0000000000400883 <+111>:   mov    DWORD PTR [rdx],eax
   0x0000000000400885 <+113>:   add    rdx,0x4
   0x0000000000400889 <+117>:   mov    QWORD PTR [rbp-0x8],0x0
   0x0000000000400891 <+125>:   mov    DWORD PTR [rbp-0xc],0x0

	char	buf_username[];
	char	buf_password[];
	char	password[];
	int 	len;

	FILE* pass = fopen("/home/users/level03/.pass", "r");
	if (pass == NULL) {
	     fwrite("ERROR: failed to open password file\n", 36, 1, stderr);
	     exit(1);
	}

	int num_read = fread(password, 1, 41, pass);
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

	if (strncmp(rbp-0xa0, buf_password, 41) == 0) {
	        printf("Greetings, %s!\n", buf_username);
	        system("/bin/sh");
	        return (0);
	}

   	printf(buf_username);
	puts(" does not have access!");
	exit(1);
}
