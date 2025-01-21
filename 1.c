// 1.c
// This is about creating the first node of the single linked list
// Created by Kyaw Zin Htet. 19 January 2025.

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link; //creating a pointer by self referencing a struct which is a node to another linked list
}; // A node is nothing but self referencial struct containing two data types.

int main()
{
  struct node *head = NULL; //defining the head of the linked list which is the first node
  head = (struct node *)malloc(sizeof(struct node));//(struct node *) is called typecasting which is standard but not important to include
  head->data = 45; // adding data to the head
  head->link = NULL; //pointing null to the first of the node
  printf("%d", head->data); // the expected output will be 45 since we are adding it.
  return 0;
}