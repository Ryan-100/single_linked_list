// del_first.c
// In this file, we are deleting the first node of the linked list.
// We don't need any traversing to delete the node.
// We will be creating a temp node which is same address as head point and head pointer is shifted to (head+1) node and then temp node is free. Then making NULL to the temp pointer.
// Created by Kyaw Zin Htet. 21 January 2025.

#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
  int data;
  struct node *link;
} NODE_T;

//Function Declaration
NODE_T* del_first(NODE_T *head);
void add_begin(NODE_T **head, int data);
void add_end(NODE_T *ptr, int data);


int main()
{
  NODE_T *head = malloc(sizeof(NODE_T));
  head->data = 98;
  head->link = NULL;

  add_begin(&head, 45); //This is same as the file "add_begin(2).c".
  add_begin(&head, 3); //This is same as the file "add_begin(2).c".

  head = del_first(head); // The head pointer from main function is updated with the return value.

  NODE_T *ptr = head; 
  add_end(ptr, 3);

  ptr = head; // copy to (ptr) to traverse and not to lose head pointer
  while (ptr != NULL)
  {
    printf("%d\n",ptr->data);
    ptr = ptr->link; // traversing
  }
  return 0;
}

//Function Defintion of deleting first node
// Arguments : the pointer to the head node so that we can delete
// Function : We check the link is empty or not. If not, we copy head pointer to the temp pointer and then shift the head pointer to its next pointer. Then, we free the memory of temp pointer which is same as post-head was pointing to. Then we make sure that temp is not pointing to nothing by assigning NULL.
// Return : The updated head pointer to the main function with return value.
NODE_T* del_first(NODE_T *head)
{
  if(head == NULL)
    printf("List is already empty!");
  else
  {
  NODE_T *temp = head; // Copy the address of head to temp pointer
  head = head->link; // Then copy head to the next node of the head
  free(temp); // Delete or free the memory of the temp which was head.
  temp = NULL;
  }
  return head;
};

//Function Definition of the node adding at the beginning.
//Arguments : A doblue pointer => A pointer pointing to the head pointer in this case and the data we want to add.
//Function : We asked for the double pointer to modify the global head pointer and create a new node (ptr) and then point to the address of the head pointer and then update the head pointer to point to the new node (ptr). 
//Note : A double pointer (struct node **head) is required if you need to modify the head pointer in the caller function.
void add_begin(NODE_T **head, int data)
{
  NODE_T *new = malloc(sizeof(NODE_T));
  new->data = data;
  new->link = *head;
// Dereference the double pointer to access the original head.
// Dereferencing the double pointer (*head) lets you modify the original pointer (head) in the caller function, ensuring the new node is correctly set as the head of the linked list.
  *head = new;
  // Modify the original head pointer to point to the new node.
  //in which new node is pointing to the post-head node.
}


// Arguments : the pointer to the head of the linked list and the data we want to add 
// Arguments: The pointer to the head node & the data we want to add.
// Function: By creating a temp pointer(temp) and a copied pointer(ptr) for the data we have passed from the function's parameter and add to the head node which we have passed from the arguments.
// Note: In here we are not using method 2 as file "optimal_add_at_end.c" because we are not only using this function. Method 2 is important the ptr is pointing to the last node by each function call but we have inserted the 2 data and ptr is pointing to the head pointer so we cannot accessing the last node without traversing the link.
void add_end(NODE_T *ptr, int data)
{
  NODE_T *temp = malloc(sizeof(NODE_T));
  temp->data = data;
  temp->link = NULL;
  //up to this is just creating a new node

  while(ptr->link != NULL)
  {
    ptr = ptr->link; //changing the node for each iteration with the next node.
  }
  ptr->link = temp; // Now we inserted the temp node at the end of the linked list.
}