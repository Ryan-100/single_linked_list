// 3.c
// In this file, we are creating the third node of the single linked list.
// We can create many pointers as we have so many data but it is a waste of memory.
// Therefore, we can access the other nodes of the data from the head like this head->link->link and etc.
// Overall, we will be using the current node to add more data and head node to access the datas.
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
  struct node *head = malloc(sizeof(struct node)); 
  head->data = 45;
  head->link = NULL;

  struct node *current = malloc(sizeof(struct node));
  current->data = 98;
  current->link = NULL;
  head->link = current;
// up to this point is same with the file "2.c" just created up to second node
// now we need to create the third node by using the current node since we can access the previous nodes with the "HEAD NODE"

  current = malloc(sizeof(struct node)); // this is simply creating third node with the "CURRENT NODE"
  current->data = 3;
  current->link = NULL;

// now we have created the third node with "CURRENT NODE" and to connect the second node of the linked list we have to use "HEAD NODE"
  head->link->link = current;
  printf("%p\n",head);
  return 0;
};