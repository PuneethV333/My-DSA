#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10000
// Stack structure for integers
typedef struct {
  int data[MAX];
  int top;
} Stack;
// Initialize stack
void initStack(Stack *s) {
  s->top = -1;
}
// Check if stack is empty
int isEmpty(Stack *s) {
  return s->top == -1;
}
// Push element to stack
void push(Stack *s, int value) {
  if (s->top < MAX - 1) {
    s->data[++(s->top)] = value;
  }
}

// Pop element from stack
int pop(Stack *s) {
  if (s->top >= 0) {
    return s->data[(s->top)--];
  }
  return 0; // fallback
}

// Peek top element
int peek(Stack *s) {
  if (s->top >= 0) {
    return s->data[s->top];
  }
  return 0; // fallback
}
 
int asteroidCollision(int* asteroids, int n, int* result) {
    Stack s;
    initStack(&s);

    for (int i = 0; i < n; i++) {
        int curr = asteroids[i];
        int destroyed = 0;

        // Process collisions only if curr is moving left and stack top moves right
        while (!isEmpty(&s) && curr < 0 && peek(&s) > 0) {
            if (abs(curr) > abs(peek(&s))) {
                pop(&s); // top asteroid destroyed
                continue; // keep checking collisions
            } else if (abs(curr) == abs(peek(&s))) {
                pop(&s); // both destroyed
                destroyed = 1;
                break;
            } else {
                destroyed = 1; // current asteroid destroyed
                break;
            }
        }

        if (!destroyed) {
            push(&s, curr);
        }
    }

    // Transfer survivors from stack to result array
    int size = s.top + 1;
    for (int i = 0; i < size; i++) {
        result[i] = s.data[i];
    }
    return size;
}
 
// Driver code
int main() {
   int n;
   scanf("%d", &n);
 
   int asteroids[MAX], result[MAX];
 
   for (int i = 0; i < n; i++) {
       scanf("%d", &asteroids[i]);
   }
 
   int finalSize = asteroidCollision(asteroids, n, result);
 
   for (int i = 0; i < finalSize; i++) {
       printf("%d ", result[i]);
   }
   printf("\n");
 
   return 0;
}