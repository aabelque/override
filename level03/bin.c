#include <string.h>
#include <stdio.h>

void	decrypt(int x)
{
	char	str[16] = "Q}|u`sfg~sf{}|a3";
	int	i;
	int	len;

	i = 0;
	len = strlen(str);
	while (i < len) {
		str[i] = x ^ str[i];
		i++;
	}

	if (!memcmp("Congratulations!", str, 17)) {
		system("/bin/sh");
	} else {
		puts("\nInvalid Password");
	}

	return;
}

void	test(int a, int b)
{
	int x;

	x = b - a;
	if (x <= 21) {
		switch (x) {
			case 1:
				decrypt(x);
				return;
			case 2:
				decrypt(x);
				return;
			case 3:
				decrypt(x);
				return;
			case 4:
				decrypt(x);
				return;
			case 5:
				decrypt(x);
				return;
			case 6:
				decrypt(x);
				return;
			case 7:
				decrypt(x);
				return;
			case 8:
				decrypt(x);
				return;
			case 9:
				decrypt(x);
				return;
			case 16:
				decrypt(x);
				return;
			case 17:
				decrypt(x);
				return;
			case 18:
				decrypt(x);
				return;
			case 19:
				decrypt(x);
				return;
			case 20:
				decrypt(x);
				return;
			case 21:
				decrypt(x);
				return;
			default:
				break;
		}
	}

	decrypt(rand());
	return;
}

int	main()
{
	int	x;

	srand(time(0));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");

	scanf("%d", &x);
	test(x, 322424845);
}
