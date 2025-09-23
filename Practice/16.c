#include <stdio.h>
#include <stdlib.h>

struct element
{
  int pty;
  int data;
};

typedef struct element element_t;

void pqinsert(element_t *q, int x, int pty, int *count)
{
  element_t temp;
  temp.data = x;
  temp.pty = pty;
  int pos = *count - 1;
  while ((pos >= 0) && (q[pos].pty > temp.pty))
  {
    q[pos + 1] = q[pos];
    pos--;
  }
  q[pos + 1] = temp;
  (*count)++;
}

element_t pqdelete(element_t *q, int *count)
{
  element_t temp;
  if (*count == 0)
  {
    printf("Queue is empty\n");
    temp.data = -1;
    temp.pty = -1;
  }
  else
  {
    temp = q[0];
    for (int i = 1; i < *count; i++)
    {
      q[i - 1] = q[i];
    }
    (*count)--;
  }
  return temp;
}

void qdisplay(element_t *q, int count)
{
  if (count == 0)
  {
    printf("Queue is empty\n");
    return;
  }
  for (int i = 0; i < count; i++)
  {
    printf("%d->%d\n", q[i].data, q[i].pty);
  }
}

int main()
{
  int k, ch, pty, x;
  element_t pq[100], temp;

  int count = 0;
  while (1)
  {
    qdisplay(pq, count);
    printf("\n1..insert");
    printf("\n2..remove");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter the priority..");

      scanf("%d", &pty);
      printf("Enter the value");
      scanf("%d", &x);
      pqinsert(pq, x, pty, &count);

      break;
    case 2:
      temp = pqdelete(pq, &count);
      if (temp.data > 0)
      {
        printf("deleted element:- data=%d", temp.data);
        printf("   priority=%d\n", temp.pty);
      }
      break;
    case 4:
      exit(0);
    }
  }
}
