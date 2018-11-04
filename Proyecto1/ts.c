#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

int main(int argc, char *argv[]){
    int uid1 = atoi(argv[1]); // id del primer usuario
    int count1 = atoi(argv[2]); // numero de procesos que el primer usuario debe bifurcar
    int uid2 = atoi(argv[3]); // id del segundo usuario
    int count2 = atoi(argv[4]); // numero de procesos que le segundo usuario debe bifurcar
    pid_t id;
    int i =0 , j=0; //auxiliar para cantidad de iteraciones a realizar por usuario
    int k,l, pid; // indices para darle formato a la impresion de los resultados
    time_t start, end, total;
    double tiempo1[count1]; // declaracion de unos arreglos para guardar el tiempo inicial de ejecucion de cada proceso
    double tiempo2[count2];
    double fin1[count1]; // declaracion de unos arreglos para guardar el tiempo final de ejecucion de cada proceso
    double fin2[count2];
     

     while ( i < count1){
	start = time(NULL);
	tiempo1[i] = (double)start;	
	id = fork();	
	if (id < 0){ 
		printf("errno = %d\n", errno);
		perror("main");
	}else if ( id == 0 ){
		printf("hola procesos usuario 1\n");
		i++;
	}else {
		pid = getpid ();
		kill(pid, SIGKILL );
	}
    } 
    end = time(NULL);
    // tomar el timepo final de cada proceso
     for(i =0; i< count1; i++){
	fin1[i] = (double)end;
	}

    //calcular la suma de los tiempos del primer usuario
    for(i =0; i< count1; i++){
	 total = (double)(fin1[i]-tiempo1[i]);
	}
    printf("El programa del usuario 1 en %lld segundos\n", total);

    while ( j < count2){
	start = time(NULL);
	tiempo2[i] = (double)start;	
	id = fork();	
	if (id < 0){ 
		printf("errno = %d\n", errno);
		perror("main");
	}else if ( id == 0 ){
		printf("hola procesos usuario 2\n");
		j++;
	}else {
		pid = getpid ();
		kill(pid, SIGKILL );
	}
    } 
    end = time(NULL);
    // tomar el timepo final de cada proceso
     for(i =0; i< count1; i++){
	fin2[i] = (double)end;
	}

    //calcular la suma de los tiempos del primer usuario
    for(i =0; i< count1; i++){
	 total = (double)(fin2[i]-tiempo2[i]);
	}
    printf("El programa del usuario 1 en %lld segundos\n", total);
    
   // while(1){} */

	 /*for(k =0; k<3; k++){
		for(l =0; l<5; l++){
			if(k == 0){
				if(l == 0){
					printf("| UID");
				}else if( l == 1){
					printf("| COUNT");	
				}else if( l == 2){
					printf("| USERTIME");	
				}else if( l == 3){
					printf("| SYSTEMTIME");	
				}else( l == 4){
					printf("| USER+SYSTEM |");	
				}
			}else if(k==1){
				if(l == 0){
					printf("%d ",uid1);
				}else if( l == 1){
					printf(" %d",count1);	
				}else if( l == 2){
					printf("| USERTIME");	
				}else if( l == 3){
					printf("| SYSTEMTIME");	
				}else( l == 4){
					printf("| USER+SYSTEM |");	
				}
			}else {
				if(l == 0){
					printf("%d ",uid2);
				}else if( l == 1){
					printf(" %d",count2);	
				}else if( l == 2){
					printf("| USERTIME");	
				}else if( l == 3){
					printf("| SYSTEMTIME");	
				}else( l == 4){
					printf("| USER+SYSTEM |");	
				}
			}
		}
	} */
    	
	
    return 0;
}
