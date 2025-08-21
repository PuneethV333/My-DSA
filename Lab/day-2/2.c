#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};


struct Node *rotate(struct Node *head, int N) {
    for (int i = 0; i < N; i++){
        struct Node* start = head;
        struct Node* second;
        second = head->next;

        struct Node* end = head;
        while(end->next != NULL){
            end = end->next;
        }
        head = second;
        second->prev = NULL;
        end->next = start;
        start->prev = end;
        start->next = NULL;
    }
    return head;
}


void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node->next != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("%d", node->data);
    printf("\n");
}

struct Node* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct Node* head = NULL;
    for (int i = size - 1; i >= 0; i--) {
        push(&head, arr[i]);
    }
    return head;
}



int main() {
    int n, N;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &N);

    struct Node* head = createList(arr, n);
    head = rotate(head, N);
    printList(head);

    return 0;
}