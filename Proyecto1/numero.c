#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>

int main( int argc, char **argv)
{
	pid_t id;
	double count=0;
	bool fin= true;
	double p1,p2;
	
	 while(1 && fin){
	    id = fork();
		p1 = getpid();

		if (id<0){ 
			printf("errno = %d\n", errno);
			perror("main");
			fin = false;
	    	} else if ( id == 0 ){
			p2 = getppid ();
			exit( 0 ); 
		}else {
		   id = wait( NULL );
			if (p1>p2){
				count = p1;
			}else{
				count = p2;
			}
		}
	 }
	
printf("El numero de maximo de procesos que un usuario puede tener es: %f \n", count);
	
	return 0;
}
