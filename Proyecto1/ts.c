#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

void procesos(){

 while(1){
		
 }  
 
}

void procesos2(){
 pid_t id;
 id = fork();

 
 while(1){
	printf("proceso numero usuario 2:");	
 }  
 
}

int main(int argc, char *argv[]){
    int uid1 = atoi(argv[1]); // id del primer usuario
    int count1 = atoi(argv[2]); // numero de procesos que el primer usuario debe bifurcar
    int uid2 = atoi(argv[3]); // id del segundo usuario
    int count2 = atoi(argv[4]); // numero de procesos que le segundo usuario debe bifurcar
    pid_t id;
    int i =0 , j=0; //auxiliar para cantidad de iteraciones a realizar por usuario
    int k,l; // indices para darle formato a la impresion de los resultados 
	
     clock_t inicio1, inicio2,final1,final2, total_t;

    while ( i < count1){
	id = fork();

		if (id < 0){ 
			printf("errno = %d\n", errno);
			perror("main");
	    	}else if ( id == 0 ){
			
			
			exit( 0 ); 
		}else {
		   procesos();
		   
		   
		}

	i++;
    }
    
    while ( j < count2){
	id = fork();

		if (id < 0){ 
			printf("errno = %d\n", errno);
			perror("main");
	    	}else if ( id == 0 ){
			
			
			exit( 0 ); 
		}else {
		   procesos2();
		   
		   
		}
	j++;
    }

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
