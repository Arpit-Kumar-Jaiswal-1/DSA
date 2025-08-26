#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
    struct node *prev;
};

// Function to create a new node
struct node* newNode(int coeff, int exp) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->coeff = coeff;
    n->exp = exp;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

// Insert node at end of DLL
struct node* insert(struct node* head, int coeff, int exp) {
    struct node* n = newNode(coeff, exp);
    if (head == NULL) {
        return n;
    }
    struct node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    return head;
}

// Polynomial addition
struct node* addPoly(struct node* head1, struct node* head2) {
    struct node* p1 = head1;
    struct node* p2 = head2;
    struct node* result = NULL;

    while (p1 && p2) {
        if (p1->exp == p2->exp) {
            result = insert(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            result = insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    // Add remaining terms
    while (p1) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2) {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Print polynomial
void printPoly(struct node* head) {
    struct node* temp = head;
    while (temp) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* sum = NULL;

    // First polynomial: 3x^3 + 2x^2 + 1x^1 + 1
    head1 = insert(head1, 3, 3);
    head1 = insert(head1, 2, 2);
    head1 = insert(head1, 1, 1);
    head1 = insert(head1, 1, 0);

    // Second polynomial: 3x^3 + 2x^2 + 1x^1 + 1
    head2 = insert(head2, 3, 3);
    head2 = insert(head2, 2, 2);
    head2 = insert(head2, 1, 1);
    head2 = insert(head2, 1, 0);

    printf("First Polynomial: ");
    printPoly(head1);

    printf("Second Polynomial: ");
    printPoly(head2);

    sum = addPoly(head1, head2);

    printf("Sum Polynomial: ");
    printPoly(sum);

    return 0;
}
