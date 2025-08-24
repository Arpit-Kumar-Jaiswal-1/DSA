#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* detectCycleStep(struct Node* head) {
    struct Node *slow = head, *fast = head;
    int step = 0;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        step++;
        printf("Step %d: slow -> %d, fast -> %d\n", step, slow->data, fast->data);

        if (slow == fast) {
            printf("Cycle detected at node %d\n", slow->data);

            // Find start of the cycle
            slow = head;
            step = 0;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
                step++;
                printf("Step %d: slow -> %d, fast -> %d\n", step, slow->data, fast->data);
            }
            printf("Start of cycle is at node %d\n", slow->data);
            return slow;
        }
    }

    printf("No cycle detected.\n");
    return NULL;
}

int main() {
    int n, i, pos;
    struct Node *head = NULL, *temp = NULL, *cycleNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input linked list from user
    for (i = 1; i <= n; i++) {
        int val;
        printf("Enter value for node %d: ", i);
        scanf("%d", &val);
        struct Node* node = newNode(val);
        if (!head) {
            head = node;
            temp = head;
        } else {
            temp->next = node;
            temp = temp->next;
        }
    }

    // Ask if user wants to create a cycle
    printf("Enter the node number to link last node to (0 for no cycle): ");
    scanf("%d", &pos);
    if (pos > 0) {
        temp = head;
        for (i = 1; i < pos; i++) {
            temp = temp->next;
        }
        cycleNode = temp;
        temp = head;
        while (temp->next) temp = temp->next;
        temp->next = cycleNode;
    }

    // Detect cycle and find start
    detectCycleStep(head);

    return 0;
}
