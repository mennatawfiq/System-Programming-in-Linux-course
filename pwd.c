#include <unistd.h>
#include <unistd.h>
#include <string.h>
#include <linux/limits.h>

const char buf[] = "Usage: pwd\n";

int main(int argc, char **argv[])
{
	if (argc > 1)
		write(1, buf, strlen(buf));

	char cwd[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	write(1, cwd, strlen(cwd));

	return 0;
}
