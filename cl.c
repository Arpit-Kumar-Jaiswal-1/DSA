#include <stdio.h>
#include <stdlib.h>
struct Node{
 int data;
 struct Node *next;
};
void traversal(struct Node *p){
    struct Node *ptr=p;
    do{
            printf("%d \n",ptr->data);
            ptr=ptr->next;

    }while(ptr!=p);



}
struct Node *before(struct Node *s,int data){
    struct Node *ptr=s;
    do{
            printf("%d \n",ptr->data);
            ptr=ptr->next;

    }while(ptr!=s);

};
int main(){

struct Node *head=(struct Node*)malloc(sizeof(struct Node));
struct Node *first=(struct Node*)malloc(sizeof(struct Node));
struct Node *second=(struct Node*)malloc(sizeof(struct Node));
struct Node *third=(struct Node *)malloc(sizeof(struct Node));


head->data=34;
head->next=first;

first->data=23;
first->next=second;


second->data=78;
second->next=third;

third->data=909;
third->next=head;


traversal(third);




}
