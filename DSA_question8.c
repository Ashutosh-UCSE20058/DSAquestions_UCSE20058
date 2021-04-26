#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//function for merging two subarray into one array
void merge(int arr[], int p, int q,int r)
{
	int n1;
	n1  = q-p+1;
	int n2;
	n2 = r-q;
	int L[n1],M[n2]; //two subarrays
	int i;
	
	for(i=0;i<n1;i++)
		L[i]=arr[p+i];
	int j;
	for(j=0;j<n2;j++)
		M[j]=arr[q+1+j];
		
		
	int k;
	i=0;
	j=0;
	k=p;
	
	while(i<n1 && j<n2)
	{
		if(L[i]<=M[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=M[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=M[j];
		j++;
		k++;
	}
}

//function for merge sort
void mergesort(int arr[], int l, int r)
{
	if(l<r)
	{
		int m;
		m= l +(r-l)/2;
		
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
		
	}
}

//function for printing the sorted array
void printarray(int arr[], int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d  ",arr[i]);
	printf("\n");
}

//Main of the program
int main()
{
	int arr[] = {6,5,12,10,9,1};
	int size;
	size = sizeof(arr)/sizeof(arr[0]);
	mergesort(arr,0,size-1);
	
	printf("Sorted array: \n");
	printarray(arr,size);
}
