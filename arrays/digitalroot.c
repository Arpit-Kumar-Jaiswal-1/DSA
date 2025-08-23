#include <stdio.h>


int sum(int n) {
    if (n < 10)  // base case: already a single digit
        return n;

    int s = 0;
    while (n > 0) {
        s += n % 10;  // add last digit
        n /= 10;      // remove last digit
    }

    return sum(s); // recurse again on digit sum
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Calling sum() function...\n");
    int result = sum(n);
    printf("Digital root is: %d\n", result);

    return 0;
}
