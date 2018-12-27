#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int mat[n][n], i, j;
    srandom(time(NULL));

    for(i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            mat[i][j] = 0;
        }
    }
    
    while(1){

        int r = random() % n;
        
        printf("%d:\n\n", r);
        for(i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if ((i == r) && (j != r))
                    mat[i][j] = 1;
                else if ((j == r) && (mat[i][j] != 0))
                    mat[i][j] = 0;
                printf("%d ",mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        sleep(3);
    }

    return 0;
}