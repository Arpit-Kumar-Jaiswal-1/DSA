#include <stdio.h>
#include <stdlib.h>
int climb(int n){
  if(n==0 ){
    return 1;//stay there 
  }
  if( n<0) {
    return 0; // no way;
  }
return climb(n-1)+climb(n-2);



}
int main(){
    int n;
    printf("Enter number of stairs: ");
    scanf("%d", &n);
    printf("Number of ways to climb %d stairs: %d\n", n, climb(n));







    return 0;
}
