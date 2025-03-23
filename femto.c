#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char** agrv) {

	char *buf;
	size_t szBuf = 0;

	while(1){
		printf("Femto shell prompt > ");
		if(getline(&buf, &szBuf, stdin) == -1){
			break;
		}
		if(strcmp(buf, "exit\n") == 0){
			printf("Good Bye\n");
			exit(0);
		} else if (strncmp(buf, "echo", 4) == 0) {
			char *echo = buf + 5;
			if (write(1, echo, strlen(echo)) < 0)
        		{	
            			printf("Error while writing to stdout");
           			exit(-1);
        		}
		}
	
	}
	return 0;
}
