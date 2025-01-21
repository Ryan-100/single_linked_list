// del_last.c
// In this file, we are deleting the last node of the linked list.
// In this case, we are using two pointers: one to point the last node and the another one to point the second last node.
// Then, we set the second last node to point to NULL.
// After that, we set the last node free (deleted) in the memory.
// We are using while loop to traverse the link and do the function.
// Created by Kyaw Zin Htet. 21 January 2025.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *link;
} NODE_T;

//Function Declarations
void del_last(NODE_T *head);
void add_begin(NODE_T **head, int data);

int main()
{
  NODE_T *head = malloc(sizeof(NODE_T));
  head->data = 45;
  head->link = NULL;

  add_begin(&head, 98); // We are passing the memory address of the head pointer instead of passing the value of the pointer with & operater.
  add_begin(&head, 3);

  del_last(head);

  // Traverser part
  NODE_T *ptr = head;
  while (ptr != NULL)
  {
    printf("%d\n",ptr->data);
    ptr = ptr->link; //shifting to next node in each iteration.
  }
  return 0;
};

// Function Definition of the delete last node.
// Arguments : the pointer of the head node.
// Function : We check for whether it is empty, only one node or more. If there is one node, we just free the head pointer in the memory. If there are more nodes, we create 2 pointers to access the last and second last node pointers by "traversing" the link. Then, we store the last node's pointer to the second last node's pointer(which simply make the second last node as the LAST NODE) and then fee the memory of the post-last node's pointer.
// ****************** Note- There is no return in this case because we are not deleting the head of the node which needs to be returend the head node to access in the main fucntion. However, in here we don't need to return since we are deleting the last node and changes are reflected to the linked list even in the child caller function. ******** 

void del_last(NODE_T *head)
{
  if(head == NULL) 
    printf("List is already empty!");
  else if(head->link == NULL)
  {
    // In this case, there is only one node(head).
    free(head); // free memory of that node
    head = NULL; // make sure not pointing to nothing.
  }
  else
  {
    // Creating two pointers to store the last and second last node.
    NODE_T *temp = head;
    NODE_T *temp2 = head;

    // Loop until the last node
    while (temp->link != NULL)
    {
      temp2 = temp; // Storing the -1 node of the "temp" into "temp2"
      temp = temp->link; // Shifting to new node in each iteration
    };
    temp2->link = NULL; // temp2 became the last node so it should point to NULL
    free(temp); // deleting the temp node which was the last node
    temp = NULL;
  }
};


//Function Definition of the node adding at the beginning.
//Arguments : A doblue pointer => A pointer pointing to the head pointer in this case and the data we want to add.
//Function : We asked for the double pointer to modify the global head pointer and create a new node (ptr) and then point to the address of the head pointer and then update the head pointer to point to the new node (ptr). 
//Note : A double pointer (struct node **head) is required if you need to modify the head pointer in the caller function.
void add_begin(NODE_T **head, int data)
{
  NODE_T *new = malloc(sizeof(NODE_T)); // allocating memory to (new) pointer
  new->data = data; // adding data
  new->link = *head; // we make the new node point to the head node which will become the second node of the link.
  *head = new; // we just updated the head pointer to point the new node in the link from child function.
};