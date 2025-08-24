#include <stdio.h>
#define MAX 100

// Function to convert normal matrix to sparse representation
int convertToSparse(int rows, int cols, int matrix[rows][cols], int sparse[MAX][3]) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    return k; // number of non-zero elements
}

// Function to display sparse matrix
void displaySparse(int sparse[MAX][3], int k) {
    printf("Row Col Value\n");
    for (int i = 0; i < k; i++) {
        printf("%d   %d   %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

// Function to display normal matrix
void displayNormal(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Transpose of Sparse
void transposeSparse(int sparse[MAX][3], int k, int result[MAX][3]) {
    for (int i = 0; i < k; i++) {
        result[i][0] = sparse[i][1];
        result[i][1] = sparse[i][0];
        result[i][2] = sparse[i][2];
    }
}

// Fast Transpose
void fastTranspose(int sparse[MAX][3], int k, int result[MAX][3], int rows, int cols) {
    int count[cols], index[cols];
    for (int i = 0; i < cols; i++) count[i] = 0;

    for (int i = 0; i < k; i++) count[sparse[i][1]]++;

    index[0] = 0;
    for (int i = 1; i < cols; i++)
        index[i] = index[i - 1] + count[i - 1];

    for (int i = 0; i < k; i++) {
        int col = sparse[i][1];
        int pos = index[col]++;
        result[pos][0] = sparse[i][1];
        result[pos][1] = sparse[i][0];
        result[pos][2] = sparse[i][2];
    }
}

// Addition of Sparse
int addSparse(int A[MAX][3], int B[MAX][3], int m, int n, int C[MAX][3]) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        } else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        } else {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
    }
    while (i < m) { C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2]; i++; k++; }
    while (j < n) { C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2]; j++; k++; }
    return k;
}

// Subtraction of Sparse
int subtractSparse(int A[MAX][3], int B[MAX][3], int m, int n, int C[MAX][3]) {
    for (int i = 0; i < n; i++) B[i][2] = -B[i][2];
    return addSparse(A, B, m, n, C);
}

// Multiplication of Sparse (basic method)
int multiplySparse(int A[MAX][3], int B[MAX][3], int m, int n, int C[MAX][3], int rowsA, int colsA, int colsB) {
    int normalA[rowsA][colsA], normalB[colsA][colsB], normalC[rowsA][colsB];

    // Initialize normal matrices
    for (int i = 0; i < rowsA; i++) for (int j = 0; j < colsA; j++) normalA[i][j] = 0;
    for (int i = 0; i < colsA; i++) for (int j = 0; j < colsB; j++) normalB[i][j] = 0;
    for (int i = 0; i < rowsA; i++) for (int j = 0; j < colsB; j++) normalC[i][j] = 0;

    for (int i = 0; i < m; i++) normalA[A[i][0]][A[i][1]] = A[i][2];
    for (int i = 0; i < n; i++) normalB[B[i][0]][B[i][1]] = B[i][2];

    // Multiply
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                normalC[i][j] += normalA[i][k] * normalB[k][j];
            }
        }
    }

    // Convert back to sparse
    return convertToSparse(rowsA, colsB, normalC, C);
}

// Reconstruction (Sparse → Normal)
void reconstruct(int rows, int cols, int sparse[MAX][3], int k, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = 0;

    for (int i = 0; i < k; i++)
        matrix[sparse[i][0]][sparse[i][1]] = sparse[i][2];
}

// ================= MAIN ====================
int main() {
    int rows, cols;
    printf("Enter number of rows and cols: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    int sparse[MAX][3], k;
    k = convertToSparse(rows, cols, matrix, sparse);

    int choice;
    do {
        printf("\n--- Sparse Matrix Operations ---\n");
        printf("1. Display Normal & Sparse\n");
        printf("2. Transpose\n");
        printf("3. Fast Transpose\n");
        printf("4. Add two matrices\n");
        printf("5. Subtract two matrices\n");
        printf("6. Multiply two matrices\n");
        printf("7. Reconstruct Normal\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        int result[MAX][3], k2, k3, matrix2[rows][cols], sparse2[MAX][3];
        switch (choice) {
            case 1:
                printf("Normal Matrix:\n");
                displayNormal(rows, cols, matrix);
                printf("\nSparse Matrix:\n");
                displaySparse(sparse, k);
                break;

            case 2:
                transposeSparse(sparse, k, result);
                printf("Transpose (Sparse):\n");
                displaySparse(result, k);
                break;

            case 3:
                fastTranspose(sparse, k, result, rows, cols);
                printf("Fast Transpose:\n");
                displaySparse(result, k);
                break;

            case 4:
                printf("Enter second matrix (%dx%d):\n", rows, cols);
                for (int i = 0; i < rows; i++)
                    for (int j = 0; j < cols; j++)
                        scanf("%d", &matrix2[i][j]);
                k2 = convertToSparse(rows, cols, matrix2, sparse2);
                k3 = addSparse(sparse, sparse2, k, k2, result);
                printf("Addition Result (Sparse):\n");
                displaySparse(result, k3);
                break;

            case 5:
                printf("Enter second matrix (%dx%d):\n", rows, cols);
                for (int i = 0; i < rows; i++)
                    for (int j = 0; j < cols; j++)
                        scanf("%d", &matrix2[i][j]);
                k2 = convertToSparse(rows, cols, matrix2, sparse2);
                k3 = subtractSparse(sparse, sparse2, k, k2, result);
                printf("Subtraction Result (Sparse):\n");
                displaySparse(result, k3);
                break;

            case 6:
                printf("Enter second matrix (%dx%d):\n", cols, cols);
                for (int i = 0; i < cols; i++)
                    for (int j = 0; j < cols; j++)
                        scanf("%d", &matrix2[i][j]);
                k2 = convertToSparse(cols, cols, matrix2, sparse2);
                k3 = multiplySparse(sparse, sparse2, k, k2, result, rows, cols, cols);
                printf("Multiplication Result (Sparse):\n");
                displaySparse(result, k3);
                break;

            case 7:
                reconstruct(rows, cols, sparse, k, matrix2);
                printf("Reconstructed Normal Matrix:\n");
                displayNormal(rows, cols, matrix2);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
