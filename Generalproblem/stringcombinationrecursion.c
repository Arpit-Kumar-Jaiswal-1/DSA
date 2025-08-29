#include <stdio.h>
#include <string.h>

void generateSubsets(char *str, char *curr, int i, int j) {
    // Base case: reached end of original string
    if (str[i] == '\0') {
        curr[j] = '\0';   // terminate the current subset
        printf("%s\n", curr);
        return;
    }

    // Case 1: include str[i]
    curr[j] = str[i];
    generateSubsets(str, curr, i + 1, j + 1);

    // Case 2: exclude str[i]
    generateSubsets(str, curr, i + 1, j);
}

int main() {
    char str[20];
    printf("Enter a string: ");
    scanf("%s", str);

    char curr[20]; // to store subset while building
    generateSubsets(str, curr, 0, 0);

    return 0;
}
