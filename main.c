#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void printAll(struct Node *head)
{
  struct Node *current = head;

  while (current != NULL)
  {
    printf("%d -> ", current->data);
    current = current->next;
  }

  printf("NULL\n");
}

int main()
{
  struct Node *head = (struct Node *)malloc(sizeof(struct Node));
  head->data = 10;

  struct Node *foot = (struct Node *)malloc(sizeof(struct Node));
  foot->data = 20;

  head->next = foot;
  foot->next = NULL;

  printAll(head);

  free(foot);
  free(head);
  return 0;
}