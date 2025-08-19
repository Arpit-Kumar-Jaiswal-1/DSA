#include <stdio.h>
#include <stdlib.h>
int main (){
    int arr[]={14,9,15,6,5,67}; int key;
     for(int i=1;i<6;i++){
            key=arr[i];
        // compare it with left and shift it the right
         int j=i-1;
         while(j>=0 && arr[j] > key){
            arr[j+1]=arr[j];
            j--;
         }
        arr[j+1]=key;

     }
     printf("Traversing through array \n");
     for(int i=0;i<6;i++){
        printf("%d \n",arr[i]);
     }











  return 0;
}
