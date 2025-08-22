#include <stdio.h>
#include <stdlib.h>
int sum(int n){
    if(n==0){
        return 0;
    }
int d=n%10;
int s=0;
s=s+d;
n=n/10;
return s + sum(n);




}
/*int sumDigits(int n) { //optimized little bit
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}
*/
int main(){
 int n;
    printf("Enter a number: ");
    scanf("%d", &n);

printf("Sum is %d",sum(n));


}