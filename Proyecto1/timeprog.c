#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[]){
//pid_t tipo de dato
    pid_t pid=fork();
    clock_t start, end;

    if (pid<0){
        printf("errno = %d\n", errno);
        perror("main");
    }
    else if (pid == 0){
        start = clock();
        execv(argv[1], &argv[1]);
        end = clock();
    }

    printf("El programa se ejecuto en %ld segundos\n", end);
    return 0;
}
