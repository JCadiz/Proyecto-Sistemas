#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[]){
    pid_t pid = fork(); 
    clock_t start_t, end_t, total_t;
    
    if (pid<0){
        printf("errno = %d\n", errno);
        perror("main");
    }
    else if (pid == 0){ 
        start_t = clock();
        execv(argv[1], &argv[1]);
        end_t = clock();
        total_t = (double)(start_t-end_t) / CLOCKS_PER_SEC;
        printf("El programa se ejecuto en %lu segundos\n", total_t);
        exit(0);
	}
    else {
        pid = wait(NULL);
    }

    return 0;
}
