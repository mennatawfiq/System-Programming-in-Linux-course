#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

	int cnt = 100, chRead;
	char buf[cnt];

	for (int i = 1; i < argc; ++i)
	{
		int fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			printf("failed to open the file\n");
			exit(-1);
		}

		while ((chRead = read(fd, buf, cnt)) > 0)
		{
			if (write(1, buf, chRead) < 0)
			{
				printf("writing failed\n");
				exit(-3);
			}
		}
	}
	return 0;
}
