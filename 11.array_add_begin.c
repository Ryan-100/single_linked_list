//array_add_begin.c
// Now we will be using arrays to insert data.
// Unlike linked lists which take O(1) run time, arrays take O(n) asymptoticaly to insert data at the beginning.
// Since we have to loop n amount of data to the right and insert data at the beginning.
// Created by Kyaw Zin Htet. 21 January 2025.

#include <stdio.h>

// Function Declaration of add_begin
int add_begin(int a[], int n, int data);

int main()
{
  int a[10], n;
  printf("Enter the number of elements: ");
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    printf("Enter %d index->",i);
    scanf("%d",&a[i]);
  };

  n = add_begin(a, n, 10);

  for(int i = 0; i < n; i++)
    printf("The %d index of element is: %d\n",i , a[i]);
   
  return 0;
}

//Function Definition
//Arguments : The array we want to add, the size of your array and the data we want to add.
//Function : We loop through from the last index of array and shift the index(s) to the right to have space in 0 index of the array. Then, we add the data at 0 index of the array.
//Return : The size of the inserted array to print data;
int add_begin(int a[], int n, int data)
{
  //Unlike, others we loop data from the back so that we can leave space for [0];
  //We can also do loop from the start, but you have to make sure i = 1 and i < n+1.
  for (int i = n - 1; i >= 0; i--)
    a[i+1] = a[i]; // shift to the next index of each index until 0 index
  a[0] = data; // Place the empty space of 0 index with data want to pass
  return n+1;// we increased n by 1 because we have inserted one element   
};

//********Note: If the array is full, we have to copy data to new array and increase size. ********** */