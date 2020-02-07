void	log_wrapper(FILE *stream, const char *toprint, char *str)
{
	char buf[264];

	strcpy(buf, toprint);
	snprintf(&buf[strlen(buf) - 1], 255 - strlen(buf) - 1, str);
	buf[strcspn(buf, "\n")] = 0;
	fprintf(stream, "LOG: %s\n", buf);
}

int	main(int ac, char **av)
{
	char	backup[100];
	int	c;
	FILE	*argfile;
	FILE	*logfile;
	int	fd;

	c = 255;

	if (ac != 2)
		printf("Usage: %s filename\n", *av);

	logfile = fopen("./backups/.log", "w");

	if (logfile == NULL) {
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}

	log_wrapper(logfile, "Starting back up: ", av[1]);

	argfile = fopen(av[1], "r");

	if (argfile == NULL) {
		printf("ERROR: Failed to open %s\n", av[1]);
		exit(1);
	}

	backup = "./backups";
	strncat(backup, av[1], 99 - strlen(backup));

	fd = open(backup, 0301, 0660);

	if (fd != 0) {
		printf("ERROR: Failed to open %s%s\n", "./backups/", av[1]);
		exit(1);
	}

	do {
		write(fd, c, 1);
		c = fgetc(argfile)
	} while (c != 255);

	log_wrapper(logfile, "Finished back up ", av[1]);

	fclose(argfile);
	close(fd);

	return 0;
}
