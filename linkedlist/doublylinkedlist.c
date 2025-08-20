#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node* createNode(int data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = ptr->prev = NULL;
    return ptr;
}

struct Node* insertFront(struct Node *head, int data) {
    struct Node *newnode = createNode(data);
    if(head) {
        newnode->next = head;
        head->prev = newnode;
    }
    return newnode;
}

struct Node* insertEnd(struct Node *head, int data) {
    struct Node *newnode = createNode(data);
    if(!head) return newnode;
    struct Node *temp = head;
    while(temp->next) temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

struct Node* insertAtPos(struct Node *head, int data, int pos) {
    if(pos <= 1 || !head) return insertFront(head, data);
    struct Node *temp = head;
    int i = 1;
    while(temp->next && i < pos-1) {
        temp = temp->next;
        i++;
    }
    if(!temp->next) return insertEnd(head, data);
    struct Node *newnode = createNode(data);
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
    return head;
}

struct Node* deleteFront(struct Node *head) {
    if(!head) return NULL;
    struct Node *temp = head;
    head = head->next;
    if(head) head->prev = NULL;
    free(temp);
    return head;
}

struct Node* deleteEnd(struct Node *head) {
    if(!head) return NULL;
    if(!head->next) {
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while(temp->next) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct Node* deleteAtPos(struct Node *head, int pos) {
    if(!head) return NULL;
    if(pos <= 1) return deleteFront(head);
    struct Node *temp = head;
    int i = 1;
    while(temp && i < pos) {
        temp = temp->next;
        i++;
    }
    if(!temp) return head;
    if(temp->prev) temp->prev->next = temp->next;
    if(temp->next) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

void displayForward(struct Node *head) {
    printf("List (forward): ");
    while(head) {
        printf("%d <-> ", head->data);
        if(!head->next) break;
        head = head->next;
    }
    printf("NULL\n");
}

void displayBackward(struct Node *head) {
    if(!head) {
        printf("List (backward): NULL\n");
        return;
    }
    while(head->next) head = head->next;
    printf("List (backward): ");
    while(head) {
        printf("%d <-> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

int length(struct Node *head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
}

void search(struct Node *head, int key) {
    int pos = 1, found = 0;
    while(head) {
        if(head->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        head = head->next;
        pos++;
    }
    if(!found) printf("Element %d not found\n", key);
}

int main() {
    struct Node *head = NULL;
    int choice, data, pos, n, i;
    printf("Enter initial number of nodes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }
    do {
        printf("\nMenu:\n1. Display Forward\n2. Display Backward\n3. Insert at Front\n4. Insert at End\n5. Insert at Position\n6. Delete from Front\n7. Delete from End\n8. Delete from Position\n9. Length of List\n10. Search Element\n11. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: displayForward(head); break;
            case 2: displayBackward(head); break;
            case 3: printf("Enter data: "); scanf("%d",&data); head=insertFront(head,data); break;
            case 4: printf("Enter data: "); scanf("%d",&data); head=insertEnd(head,data); break;
            case 5: printf("Enter data and position: "); scanf("%d%d",&data,&pos); head=insertAtPos(head,data,pos); break;
            case 6: head=deleteFront(head); break;
            case 7: head=deleteEnd(head); break;
            case 8: printf("Enter position: "); scanf("%d",&pos); head=deleteAtPos(head,pos); break;
            case 9: printf("Length: %d\n", length(head)); break;
            case 10: printf("Enter element to search: "); scanf("%d",&data); search(head,data); break;
            case 11: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice!=11);
    return 0;
}
