#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define COUNT 1024

int main(int argc, char **argv)
{

	if (argc != 3)
	{
		printf("Usage: cp <file> <destination>");
		exit(-1);
	}

	int fd_read = open(argv[1], O_RDONLY);
	if (fd_read < 0)
	{
		printf("Failed to open the file for reading");
		exit(-2);
	}

	int fd_write = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_write == -1)
	{
		close(fd_read);
		printf("Failed to open the file for writing");
		exit(-3);
	}

	char buf[COUNT];
	int bytes_read;
	while ((bytes_read = read(fd_read, buf, COUNT)) > 0)
	{
		if (write(fd_write, buf, bytes_read) < 0)
		{
			close(fd_read);
			close(fd_write);
			printf("Failed to write to file");
			exit(-4);
		}
	}

	close(fd_read);
	close(fd_write);
	return 0;
}
