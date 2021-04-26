#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//function to swap elements
void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	
}

//function to put a partition position
int division(int array[], int low , int high)
{
	int pivot;
	pivot = array[high];
	int i;
	i = (low-1);
	int j;
	for(j=low;j<high;j++)
	{
		if(array[j]<=pivot)
		{
			i++;
			swap(&array[i],&array[j]);
		}
	}
	
	swap(&array[i+1],&array[high]);
	return (i+1);
}

//function to quicksorting 
void quicksorting(int array[], int low, int high)
{
	if(low < high)
	{
		int pi;
		pi = division(array,low,high);
		quicksorting(array,low,pi-1);
		quicksorting(array,pi+1,high);
	}
}

//function to printing the sorted array
void printarray(int array[], int arrsize)
{
	int i;
	for(i=0;i<arrsize;++i)
	{
		printf("%d  ",array[i]);
	}
	printf("\n");
	
}

//Main of the program
int main()
{
	int data[]={8,7,2,1,0,9,6,12,67,34,11};
	int n;
	n = sizeof(data)/sizeof(data[0]);
	
	printf("\nUnsorted array\n");
	printarray(data,n);  	//printing the unsorted array
	quicksorting(data,0,n-1);
	
	printf("Sorted array in ascending order:\n");
	printarray(data,n);		//printing the sorted array
}

//Output

Unsorted array
8  7  2  1  0  9  6  12  67  34  11
Sorted array in ascending order:
0  1  2  6  7  8  9  11  12  34  67
