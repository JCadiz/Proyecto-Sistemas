#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[]){
    int uid1=atoi(argv[1]); 
    int count1=atoi(argv[2]);
    int uid2=atoi(argv[3]); 
    int count2=atoi(argv[4]);
    int pid = fork();

    return 0;
}