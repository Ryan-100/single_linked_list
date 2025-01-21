//array_add_end.c
//This file is about we add data to the end of the arrray.
// We will have 2 versions [array is not full] and [array is full].
// When the array is not full, the time complexity of adding data to the end is Big_O(1).
// When the array is full, the time plexity is Big_O(n) because we have to copy the previous array elements to the new empty array and have to declare more space to add new element to the array.
// Created by Kyaw Zin Htet. 21 January 2025.

#include <stdio.h>
#include <stdlib.h>

//Arguements: The current array we are working on, the no.of elements in the array and the data we want to add
//Function: This is the function we add the data at the end of the array which is currently not full.
//Return : The size of the array
int add_at_end_space(int a[], int freePos, int data)
{
  a[freePos] = data; //Simply add the new data at free position. Eg.If you have array with 2 element this means array[2] = data; 
  freePos++; //Increasing one to this variable since we have inserted a new data.
  return freePos;
}

//Note:The error boundary handling cases are left to avoid complex nature.
//Arguments : The data we want to add.
//Function : This is a function which asks user to enter how many elements want to be added in the array and add the new data to the end of the array.
// Return : 
void has_space(int data)
{
  int a[10];
  int n, freePos; // n for user's input to store how many elements and freePos for handle the free position of the array.
  printf("Enter the number of elements:");
  scanf("%d", &n); //store input data to variable n
  
  // We loop through the amount of times user enterd and ask again the data to add into array.
  for(int i = 0; i<n; i++)
  {
    printf("Enter for %d index->",i);
    scanf("%d",&a[i]);
  } 
  freePos = n; // we now know the free position from the size of the array (which is same as how many elements user wants to add).
  freePos = add_at_end_space(a, freePos, data);

  //This is about printing thd data, we use "freePos" to loop because we have added one new data and n is the previous state of the array size.
  for(int i=0; i < freePos; i++)
  {
    printf("The %d index of element is : %d\n", i, a[i]);
  };
};

//Arguments: a = full array, b = new array with more space so that we can add data,
//           size = current size of "array a",freePos=The index we want to add
//           (will be last index of "array b"), data = we want to add.
//Function : Copy elements from old array to new array and add data to new array at the end.
//Return : The last index of the new array or the size of the array

int add_at_end_full(int a[], int b[], int size, int freePos, int data)
{ 
  for(int i = 0; i < size; i++) // This is copying data from "array a" to "array b".
    b[i] = a[i];
  //---------Copied a to b-----------//
  b[freePos] = data; // adding data to the last index of "array b".
  freePos++; // increment the size
  return freePos;
}

void full_array(int data)
{
  int a[3]; //To be tested easily, defining the array that can store only 3 elements.
  int n, freePos; // Same variable declaration with the has_space().
  printf("Enter the number of elements:");
  scanf("%d", &n); //store input data to variable n
  // We loop through the amount of times user enterd and ask again the data to add into array.
  for(int i = 0; i<n; i++)
  {
    printf("Enter for %d index->",i);
    scanf("%d",&a[i]);
  } 
  freePos = n; // we now know the free position from the size of the array (which is same as how many elements user wants to add).
  int size = sizeof(a)/sizeof(a[0]); // This is getting the length of array so that we know it is full or not.

  if(size == freePos) // we check whether the array is full or not.
  {
    int b[size+2]; // We have to create another array which has bigger than the "array a".
    freePos = add_at_end_full(a, b, size, freePos, data); //adding a data to the end.
    //This is about printing thd data, we use "freePos" to loop because we have added one new data and n is the previous state of the "new" array size.
    for(int i=0; i < freePos; i++)
    {
      printf("The %d index of element is : %d\n", i, b[i]);
    };
  }
  else
  {
    freePos = add_at_end_space(a, freePos, data);
    //This is about printing thd data, we use "freePos" to loop because we have added one new data and n is the previous state of the array size.
    for(int i=0; i < freePos; i++)
    {
      printf("The %d index of element is : %d\n", i, a[i]);
    };
  }
};

int main()
{
  //This part is adding data to the array which is not full.
  printf("1.This part is adding data to the array which is not full.\n");
  has_space(65);

  //This part is adding data to the full array.
  printf("\n\n2.This part is adding data to the full array.\n");
  full_array(65);
  return 0;
};
