//2.c
// creating a current node after the first node so that it can points to the next node
// Created by Kyaw Zin Htet. 19 January 2025.

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

int main()
{
  struct node *head = malloc(sizeof(struct node)); // allocating the memory of the head node
  head->data = 45;
  head->link = NULL;// created the head node

  struct node *current = malloc(sizeof(struct node)); //create another node so that the first node can point to the next node
  current->data = 98;
  current->link = NULL; // make sure the last node is always NULL (in this case there are only actual data)
  head->link = current; // pointing the head node to the second data
  printf("First node->%p and Second node->%p",head->link,current->link);
  return 0;
};