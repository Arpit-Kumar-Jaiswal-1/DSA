#include <stdio.h>
#include <stdlib.h>
int Max(int arr[] ,int n,int max){
   
    if(n==0){
        return max;
    }
    if(arr[n-1]>max){
        max=arr[n-1];
    }
   
  return Max(arr,  n-1, max);

}
/*Non-Accumulator 
int findMax(int arr[], int n) {
    if (n == 1) return arr[0];          
    int maxRest = findMax(arr+1, n-1);  
    return (arr[0] > maxRest) ? arr[0] : maxRest;
}

*/
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxi = -100000; // Minimum value for a signed int

    int max = Max(arr, n,maxi);
    printf("Maximum element is: %d\n", max);

    free(arr);
    




}