#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

void sighandler(int signo) {
   printf("Recibido...\n");
   exit(1);
}

int main(int argc, char *argv[]){
    pid_t c1, c2;
    char buffer[100];
    pipe(fileDes);
    c1=fork();

    if (c1 == 0) {
        /* Estamos dentro del primer hijo */
    } 
    else {
        c2=fork();

        if (c2 == 0) {
            /* Estamos dentro del segundo hijo */
        } 
        else {
            /* Estamos dentro del padre */
        }
    }

    return 0;
}