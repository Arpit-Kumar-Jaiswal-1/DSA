#include <stdio.h>

void bubbleSort(int a[], int n, int *c, int *s) {
    *c = *s = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*c)++;
            if (a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
                (*s)++;
            }
        }
    }
}

void selectionSort(int a[], int n, int *c, int *s) {
    *c = *s = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            (*c)++;
            if (a[j] < a[min]) min = j;
        }
        if (min != i) {
            int t = a[i]; a[i] = a[min]; a[min] = t;
            (*s)++;
        }
    }
}

void insertionSort(int a[], int n, int *c, int *s) {
    *c = *s = 0;
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0) {
            (*c)++;
            if (a[j] > key) {
                a[j+1] = a[j];
                (*s)++;
                j--;
            } else break;
        }
        a[j+1] = key;
    }
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n], b[n], s[n], in[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        b[i] = s[i] = in[i] = arr[i]; // copies for each sort
    }

    int c1, s1, c2, s2, c3, s3;

    bubbleSort(b, n, &c1, &s1);
    selectionSort(s, n, &c2, &s2);
    insertionSort(in, n, &c3, &s3);

    printf("\nAlgorithm      Comparisons   Swaps\n");
    printf("----------------------------------\n");
    printf("Bubble Sort    %11d   %5d\n", c1, s1);
    printf("Selection Sort %11d   %5d\n", c2, s2);
    printf("Insertion Sort %11d   %5d\n", c3, s3);

    return 0;
}
