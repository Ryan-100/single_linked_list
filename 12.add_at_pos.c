//add_at_pos.c
//In this file, we are adding a data to a certain point of the linked list by traversing.
// Let's assume we know the position we want to add in this case.
// Created by Kyaw Zin Htet. 21 January 2025.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *link;
} NODE_T; // we can write like this to reduce sytax
// NODE_T equals to struct node as we have written.

//Function Declaration of add at end function.
NODE_T* add_at_end(NODE_T *ptr, int data);

//Function Declaration of add at a position we know function.
void add_at_pos(NODE_T *head, int data, int position);

int main()
{
  NODE_T *head = malloc(sizeof(NODE_T));
  head->data = 45;
  head->link = NULL;

  NODE_T *ptr = head;
  ptr = add_at_end(ptr, 98);
  ptr = add_at_end(ptr, 3);

  int position = 3;
  add_at_pos(head, 33, position);

  ptr = head;
  while(ptr != NULL)
  {
    printf("%d\n",ptr->data);
    ptr = ptr->link; //traversing in each iteration
  }
  return 0;
};

//Function Defition of the add_at_end().
//Arguments : a pointer to the head of the linked list and the data we want to add.
//Function : By creating a temp node to add the data to the last node of the linked list in EACH return of this function.
//Return : We return the last node to avoid traverse for further additions.
NODE_T* add_at_end(NODE_T *ptr, int data)
{
  NODE_T *new = malloc(sizeof(NODE_T));
  new->data = data;
  new->link = NULL;
//up to this is created new node which is to be added to the end of the link.

  ptr->link = new;  // (ptr) pointer is pointing to the last node;
  return new; //Then we have to return the last node for further additions.
  //If you returned ptr instead of new, the caller would still have a reference to the old last node, which is no longer the actual last node after the new node is added. This would break the logic for further additions.
}

//Arguments: pointer to the head, the data we want to add and the position we want to add.
//Function: 
void add_at_pos(NODE_T *head, int data, int position)
{
  //Simply we have to create the new node;
  NODE_T *new = malloc(sizeof(NODE_T));
  new->data = data;
  new->link = NULL;

  NODE_T *ptr = head; //we copy the address of head to (ptr) to be more visible.

  // Traverse the linked list to find the desired position.
  position--; // Subtract 1 to find the node before the target position.
  while(position != 1 && position > 1)
  {
    ptr = ptr->link;
    position --;
  };
  // Insert the new node at the desired position.
  new->link = ptr->link; // we have to make new node point to the third node as example since new node is put between second node and third node.
  ptr->link = new; // The ptr node is still pointing to the old "next node." To include the new node in the list, we must update ptr->link so that ptr now points to new. This connects the new node to the list at the desired position.
};

// Why ptr->link = new is required:

// What happens before ptr->link = new:
// When you execute new->link = ptr->link;, the new node starts pointing to the node that ptr was pointing to (the next node in the list).
// However, this operation only establishes the forward link from new to the next node but does not modify the list to include new yet.


// Why we need ptr->link = new:
// The ptr node is still pointing to the old "next node." To include the new node in the list, we must update ptr->link so that ptr now points to new. This connects the new node to the list at the desired position.


// What would happen if you omit ptr->link = new:
// The new node would not be part of the list. It would exist independently in memory, pointing to the next node, but nothing in the list would reference it. This breaks the chain and effectively leaves the new node disconnected from the linked list.