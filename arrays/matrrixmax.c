#include <stdio.h>
#include <stdlib.h>


void maxi( int a[][2],int b[][2] ){
    int i, j;
    int c[2][2];
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            c[i][j] = (a[i][j] > b[i][j]) ? a[i][j] : b[i][j];
        }
    }
    printf("Resultant matrix (element-wise max):\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

}


int main(){
    int a[2][2], b[2][2];
    int i, j;

    printf("Enter elements of first 2x2 matrix:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second 2x2 matrix:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    maxi(a, b);




     return 0;
}