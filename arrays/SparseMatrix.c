#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
     // Sparase Matrix conversion
     int sparse[rows*cols][3];
     int k=0;
     for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j] != 0) {
            sparse[k][0]=i;
            sparse[k][1]=j;
            sparse[k][2]=matrix[i][j];
            k++;
        }
    }
}
     printf("\nSparse Matrix Representation (row col value):\n");
    for(int i=0; i<k; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
//Performin addition
int transpose[k][3];
for(int i=0;i<k;i++){
     transpose[i][0]=sparse[i][1];
     transpose[i][1]=sparse[i][0];
     transpose[i][2]=sparse[i][2];
}
printf("\nTranspose Sparse Matrix Representation (row col value):\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }

 


    return 0;
}