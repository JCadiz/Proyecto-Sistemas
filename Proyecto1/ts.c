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

int main(int argc, char *argv[]){
    int uid1 = atoi(argv[1]); // id del primer usuario
    int count1 = atoi(argv[2]); // numero de procesos que el primer usuario debe bifurcar
    int uid2 = atoi(argv[3]); // id del segundo usuario
    int count2 = atoi(argv[4]); // numero de procesos que le segundo usuario debe bifurcar
    int ejecucion = atoi(argv[5]);
    pid_t id;
    int i =0 , j=0; //auxiliar para cantidad de iteraciones a realizar por usuario
    int k,l, pid; // indices para darle formato a la impresion de los resultados
    time_t start, end, total1, total2, verificar,  verificarfinal;
    double tiempo1[count1]; // declaracion de unos arreglos para guardar el tiempo inicial de ejecucion de cada proceso
    double tiempo2[count2];
    double suma1,suma2;
    bool entrada= true;
	
    verificar = time(NULL);
	
    while(entrada){

	 while ( i < count1){
		start = time(NULL);
		tiempo1[i] = (double)start;	
		id = fork();	
		if (id < 0){ 
			printf("errno = %d\n", errno);
			perror("main");
		}else if ( id == 0 ){
			//printf("hola procesos usuario 1\n");
			i++;
		}else {
			pid = getpid ();
			kill(pid, SIGKILL );
		}
    	 } 
   
	 while ( j < count2){
		start = time(NULL);
		tiempo2[j] = (double)start;	
		id = fork();	
		if (id < 0){ 
			printf("errno = %d\n", errno);
			perror("main");
		}else if ( id == 0 ){
			 //printf("hola procesos usuario 2\n");
			j++;
		}else {
			pid = getpid ();
			kill(pid, SIGKILL );
		}
	  } 
	verificarfinal= time(NULL);
	/*printf("verificar hasta este momento %i \n", (int)(verificarfinal - verificar));*/
	if(((int)(verificarfinal - verificar)) == ejecucion){
		entrada = false;	
	}
	
    }
	printf("UID  COUNT  USERTIME  SYSTIME  USER+SYSTEM\n");
    end = time(NULL);
    //calcular el tiempo de ejecucion de cada usuario 
    for(i =0; i< count1; i++){
	total1 = total1 + (int)(end-tiempo1[i]);
    }
    for(i =0; i< count2; i++){
	total2= total2 + (int)(end-tiempo1[i]);
    }
	

	 for(k =0; k<3; k++){
		for(l =0; l<5; l++){
			if(k == 0){
			}if(k==1){
				if(l == 0){
					printf("%d  ",uid1);
				}else if( l == 1){
					printf("%i  ",count1);	
				}else if( l == 2){
					printf("%li  ", total1);	
				}else if( l == 3){
					printf("%i  ",ejecucion);	
				}else{
					printf("%d  \n",(int)(total1 + (int)(ejecucion)));	
				}
			}else {
				if(l == 0){
					printf("%d  ",uid2);
				}else if( l == 1){
					printf("%d   ",count2);	
				}else if( l == 2){
					printf("%li   ", total2);	
				}else if( l == 3){
					printf("%i   ",ejecucion);	
				}else{
					printf("%i   \n",(int)(total2 + (int)(ejecucion)));	
				}
			}
		}
	} 



    	
	
    return 0;
}
