#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[]){
//pid_t tipo de dato para el fork
    pid_t pid = fork();
    clock_t start, end;
    double seg;

    if (pid<0){
        printf("errno = %d\n", errno);
        perror("main");
    }
    else if (pid == 0){ 
        start = clock();
        execv(argv[1], &argv[1]);
        end = clock();
	}
	 seg = (double)(start - end) / CLOCKS_PER_SEC;  // ld
    	printf("El programa se ejecuto en %f segundos\n", seg);
	exit(0);
    // }
	
    return 0;
}
