#include <stdio.h>
#include <stdlib.h>

void main()
{
    int menor=5;
    int entre=5;
    int mayor=10;

    for(int i=20;i>=0;i--){
        if((menor-i)>0){
            printf("*   ");
        }else{
            printf("    ");
        }
        if((entre-i)>0){
            printf("*   ");
        }else{
            printf("    ");
        }
        if((mayor-i)>0){
            printf("*");
        }
        printf("\n");
    }

    return;
}
