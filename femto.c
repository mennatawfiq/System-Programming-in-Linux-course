#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char **agrv)
{

	char *buf;
	size_t szBuf = 0;

	while (1)
	{
		printf("Femto shell prompt > ");
		if (getline(&buf, &szBuf, stdin) == -1)
		{
			break;
		}

		if (strcmp(buf, "\n") == 0)
		{
			continue;
		}
		else if (strcmp(buf, "exit\n") == 0)
		{
			printf("Good Bye\n");
			exit(0);
		}
		else if (strncmp(buf, "echo", 4) == 0)
		{
			char *echo = buf + 5;
			printf("%s", echo);
		}
		else
		{
			printf("Invalid command\n");
		}
	}
	return 0;
}
