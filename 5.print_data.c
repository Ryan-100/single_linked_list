//print_data.c
// This is about printing the data from each nodes we have created.
// According to the file "3.c", we have created 3 nodes.
// In the file "count.c", we have printed how many nodes we have created.
// Now we will be writing a function to print the data from each node.
// Created by Kyaw Zin Htet. 19 January 2025.

#include <stdio.h>
#include <stdlib.h>

//Note : The struct node definition shoule be at the top, so it is visible to all subsequent code, including the "print_data" function declaration.

struct node
{
  int data;
  struct node *link;
};

void print_data(struct node *head); // function declaration of the printing data function.

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
// In order to get the data from each node, we will create a function with "while loop" to return the data from each node.
// The function name is ###print_data### underneath of the main function.
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

//Note : Time complexity of the while loop above is Big_O(n).