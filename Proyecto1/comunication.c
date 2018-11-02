#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>


int ring=0;
void wakeUp(int s){
    ring++;
    alarm(2);
}

int main(int argc, char *argv[]){
    char buffer[125];
    pid_t c1, c2;
    int count;
    struct sigaction sigact;
    sigset_t sigset;

    sigemptyset(&sigset);
    sigact.sa_handler = wakeUp;
    sigact.sa_mask = sigset;
    sigact.sa_flags = 0;
    sigaction(SIGALRM, &sigact, NULL);

    int fileDes[2];
    pipe(fileDes);

    c1=fork();

    if (c1 == 0) {
        /* Estamos dentro del primer hijo */
        int rong=0;
        close(fileDes[0]);
        alarm(2);
        while (1){
            if (ring>=10) break;
            if (rong<ring){
                rong++;
                if (write(fileDes[1], "C2: Recibido el mensaje de c1", 30) < 0){
			        fprintf(stderr, "No se puede escribir el pipe\n");
		        }
            }
        }
        close(fileDes[1]);
    } 
    else {
        c2=fork();

        if (c2 == 0) {
            /* Estamos dentro del segundo hijo */
            close(fileDes[1]);
            while(1){
                if (ring>=10) break;
                else {
                    ring++;
                    if ((count = read(fileDes[0], buffer, 100) < 0)){
                        fprintf(stderr, "No se puede leer del pipe\n");
                        exit(1);
                    }
                    printf("%s\n", buffer);
                }
            }
            close(fileDes[0]);
            exit(0);
        } 
        else {
            /* Estamos dentro del padre */
            close(fileDes[0]);
            close(fileDes[1]);
            c1 = wait(NULL);
            c2 = wait(NULL);
            printf("PADRE: Fin del padre\n");
        }
    }

    return 0;
}