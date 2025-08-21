#include <stdlib.h>
#include <stdio.h>

// Structure for a node in doubly linked list
struct Node {
    int data;
    struct Node *prev, *next;
};

// Function to be implemented
void findPairsWithGivenSum(struct Node *head, int x) {
    struct Node *start = head;
    struct Node *end = head;

    // Find the last node
    while (end && end->next)
        end = end->next;

    int found = 0;

    // Two-pointer approach
    while (start != end && end->next != start) {
        int sum = start->data + end->data;
        if (sum == x) {
            printf("(%d,%d) ", start->data, end->data);
            found = 1;
            start = start->next;
            end = end->prev;
        } else if (sum < x) {
            start = start->next;
        } else {
            end = end->prev;
        }
    }
    if (!found) {
        printf("No pair found");
    }
    printf("\n");
}


// Part of Driver Code
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver Code
int main() {
    int n, x;
    scanf("%d", &n);
    int arr[n];
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        insert(&head, arr[i]);
    }
    scanf("%d", &x);

    findPairsWithGivenSum(head, x);
    
    

    return 0;
}   