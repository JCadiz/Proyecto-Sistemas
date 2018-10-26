#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[]){
    time_t start, end, total;
    start = time(NULL);

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
    }
    end = time(NULL);
    total = (double)(end-start);
    printf("El programa se ejecuto en %lld segundos\n", total);
    return 0;
}
