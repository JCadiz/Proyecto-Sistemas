#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[]){
    clock_t start, end, total;
    start = clock();

    pid_t pid = fork(); 
    if (pid<0){ //error
        printf("errno = %d\n", errno);
        perror("main");
    }
    else if (pid == 0){ //hijo
        execv(argv[1], &argv[1]);
        exit(1);
	}
    else { //padre
        pid = wait(NULL);
        end = clock();
        total = (double)(start-end) / CLOCKS_PER_SEC;
    }
    printf("El programa se ejecuto en %lu segundos\n", total);
    return 0;
}
