#include <stdio.h>
#include <stdlib.h>
void matrix(int a[2][2],int b[][2]){
    int j=0;
  int i=0;
int c[2][2];
for(i = 0; i < 2; i++) {
    for(j = 0; j < 2; j++) {
        c[i][j] = a[i][j] + b[i][j];
    }
}
 int result[2][2];
 for(i = 0; i < 2; i++) {
    for(j = 0; j < 2; j++) {
        int s=0;
        for(int k=0;k<2;k++){
            s+=a[i][k] * b[k][j];
        }
        result[i][j]=s;

    
    }
}

}
void magicsquare(int a[2][2]){
    int s1=0, s2=0, d1=0, d2=0;
    int row_sum[2] = {0}, col_sum[2] = {0};
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            row_sum[i] += a[i][j];
            col_sum[j] += a[i][j];
            if(i == j) d1 += a[i][j];
            if(i + j == 1) d2 += a[i][j];
        }
    }

    if(row_sum[0] == row_sum[1] && col_sum[0] == col_sum[1] &&
       row_sum[0] == col_sum[0] && d1 == d2 && d1 == row_sum[0]) {
        printf("The matrix is a magic square.\n");
    } else {
        printf("The matrix is NOT a magic square.\n");
    }
}
int main(){

    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};

    printf("Matrix A:\n");
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    matrix(a, b);

    printf("Checking if Matrix A is a magic square:\n");
    magicsquare(a);

    printf("Checking if Matrix B is a magic square:\n");
    magicsquare(b);



    return 0;
}