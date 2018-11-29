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

int main(int argc, char *argv[]){
    int uid1 = atoi(argv[1]); // id del primer usuario
    int count1 = atoi(argv[2]); // numero de procesos que el primer usuario debe bifurcar
    int uid2 = atoi(argv[3]); // id del segundo usuario
    int count2 = atoi(argv[4]); // numero de procesos que le segundo usuario debe bifurcar
    int ejecucion = atoi(argv[5]);
    pid_t id;
    int i =0 , j=0; //auxiliar para cantidad de iteraciones a realizar por usuario
    int pid;
    time_t start1, start2, end, total1, total2, verificar,  verificarfinal;
    double suma1,suma2;
    bool entrada= true;
	double tics_per_second;
	tics_per_second = sysconf(_SC_CLK_TCK);
	
    verificar = time(NULL);
	
    while(entrada){

	 while ( i < count1){ //creo los procesos del usuario1
		start1 = time(NULL);//Tomo el tiempo actual
		id = fork();
		if (id < 0){
			printf("errno = %d\n", errno);
			perror("main");
		}else if ( id == 0 ){
			//printf("hola procesos usuario 1\n");
			i++;
		}else {//elimino los procesos innecesarios
			pid = getpid ();
			kill(pid, SIGKILL );
		}
    	 }

	 while ( j < count2){//creo los procesos del usuario2
		start2 = time(NULL);//Tomo el tiempo actual	
		id = fork();	
		if (id < 0){ 
			printf("errno = %d\n", errno);
			perror("main");
		}else if ( id == 0 ){
			 //printf("hola procesos usuario 2\n");
			j++;
		}else {//elimino los procesos innecesarios
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
    end = time(NULL);//Tomo el nuevo tiempo actual

	printf("UID COUNT USERTIME SYSTIME USER+SYSTEM\n");
    //calcular el tiempo de ejecucion de cada usuario
	total1 = (double)(end-start1);//Me da la duracion del usuario1
	clock_t stime1 = (double)(end-start1)/tics_per_second;//Duracion del sistema1
	suma1= total1+stime1;//Sumo los dos tiempos
	total2 = (double)(end-start2);//Me da la duracion del usuario2
	clock_t stime2 = (double)(end-start2)/tics_per_second;//Duracion del sistema2
	suma2= total2+stime2;//Sumo los dos tiempos

	
	printf("%d  %d  %lld  %lu  %f\n", uid1, count1, total1, stime1, suma1);
	printf("%d  %d  %lld  %lu  %f\n", uid2, count2, total2, stime2, suma2);

    return 0;
}
