#include <stdio.h>

#include <stdlib.h>


struct ListNode {
  int val;
  struct ListNode *next;
};



// Function to be implemented

struct ListNode* partition(struct ListNode* head, int x) {
    int small[1000], big[1000];
    int s = 0, b = 0;

    // Step 1: Separate into two arrays
    struct ListNode* temp = head;
    while (temp) {
        if (temp->val < x)
            small[s++] = temp->val;
        else
            big[b++] = temp->val;
        temp = temp->next;
    }

    // Step 2: Rebuild linked list in order
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;

    for (int i = 0; i < s; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = small[i];
        node->next = NULL;
        current->next = node;
        current = node;
    }
    for (int i = 0; i < b; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = big[i];
        node->next = NULL;
        current->next = node;
        current = node;
    }

    return dummy->next;
}



// Part of Driver Code

struct ListNode *createList(int *arr, int size) {
  if (size == 0)
    return NULL;



  struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
  head->val = arr[0];
  head->next = NULL;



  struct ListNode *current = head;
  for (int i = 1; i < size; i++) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = arr[i];
    node->next = NULL;
    current->next = node;
    current = node;

  }
   return head;
}



void printList(struct ListNode *head) {
  while (head) {
    printf("%d", head->val);
    if (head->next)
      printf(" ");
    head = head->next;
  }
  printf("\n");
}



// Driver Code:



int main() {
  int n, x;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  scanf("%d", &x);

  struct ListNode *head = createList(arr, n);
  struct ListNode *result = partition(head, x);
  printList(result);
  return 0;

}


