// add_node_at_end.c
// This is about we are inserting a new node at the end of the function.
// According to the file "3.c", we have created 3 nodes.
// Now, we ill be using a function to insert a new node at the end of the linked list.
// Created by Kyaw Zin Htet. 19 January 2025.

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

// Function declaration of the node add at the end function.
void add_at_end(struct node *head, int data); 

// Function declaration of the printing data function.
void print_data(struct node *head); 

int main()
{
  struct node *head = malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;

  struct node *current = malloc(sizeof(struct node));
  current->data = 98;
  current->link = NULL;
  head->link = current;

  current = malloc(sizeof(struct node));
  current->data = 3;
  current->link = NULL;

  head->link->link = current;
// up to this point is same with the file "3.c" which we just created the third node of the linked list.
// In order to add the new node at the end of the linked list, we will create a function with "while loop" to add.
// The function name is ###add_at_end### underneath the print_data function.
  add_at_end(head,67); // We can simply pass the head node to the function which will add the new data at the end of the linked list.
  print_data(head); // We can simply pass the head node to the function which will return the data of each node.
  return 0;
};


// Arguments: the pointer to the head node
// Function: prints the data from each node of the linked list when the head node is passed to the function.
void print_data(struct node *head) // Function definition of the print data function.
{
  if(head == NULL) // A condition to check whether the linked list is empty or not.
  {
    printf("Linked list is empty.");
  }
  else{
    struct node *ptr = NULL; // creating a new pointer to access the value from the head node which is passed from the function's parameter. You will see in the next line of the code.
    ptr = head; // Now, the ptr is copied with the values from the head.
    while(ptr != NULL) // This condition is required to check until the last node.
    {
      printf("%d\n", ptr->data); // Printing the data of each node.
      ptr = ptr->link; //Changing the link of the node for each iteration with next node.
    }
  }
};


// Arguments: The pointer to the head node & the data we want to add.
// Function: By creating a temp pointer(temp) and a copied pointer(ptr) for the data we have passed from the function's parameter and add to the head node which we have passed from the arguments.
void add_at_end(struct node *head, int data)
{
  struct node *temp, *ptr; // We are creating 2 pointers to (temp) is to add the new node and (ptr) is to be used as the head node while looping the linked list.
  ptr = head;
  temp = (struct node*)malloc(sizeof(struct node)); // We are passing the created memory address of the temp node to the temp pointer.

  // Now, we are adding the data we got from the parameter to the temp node and making the temp->link as "NULL" by the time temp node is made as the last node.
  temp->data = data;
  temp->link = NULL;

  while(ptr->link != NULL)
  {
    ptr = ptr->link; //changing the node for each iteration with the next node.
  }
  ptr->link = temp; // Now we inserted the temp node at the end of the linked list.
};

//Note : Time complexity of the while loop above is Big_O(n).











// The case of using (ptr->link != NULL) instead of (ptr != NULL) as the previous C codes is explained below:

// The goal of the loop is to traverse the linked list and stop at the last node.
// If you use while (ptr->link != NULL), the loop will stop at the last node because the link of the last node is NULL.
// If you use while (ptr != NULL), the loop will stop after traversing the last node, and ptr will become NULL. This means you won’t have access to the last node, which is needed to add the new node at the end.

// What Happens in Each Case
// Case 1: while (ptr->link != NULL)
// The condition ensures the loop iterates until ptr points to the last node.
// After the loop, ptr still points to the last node, allowing you to set ptr->link = temp to insert the new node.
// Example (Visualization): For a linked list: head -> node1 -> node2 -> NULL

// Initially: ptr = head.
// First iteration: ptr moves to node1.
// Second iteration: ptr moves to node2. Now ptr->link == NULL, so the loop stops.
// You can now set ptr->link = temp, adding the new node after node2.
// Case 2: while (ptr != NULL)
// The condition will iterate until ptr becomes NULL, i.e., it goes past the last node.
// After the loop, ptr will no longer point to the last node, so you cannot set ptr->link = temp.
// Example (Visualization): For a linked list: head -> node1 -> node2 -> NULL

// Initially: ptr = head.
// First iteration: ptr moves to node1.
// Second iteration: ptr moves to node2.
// Third iteration: ptr becomes NULL. The loop stops, but now you don’t have access to the last node (node2).

// 3. Why while (ptr->link != NULL) is Correct
// It ensures that you stop at the last node, which is needed to attach the new node to the end of the list.
// Using while (ptr != NULL) would make it impossible to access the last node, resulting in an error when trying to set ptr->link.