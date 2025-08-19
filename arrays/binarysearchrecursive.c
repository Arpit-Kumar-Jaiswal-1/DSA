#include <stdio.h>

int binarysearch(int arr[],int start , int end , int target){
    
    if(start <= end ){
        int mid=(start+end)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            return binarysearch(arr, mid+1,  end, target);
        }
          return binarysearch(arr, start,  mid -1, target);

    }




    return -1;

}
int main(){
printf("Enter an array\n");
int arr[100];
for(int i=0;i<5;i++){
    scanf("%d",&arr[i]);
}
int target ;
printf("Enter  the target u wanna search \n");
scanf("%d",&target);
int k=binarysearch(arr,0,4,target);
if(k==-1){
    printf("Not found");
}
if(k!=-1){
    printf("Found");
}

    return 0;
}