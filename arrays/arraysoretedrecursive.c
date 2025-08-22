#include <stdio.h>
#include <stdlib.h>
int IsSorted(int arr[], int n){

if(n==0 || n==1)// size of array
{
    return 1;
}
if (arr[n-2] <= arr[n-1]) {
        return IsSorted(arr, n-1);
    }
   
    return 0;
}
/*int IsSortedoptimized(int arr[], int n) {
    if (n <= 1) return 1;
    if (arr[0] > arr[1]) return 0; 
    return IsSorted(arr + 1, n - 1); // recurse on smaller subarray
}*/

int main(){
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);

int arr[n];
printf("Enter %d elements:\n", n);
for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
}

if (IsSorted(arr, n)) {
        printf("Array is sorted\n");
    } 
     else {
        printf("Array is not sorted\n");
    }

    return 0;
}