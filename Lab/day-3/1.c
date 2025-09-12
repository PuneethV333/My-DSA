#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
 
// Stack implementation using array
typedef struct {
   int data[MAX];
   int top;
} Stack;
 
// Initialize the stack
void initStack(Stack *s) {
   s->top = -1;
}
 
// Check if stack is empty
int isEmpty(Stack *s) {
   return s->top == -1;
}
 
// Push to stack
void push(Stack *s, int value) {
   if (s->top < MAX - 1) {
      s->data[++(s->top)] = value;
   }
}

// Pop from stack
int pop(Stack *s) {
   if (!isEmpty(s)) {
      return s->data[(s->top)--];
   }
   return 0; // safeguard
}

// Peek top of stack
int peek(Stack *s) {
   if (!isEmpty(s)) {
      return s->data[s->top];
   }
   return 0;
}

 
// Calculate total score from operations
int calculateScore(char operations[][10], int n) {
   Stack s;
   initStack(&s);

   for (int i = 0; i < n; i++) {
      if (strcmp(operations[i], "+") == 0) {
         // sum of last two
         int val1 = pop(&s);
         int val2 = peek(&s);
         push(&s, val1);          // put val1 back
         push(&s, val1 + val2);

      } else if (strcmp(operations[i], "D") == 0) {
         int val = peek(&s);
         push(&s, 2 * val);

      } else if (strcmp(operations[i], "C") == 0) {
         pop(&s);

      } else {
         // integer score
         int num = atoi(operations[i]);
         push(&s, num);
      }
   }

   // Sum up all values in stack
   int total = 0;
   for (int i = 0; i <= s.top; i++) {
      total += s.data[i];
   }

   return total;
}

 
// Driver code
int main() {
   int n;
   scanf("%d", &n);
 
   char operations[n][10];
   for (int i = 0; i < n; i++) {
       scanf("%s", operations[i]);
   }
 
   int result = calculateScore(operations, n);
   printf("%d\n", result);
 
   return 0;
}