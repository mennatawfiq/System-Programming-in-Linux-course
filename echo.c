#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    
    int i = 2;
    
    if(strcmp(argv[1], "-n")){
        i = 1;
    }
    
    for(; i < argc; ++i){
        if(write(1, argv[i], strlen(argv[i])) < 0){
            printf("Error while writing on stdout");
            exit(-1);
        }
	if(i != argc-1 && write(1, " " , 1) < 0){
	    printf("Error while writing on stdout");
	    exit(-2);
	}
    }

    printf("\n");
    
    return 0;
}
