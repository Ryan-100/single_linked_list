//optimal_add_at_end.c
// In this file, we will be optimizing the time complexity of adding at the end of the linked list.
// In previous files, we used traversing a linked list to print, count and add node at the end of the linked list.
// Now, we will reduce the time complexity to Big_O(1).
// Created by Kyaw Zin Htet. 19 January 2025.

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

// Function Declaration of the node adding at the end.
struct node* add_at_end(struct node *ptr, int data);

int main()
{
  struct node *head = malloc(sizeof(struct node)); // Creating the head node(Allocating the memory address to the head pointer).
  head->data = 45;
  head->link = NULL;

//Note: The head pointer is essential for accessing the entire linked list. If you modify head during the operations (e.g., reassign it), you lose the reference to the start of the list.
  struct node *ptr = head; // Copying the head node to (ptr) pointer so that we can add data without changing the head node and ptr to be always pointing to the last node.
  ptr = add_at_end(ptr, 98); //Memory address of value 98 was added to the head->link
  ptr = add_at_end(ptr, 3); // Memory address of value 3 was added to the [98]->link
  ptr = add_at_end(ptr, 67); // Memory address of value 67 was added to the [3]->link
  // Remember in each function call, we are updating the (ptr) from the return value of the function.
  ptr = head; // Need to update the linked list from ptr to head pointer to traverse. 

  printf(" This is from head: %d\n",head->link->link->data);
  // This part is used to traverse the linked list for printing the data form each node.
  while (ptr != NULL) // To check until the last node.
  {
    printf("%d\n", ptr->data); // Printing the current data of each node.
    ptr = ptr->link; // Changing to next node in each iteration.
  }
  return 0;
};

// Arguments : the pointer to the head of the linked list and the data we want to add 
// Function : By creating a temp node to add the data to the last node of the linked list in EACH return of this function.
// Return : It is different from the other code (void) since, we are returning the node of the data we have added.
struct node* add_at_end(struct node *ptr, int data)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->data = data;
  temp->link = NULL; //Since it is the last node

  ptr->link = temp; // This line is important since it is chaning the end of the node whenever this function is called. (which is same as {{head->link = current}} as previous codes.) 
  //ptr is updating the link part of the node with the new node.
  return temp;
}


//Note: Now our add_at_end function of time complexity is Big_O(1) instead of Big_O(n) we reduce the traversing part and make pointing to next node at the constat amount of time.

//Note : Why does head see the changes?
// Because head and ptr are pointing to the same list in memory, and changes made via ptr are to the shared data, not to the pointers themselves.