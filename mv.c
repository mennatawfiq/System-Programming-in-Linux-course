#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

const int COUNT = 1024;

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: mv <old> <new>\n");
		exit(-1);
	}

	int f1 = open(argv[1], O_RDONLY);
	if (f1 == -1)
	{
		printf("Failed to open the source file\n");
		exit(-2);
	}

	int f2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (f2 == -1)
	{
		close(f1);
		printf("Failed to open the destination file\n");
		exit(-2);
	}

	char buf[COUNT];
	int bytes_read;
	while ((bytes_read = read(f1, buf, COUNT)) > 0)
	{
		if (write(f2, buf, bytes_read) < 0)
		{
			close(f1);
			close(f2);
			printf("Failed to write to file\n");
			exit(-3);
		}
	}

	close(f2);

	int f3 = unlink(argv[1]);

	if (f3 < 0)
	{
		printf("failed to remove %s\n", argv[1]);
		exit(-4);
	}

	return 0;
}
