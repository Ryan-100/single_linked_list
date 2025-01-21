// count.c 
// This is about the printing the counts of how many nodes do we have.
// According to the file "3.c", we have created 3 nodes.
// Now we will be using a function that will return us the count of the nodes.
// Created by Kyaw Zin Htet. 19 January 2025.

#include <stdio.h>
#include <stdlib.h>

//Note : The struct node definition shoule be at the top, so it is visible to all subsequent code, including the "count_of_nodes" function declaration.


struct node
{
  int data;
  struct node *link;
};


void count_of_nodes(struct node *head); // function declaration of the counts function


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
// up to this point is same with the file "3.c" which we just created the third node of the linked list
// In order to get the counts of the linked list, we will create a function with "while loop" to return the counts
// The function name is ###count_of_nodes### underneath of the main function
  count_of_nodes(head); // we can simply pass the head node to know the counts of the linked list.
  return 0;
}




// Arguments: the pointer to the head node
// Function: counts the numbers of the nodes in the linked list when the head node is passed to the function
void count_of_nodes(struct node *head) // function definition of the counts function
{
  int count = 0; // initialized the variable to know the counts 
  if(head == NULL) // A condition to check whether the linked list is empty or not.
  {
    printf("Linked List is empty.");
  }
  else
  {
    struct node *ptr = NULL; // creating a new pointer to access the values from the head node which is passed from the function's parameter.
    ptr = head; // now the "ptr" is copied with the values from the head.
    while(ptr != NULL) // This condition is required to check until the last node
    {
      count++; // increasing the counts so that we can know the numbers of the nodes.
      ptr = ptr->link; // changing the link of the node for each iteration with next node.
    };
    printf("%d",count); // printing the counts of the linked list.
  }
}

//Note : Time complexity of the while loop above is Big_O(n).
