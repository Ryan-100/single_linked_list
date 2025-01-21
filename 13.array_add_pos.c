//array_add_post.c
// This time, we are adding data to a certain position using array instead of linked list.
// We have to copy the old array data to the new array and we have to insert data in the desired point.
// 2 loops, 1 for copy until the desired point and insert data at that point. Then, another loop copy the data after that point.
// It takes Big_O(n) run time.
// Created by Kyaw Zin Htet. 21 January 2025.

#include <stdio.h>

//Function Declaration
// Note: There is no return in this function because when update the array passed to the function(which is equivalent to passing the address of the same array), which then reflect the changes made in the function in the caller function.
void add_at_pos(int arr[], int arr2[], int size, int data, int position);

int main()
{
  int arr[] = {2, 34, 21, 6, 7, 8, 90, 67, 23, 39}; // Define the array with some data.
  int position = 5, data = 78; // We make them as static to reduce complexity, but you can use scanf or fgets to get user input to these data.
  int size = sizeof(arr) / sizeof(arr[0]); // To know the length of array.
  int arr2[size+1]; // create a new array which is larger than "arr" to copy data.

  add_at_pos(arr, arr2, size, data, position);

  for(int i = 0; i < size+1; i++)
  {
    printf("%d\n",arr2[i]);
  }
  return 0;
}

void add_at_pos(int arr[], int arr2[], int size, int data, int position)
{
  int index = position - 1; // Array starts at 0 index. The desired position of index is position - 1.
  //1st loop: we have to iterate until the desired index to copy to arr2.
  for(int i = 0; i < index; i++)
    arr2[i] = arr[i];
    
  arr2[index] = data; //inserted data to the desired position

  //2nd loop: we have to start from the next index of desired index so that we can copy the rest of the data
  //loop until the arr size+1 because we have one new data in arr2[]
  for(int i = index+1 ; i < size+1; i++)
    arr2[i] = arr[i-1]; // copying the rest of the data to arr2 from arr 
};