
#include<iostream> 
#include<stdio.h>
#include<conio.h>



void merge(int array[], int x, int y, int z)
{
	int i, j, k;
	int a = y - x + 1;
	int a1 = z - y;

	
	int X[30], Z[30];


	
	for (i = 0; i < a; i++)
		X[i] = array[x + i];
	for (j = 0; j < a1; j++)
		Z[j] = array[y + 1 + j];

	
	i = 0; 
	j = 0; 
	k = x; 
	while (i < a && j < a1) 
	{
		if (X[i] <= Z[j])
	{
		array[k] = X[i];
		i++;
		}
		else
		{
		array[k] = Z[j];
		j++;
	}
	k++;
	}

	
	while (i < a)
	{
	array[k] = X[i];
	i++;
	k++;
	}

	
	while (j < a1) 
	{
	array[k] = Z[j];
	j++;
	k++;
	}
}
void mergeSort(int array[], int x, int z)
{
	if (x < z)
	{
		
	int y = x + (z - x) / 2;
	mergeSort(array, x, y);
	mergeSort(array, y + 1, z);
	merge(array, x, y, z);
	}
}

void printArray(int Arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	printf("%d ", Arr[i]);
	printf("\n");
}


int main()
{
	int A[] = { 3,1,4,1,5,9,2,6,5,3,5 };
	int A_size = sizeof(A) / sizeof(A[0]);

	printf("Given array is \n");
	printArray(A, A_size);

	mergeSort(A, 0, A_size - 1);

	printf("\nSorted array is \n");
	printArray(A, A_size);
	return 0;
}
