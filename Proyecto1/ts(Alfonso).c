#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[]){
    int uid1 = atoi(argv[1]); // id del primer usuario
    int count1 = atoi(argv[2]); // numero de procesos que el primer usuario debe bifurcar
    int uid2 = atoi(argv[3]); // id del segundo usuario
    int count2 = atoi(argv[4]); // numero de procesos que le segundo usuario debe bifurcar
    int timing = atoi(argv[5]); // segundos de duracion del programa
    (double) timing integer;
    pid_t pid1, pid2;
	time_t start, end, total, startp, endp, totalp;
    printf("UID  COUNT  USERTIME  SYSTIME  USER+SYSTEM\n");
    start = time(NULL);

	for (int i; i<count1; i++){
		pid1 = fork();
	}

    for (int j; j<count2; j++){
        pid2 = fork();
    }

    if (pid1==0){
        pid1 = wait(NULL);
    }
    else{
        startp = time(NULL);
        while(1){
            end = time(NULL);
            total = (double)(end-start);
            if (timing == total) break;

        }
        endup = time(NULL);
        totalp = (double)(endp-startp);
        printf("%d  %d  %ld  SYSTEMTIME  USER+SYSTEM\n", uid1 count1 totalp);

    }

    if (pid2==0){
        pid2 = wait(NULL);
    }
    else{
        startp = time(NULL);
        while(1){
            end = time(NULL);
            total = (double)(end-start);
            if (timing == total) break;

        }
        endup = time(NULL);
        totalp = (double)(endp-startp);
    }

    return 0;
}
