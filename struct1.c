#include <stdio.h>
#include <stdlib.h>

struct stu{
  char name[50];
  int r;
  char g;

};
void read(struct stu s1[],int n){
    
    for(int i=0;i<n;i++){
        printf("Enter the details of student %d \n",i+1);
        printf("Enter the name \n");
        scanf("%s",s1[i].name);
        printf("Enter the roll no.\n");
        scanf("%d",&s1[i].r);
        printf("Enter the grades: \n");
        scanf("%c",&s1[i].g);
    }
}
void display(struct stu s1[],int n){
for (int i=0;i<n;i++){
    printf("the name of the student is %s",s1[i].name);
    printf("The roll no. of the student is %d",s1[i].r);
    printf("The grade of the student is",s1[i].g);
}
 
}
void sort(struct stu s1[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s1[i].r  > s1[i].r ){
                struct stu temp=s1[i];
                s1[i]=s1[j];
                s1[j]=temp;


            }
        }
    }


}
int main(){

 struct stu stu1[50];

int n, choice;
printf("Enter the number of students: ");
scanf("%d", &n);

do {
    printf("\nMenu:\n");
    printf("1. Read student details\n");
    printf("2. Display student details\n");
    printf("3. Sort students by roll number\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            read(stu1, n);
            break;
        case 2:
            display(stu1, n);
            break;
        case 3:
            sort(stu1, n);
            printf("Students sorted by roll number.\n");
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
} while (choice != 4);
 
 
 
 
 
 
 
 
    return 0;
}
