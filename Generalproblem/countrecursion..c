// Recurssion to count  zero present in the Elements
#include <stdio.h>
#include <stdlib.h>
int  count(int n){
       if(n<10){
        return (n==0)?1:0;
    }
     int lastDigit = n % 10;
    if (lastDigit == 0)
        return 1 + count(n / 10);
    else
        return count(n / 10);

  return n;
}
int main(){
   int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Number of non-zero digits: %d\n", count(n));
    return 0;
}