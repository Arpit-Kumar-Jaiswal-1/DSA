#include <stdio.h>
#include <stdlib.h>
int  count(int arr[],int n, int x){
    if(n==0){
        return 0;
    }
   if(arr[n-1]==x){
  return 1+ count(arr,n-1,x);
    
}
    return count(arr,n-1 ,x); 

}
int main(){
int n, i;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr[n];
printf("Enter %d elements:\n", n);
for(i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
}
int x;
printf("Enter element to count: ");
    scanf("%d", &x);

    printf("Element %d occurs %d times\n", x,count(arr, n, x));



   return 0; 
}