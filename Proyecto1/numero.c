#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>

void wakeup( int ); /* declaración */
long count=0;
bool cierre=true;

int main( int argc, char **argv)
{
	pid_t id;
	int i=1;
	bool entrada= true;
	long p1;

	struct sigaction sigact;
    	sigset_t sigset;
    
	/* montar el manejador para le interrupcion del teclado (DEL o CTRL-C) */
	sigemptyset( &sigset ); /* conjunto vacio de mascaras de señales */
	sigact.sa_handler = wakeup; /* registra el manejador de señales */
	sigact.sa_mask = sigset; /* utilizar el sigset vacio */
	sigact.sa_flags = 0; /* no se necesitan banderas o flags */
	sigaction( SIGINT, &sigact, NULL );
	
	 while((i > 0) && cierre){
	    id = fork();

		if (id < 0){ 
			printf("errno = %d\n", errno);
			perror("main");
			cierre = false;
			printf("El numero de maximo de procesos que un usuario puede tener es: %ld \n", count);
	    	}else if ( id == 0 ){
			
			printf ("Inicio proceso hijo. proceso padre PID=%d, proceso hijo PPID=%d\n", getpid (), getppid ());
			exit( 0 ); 
		}else {
		  
		   id = wait( NULL );
		   // printf("El numero maximo de procesos que un usuario puede tener es: %i \n", count);
		}

		if(entrada == true){
			count= p1;
			entrada= false;
		}else{
			count++;
		}
								
		
		

	 }
	
	return 0;
}

void wakeup(int s )
{
	static int detener = 0;
	if(detener == 0){
		cierre=false;
		printf("El numero de procesos alcanzado hasta el momento es: %ld \n", count);
	}
  	

}
