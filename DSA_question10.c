#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//function to swap the position of elements
void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


void heapify(int array[], int n, int i)
{
	int largest = i;		//to find the largest among node, 
	int left = 2*i+1;		//its left node,
	int right = 2*i+2;		//its right node
	
	if(left<n && array[left] > array[largest])
	{
		largest=left;
	}
	if(right<n && array[right] > array[largest])
	{
		largest=right;
	}
	
	if(largest!=i)
	{
		swap(&array[i],&array[largest]);
		heapify(array,n,largest);
	}
}

//Main function to do heapsort
void heapsort(int array[], int n)
{
	int i;
	for(i=n/2 - 1;i>=0;i--)
	{
		heapify(array,n,i);
		
	}
	
	for(i=n-1;i>=0;i--)
	{
		swap(&array[0],&array[i]);
		heapify(array,i,0);
	}
}

//Printing the sorted array
void printingarray(int array[], int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		printf("%d  ",array[i]);
		
	}
	printf("\n");
}

//Main of the program
int main()
{
	int array[]={1,12,10,50,78,11,13,6};
	int n = sizeof(array)/sizeof(array[0]);
	heapsort(array,n);
	
	printf("Sorted array is \n");
	printingarray(array,n);
}


//Output
Resetting queue Visited 0
 Visited 2
 Visited 1
 Visited 4
 Resetting queue Visited 3
