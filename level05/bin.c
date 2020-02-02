#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main()
{
	char	buf[100];
	int	i;

	fgets(buf, 100, stdin);
	i = 0;

	while (i < strlen(buf)) {
		if (64 < buf[i] && buf[i] <= 90) {
			buf[i] += 32;
		}
		i++;
	}

	printf(buf);
	exit(0);
}
