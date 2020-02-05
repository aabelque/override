void		clear_stdin()
{
	char w;

	w = 0;
	while (w != 255)
	{
		w = getchar();
		if (w == 10)
			break;
	}

	return;
}

unsigned int	get_unum()
{
	unsigned int	v;

	v = 0;
	fflush(stdout);
	scanf("%u", &v);
	clear_stdin();

	return v;
}

int	store_number(unsigned int *zone)
{
	unsigned int number;
	unsigned int index;

	number = 0;
	index = 0;

	printf(" Number: ");
	number = get_unum();

	printf(" Index: ");
	index = get_unum();

	if (index - ((index * 0xaaaaaaab) >> 1) * 3 == 0 || number >> 0x18 == 183) {
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return 1;
	}

	index *= 4;
	zone[index] = number;

	return 0;
}

int	read_number(unsigned int *zone)
{
   unsigned int	index;

   index = 0;

   printf(" Index: ");
   index = get_unum();
   printf(" Number at data[%u] is %u\n", index, *(zone + (index << 2)));

   return 0;
}

int	main()
{
   <+0>:     push   ebp
   <+1>:     mov    ebp,esp
   <+3>:     push   edi
   <+4>:     push   esi
   <+5>:     push   ebx
   <+6>:     and    esp,0xfffffff0
   <+9>:     sub    esp,0x1d0
   <+15>:    mov    eax,DWORD PTR [ebp+0xc]
   <+18>:    mov    DWORD PTR [esp+0x1c],eax
   <+22>:    mov    eax,DWORD PTR [ebp+0x10]
   <+25>:    mov    DWORD PTR [esp+0x18],eax
   <+29>:    mov    eax,gs:0x14
   <+35>:    mov    DWORD PTR [esp+0x1cc],eax
   <+42>:    xor    eax,eax
   <+44>:    mov    DWORD PTR [esp+0x1b4],0x0
   <+55>:    mov    DWORD PTR [esp+0x1b8],0x0
   <+66>:    mov    DWORD PTR [esp+0x1bc],0x0
   <+77>:    mov    DWORD PTR [esp+0x1c0],0x0
   <+88>:    mov    DWORD PTR [esp+0x1c4],0x0
   <+99>:    mov    DWORD PTR [esp+0x1c8],0x0

   <+110>:   lea    ebx,[esp+0x24] // unsigned int zone[100]; // can store 400 bytes
   <+114>:   mov    eax,0x0
   <+119>:   mov    edx,0x64
   <+124>:   mov    edi,ebx
   <+126>:   mov    ecx,edx
   <+128>:   rep stos DWORD PTR es:[edi],eax
   <+130>:   jmp    0x80487ea <main+199>

   <+132>:   mov    eax,DWORD PTR [esp+0x1c]
   <+136>:   mov    eax,DWORD PTR [eax]
   <+138>:   mov    DWORD PTR [esp+0x14],0xffffffff
   <+146>:   mov    edx,eax
   <+148>:   mov    eax,0x0
   <+153>:   mov    ecx,DWORD PTR [esp+0x14]
   <+157>:   mov    edi,edx
   <+159>:   repnz scas al,BYTE PTR es:[edi]
   <+161>:   mov    eax,ecx
   <+163>:   not    eax
   <+165>:   lea    edx,[eax-0x1]
   <+168>:   mov    eax,DWORD PTR [esp+0x1c]
   <+172>:   mov    eax,DWORD PTR [eax]
   <+174>:   mov    DWORD PTR [esp+0x8],edx
   <+178>:   mov    DWORD PTR [esp+0x4],0x0
   <+186>:   mov    DWORD PTR [esp],eax
   <+189>:   call   0x80484f0 <memset@plt>

   esp+0x1c += 4;

   <+199>:   mov    eax,DWORD PTR [esp+0x1c]
   <+203>:   mov    eax,DWORD PTR [eax]
   <+205>:   test   eax,eax
   <+207>:   jne    0x80487a7 <main+132>

   <+209>:   jmp    0x8048839 <main+278>

   <+211>:   mov    eax,DWORD PTR [esp+0x18]
   <+215>:   mov    eax,DWORD PTR [eax]
   <+217>:   mov    DWORD PTR [esp+0x14],0xffffffff
   <+225>:   mov    edx,eax
   <+227>:   mov    eax,0x0
   <+232>:   mov    ecx,DWORD PTR [esp+0x14]
   <+236>:   mov    edi,edx
   <+238>:   repnz scas al,BYTE PTR es:[edi]
   <+240>:   mov    eax,ecx
   <+242>:   not    eax
   <+244>:   lea    edx,[eax-0x1]
   <+247>:   mov    eax,DWORD PTR [esp+0x18]
   <+251>:   mov    eax,DWORD PTR [eax]
   <+253>:   mov    DWORD PTR [esp+0x8],edx
   <+257>:   mov    DWORD PTR [esp+0x4],0x0
   <+265>:   mov    DWORD PTR [esp],eax
   <+268>:   call   0x80484f0 <memset@plt>

   <+273>:   add    DWORD PTR [esp+0x18],0x4
   <+278>:   mov    eax,DWORD PTR [esp+0x18]
   <+282>:   mov    eax,DWORD PTR [eax]
   <+284>:   test   eax,eax
   <+286>:   jne    0x80487f6 <main+211>

 	puts("----------------------------------------------------\n  Welcome to wil's crappy number storage service!   \n----------------------------------------------------\n Commands:                               \n    store - store a number into the data storage\n    read  - read a number from the data storage\n    quit  - exit the program\n----------------------------------------------------\n   wil has reserved some storage :>\n----------------------------------------------------\n");

   while (true) {
	   printf("Input command: ");

	   esp+0x1b4 = 1;

	   fgets(0x1b8, 20, stdin);

	   if (memcmp(0x1b8, "store", 5) == 0) {

		   esp+0x1b4 = store_number(&zone);

	   } else if (memcmp(0x1b8, "read", 4) == 0) {

		   esp+0x1b4 = read_number(&zone);

	   } else if (memcmp(0x1b8, "quit", 4) == 0) {
		   return 0;
	   }

	   if (esp+0x1b4 == 0) {
		   printf(" Completed %s command successfully\n", esp+0x1b8);
	   } else {
		   printf(" Failed to do %s command\n", esp+0x1b8);
	   }

	   bzero(0x1b8, 20);
   }

   return 0;
}
