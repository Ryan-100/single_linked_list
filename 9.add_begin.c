//add_begin.c
//In this file, we will be adding a data at the beginning of the linked list.
// Created by Kyaw Zin Htet. 21 January 2025.

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

//Function declaration of the node adding at the beginning.
struct node* add_begin(struct node *ptr, int data);
//Function declaration of the node adding at the end.
struct node* add_end(struct node *ptr, int data);

int main()
{
  struct node *head = malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL; //Currently, head is the first node and it is pointing to nothing.

  head = add_begin(head, 1); // Memory address of head is now pointing the [1] node after this function becuase the newly added data became the head node and the head node became the second node.

  struct node *ptr = head; // created a ptr pointer and copied the head node to this pointer.
  ptr = add_end(ptr, 98); //Memory address of value 98 was added to the head->link
  ptr = add_end(ptr, 3); // Memory address of value 3 was added to the [98]->link
  ptr = add_end(ptr, 67); //Memory address of value 67 was added to the [3]->link
  //Then we have to update ptr to point to head node to traverse the linked list.
  ptr = head;
  while(ptr != NULL)
  {
    printf("%d\n",ptr->data);
    ptr = ptr->link;
  };
  return 0;
};

//Arguments : a pointer to the head of the linked list and the data we want to add.
//Function : By creating a temp node to add the data to the last node of the linked list in EACH return of this function.
//Return : We return a node of the new data we have added.
struct node* add_end(struct node *ptr, int data)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->data = data;
  temp->link = NULL; //Since it is the last node

  ptr->link = temp; // This is important because it is changing the end of the node whenever the function called. {{3 nodes[pre last node] -> temp(which is last node)}}
  return temp;
};

//Arguments: A pointer to the head of the linked list and the data we want to add.
//Function : By creating a temp node and add the data to the front of the linked list in EACH return of this function.
//Return : We return a node of the new data we added.
struct node* add_begin(struct node *head, int data)
{
  struct node *ptr = malloc(sizeof(struct node)); // Creating a pointer to the new node
  ptr->data = data; // Add data to that new node
  ptr->link = head; // Directly point the head node which became the second node and ptr node became the first node.

  return ptr;
};

//-------- This is the code of NESO Academy ---------- //
// struct node* add_begin(struct node *head, int data)
// {
//   struct node *ptr = malloc(sizeof(struct node));
//   ptr->data = data;

// This part is different from Kyaw Zin Htet's code which has more step to point to head node and modify the head node and return it.
//   ptr->link = NULL; 

//   ptr->link = head;
//   head = ptr;
//   return head;
// };

