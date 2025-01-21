//add_begin(2).c
// In this file, we are adding data at the beginning of the linked list in another way.
// In 9.add_begin.c, we passed the value of the head pointer(struct node *head) as an argument to the function and return a node and update the head node with that returned node
// Now, we will be passing the address of the head pointer to the function and create a **pointer which is a pointer to another pointer and update that pointer(which is pointing to the head node) with the new data node we have added.
// Created by Kyaw Zin Htet. 21 January 2025.

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

//Function Declaration of the node adding at the beginning.
void add_begin(struct node **head, int data);

int main()
{
  struct node *head = malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;

  struct node *current = malloc(sizeof(struct node));
  current->data = 98;
  current->link = NULL;

  head->link = current;

  add_begin(&head, 3);// & is the referencing the address of the head node.
  //now we print data with traversing
  current = head;
  while (current != NULL)
  {
    printf("%d\n",current->data);
    current = current->link; //shifting to next node in each iteration.
  }
  return 0;
};

//Function Definition of the node adding at the beginning.
//Arguments : A doblue pointer => A pointer pointing to the head pointer in this case and the data we want to add.
//Function : We asked for the double pointer to modify the global head pointer and create a new node (ptr) and then point to the address of the head pointer and then update the head pointer to point to the new node (ptr). 
//Note : A double pointer (struct node **head) is required if you need to modify the head pointer in the caller function.
void add_begin(struct node **head, int data)
{
  struct node *ptr = malloc(sizeof(struct node));
  ptr->data = data;
  ptr->link = *head; // Dereference the double pointer to access the original head.
// Dereferencing the double pointer (*head) lets you modify the original pointer (head) in the caller function, ensuring the new node is correctly set as the head of the linked list.
  *head = ptr;  // Modify the original head pointer to point to the new node.
  //in which new node is pointing to the post-head node.
};

//Note : The time complexity of this function is Big_O(1).
