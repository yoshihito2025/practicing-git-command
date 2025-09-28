#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

void *safeMalloc(size_t size)
{
  void *p = malloc(sizeof(size));
  if (p == NULL)
  {
    perror("Failed to allocation memories.\n");
    exit(EXIT_FAILURE);
  }

  return p;
}

void printAll(Node *head)
{
  Node *current = head;

  while (current != NULL)
  {
    printf("%d", current->data);
    current = current->next;
    if (current != NULL)
    {
      printf(" -> ");
    }
  }

  printf("\n");
}

void insertElement(Node *x, Node *y)
{
  if (x == NULL || y == NULL)
    return;
  y->next = x->next;
  x->next = y;
}

void freeList(Node *head)
{
  Node *current = head;
  while (current != NULL)
  {
    Node *tmp = current->next;
    free(current);
    current = tmp;
  }
}

int main()
{
  Node *head = safeMalloc(sizeof(Node));
  head->data = 10;

  Node *foot = safeMalloc(sizeof(Node));
  foot->data = 20;

  head->next = foot;
  foot->next = NULL;

  printAll(head);

  struct Node *element1 = safeMalloc(sizeof(Node));
  element1->data = 15;

  insertElement(head, element1);
  printAll(head);

  // 先頭からメモリ解放
  freeList(head);

  return 0;
}