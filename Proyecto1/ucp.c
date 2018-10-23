#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int BUFFSIZE = atoi(argv[1]), fd1, fd2, count;
    char buffer[BUFFSIZE];
    
    if ((BUFFSIZE>=1) || (BUFFSIZE<=16384)){
        if ((fd1=open(argv[2], O_RDONLY))<0){
            fprintf(stderr, "el archivo %s no se puede abrir\n", argv[2]);
		    exit(1);
        }
        if ((fd2=open(argv[3], O_CREAT | O_WRONLY))<0){
            fprintf(stderr, "el archivo %s no se puede abrir\n", argv[3]);
		    exit(1);
        }
        while ((count=read(fd1, buffer, BUFFSIZE))>0){
		    write(fd2, buffer, count);
	    }
        close(fd1);
        close(fd2);
    }
    else printf("Usted introdujo un tamaño de buffer incorrecto");
    return 0;
}