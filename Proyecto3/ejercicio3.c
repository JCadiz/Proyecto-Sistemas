#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/times.h>

bool entrada= 0;

void detener(int s){
  entrada = 1;
}

void tiempo(int time)
{
    struct sigaction sigact;
    sigset_t sigset;
    /* registrar el manejador para SIGALRM, pero obtener la señal del padre */
    sigemptyset( &sigset ); /* crear un conjunto vacio de mascaras de señales */
    sigact.sa_handler = detener; /* utilizar el manejador wakeup */
    sigact.sa_mask = sigset; /* utilizar el sigset vacio */
    sigact.sa_flags = 0; /* no es necesario banderas */
    sigaction( SIGALRM, &sigact, NULL );


    /*cronometro para la alarma */
    alarm( time );
}


int main(int argc, char *argv[]){
    int procesos = atoi(argv[1]); //cantidad de procesos a realizar 
    int eliminar = atoi(argv[2]); //cantidad de procesos a eliminar 
    int memoria = atoi(argv[3]); // espacio de memoria a definir para cada proceso
    int duracion = atoi(argv[4]); // tiempo de ejecucion

    int pid, i =0 ;
    int n[ eliminar ]; // aqui almaceno los id de los procesos creados

    struct sigaction sigact;
    sigset_t sigset;
    /* registrar el manejador para SIGALRM, pero obtener la señal del padre */
    sigemptyset( &sigset ); /* crear un conjunto vacio de mascaras de señales */
    sigact.sa_handler = detener; /* utilizar el manejador wakeup */
    sigact.sa_mask = sigset; /* utilizar el sigset vacio */
    sigact.sa_flags = 0; /* no es necesario banderas */
    sigaction( SIGINT, &sigact, NULL );


     printf("Procesos creados: %d \n", procesos);
     printf("Procesos eliminados: %d \n", eliminar);
     printf("Memoria definida: %d \n", memoria);

    pid_t id;
	
	 while (procesos > 0){ //creo los procesos del usuario1

		id = fork();
		if (id < 0){
			printf("errno = %d\n", errno);
			perror("main");
		}else if ( id == 0 ){
			pid = getpid ();
			n[i]=pid;
			i++;
			tiempo(duracion);
			printf("se creo un proceso: \n");
			
			while(!entrada){}

			exit (0);
		}else{
			procesos--;	
		}
    	 }

	 for (int j=0; j < eliminar; j++ ){
		kill(n[j], SIGKILL );
		printf("se elimino un proceso: %d \n",n[j]);
	 }

    return 0;
}
