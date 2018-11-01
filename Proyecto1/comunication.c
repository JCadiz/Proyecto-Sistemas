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


int count=0;
void wakeup(int s){
    static int rings = 0;
    if (++rings > 10) exit(0);
    printf( "C1: Recibida la señal, enviando mensaje a c2...\n" );
    count++;
    alarm(2);
}

int main(int argc, char *argv[]){
    char buffer[125];
    struct sigaction sigact;
    pid_t c1, c2;
    sigset_t sigset;

    sigemptyset(&sigset);
    sigact.sa_handler = wakeup;
    sigact.sa_mask = sigset;
    sigact.sa_flags = 0;
    sigaction(SIGALRM, &sigact, NULL);

    int fileDes[2];
    pipe(fileDes);

    c1=fork();

    if (c1 == 0) {
        /* Estamos dentro del primer hijo */
        
        close(fileDes[0]);
        if ( write( fileDes[ 1 ], "C2: Recibido el mensaje de c1...", 30 ) < 0 ){
			fprintf( stderr, "No se puede escribir el pipe\n" );
		}
        close(fileDes[1]);
        alarm(2);
        while(1){
        }
    } 
    else {
        c2=fork();

        if (c2 == 0) {
            /* Estamos dentro del segundo hijo */
            close(0);
            dup( fileDes[ 0 ] );
            close( fileDes[ 1 ] );

            if ( ( count = read( fileDes[ 0 ], buffer, 100 ) < 0 ) ){
                fprintf( stderr, "No se puede leer del pipe\n" );
                exit( 1 );
		    }
            for (int i = 0; i < count; i++){
                printf("buff[] = %s\n", buffer);
            }
            exit( 0 );
        } 
        else {
            /* Estamos dentro del padre */
            c1 = wait(NULL);
            c2 = wait(NULL);
            close(fileDes[0]);
            close(fileDes[1]);
            printf("PADRE: Fin del padre\n");
        }
    }

    return 0;
}