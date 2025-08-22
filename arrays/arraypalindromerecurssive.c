#include <stdio.h>
#include <stdlib.h>
int isPalindrome(int arr[],int i,int n){
    if(i > n){
        return 1;
    }
      if(arr[i]==arr[n-1]){
        return isPalindrome(arr,i+1,n-1);
     }               
  return 0;


  
}
int main(){

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if(isPalindrome(arr, 0, n )) {
        printf("The array is a palindrome.\n");
    } else {
        printf("The array is not a palindrome.\n");
    }




    return 0;
}