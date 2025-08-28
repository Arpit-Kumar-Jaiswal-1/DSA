#include <stdio.h>


int josephus(int n, int k) {
    if (n == 1)
        return 0; // base case (0-based index)
    else
        return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    printf("Enter number of people (n): ");
    scanf("%d", &n);
    printf("Enter step size (k): ");
    scanf("%d", &k);

    int result = josephus(n, k) + 1; // convert 0-based to 1-based index
    printf("The safe position is %d\n", result);

    return 0;
}
