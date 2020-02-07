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
	unsigned int	zone[100];
	char		command[20];
	int		ret;

 	puts("----------------------------------------------------\n  Welcome to wil's crappy number storage service!   \n----------------------------------------------------\n Commands:                               \n    store - store a number into the data storage\n    read  - read a number from the data storage\n    quit  - exit the program\n----------------------------------------------------\n   wil has reserved some storage :>\n----------------------------------------------------\n");

   while (true) {
	   printf("Input command: ");

	   ret = 1;

	   fgets(command, 20, stdin);

	   if (memcmp(command, "store", 5) == 0) {

		   ret = store_number(&zone);

	   } else if (memcmp(command, "read", 4) == 0) {

		   ret = read_number(&zone);

	   } else if (memcmp(command, "quit", 4) == 0) {
		   break;
	   }

	   if (ret == 0) {
		   printf(" Completed %s command successfully\n", command);
	   } else {
		   printf(" Failed to do %s command\n", command);
	   }

	   bzero(command, 20);
   }

   return 0;
}
