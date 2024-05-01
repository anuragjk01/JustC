#include<stdio.h>

void quickSort(int *arr, int len);
void printArr(int *arr, int len);
void swap(int *a, int *b){
	if(*a != *b){
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

void main()
{
	int arr[] = {2, 7, 4, 2, 0, 6, 9, 8, 1, 3, 5};
	int len = sizeof(arr)/sizeof(*arr);

	printArr(arr, len);
	quickSort(arr, len);
	printArr(arr, len);

}

void quickSort(int *arr, int len)
{
/*
 *  This algorithm assumes arr[0] as the pivot always. 
 *  
 */
	int i = 0;
	int j = 0;

	if(len <= 1)
		return;

	i = 0;
	j = len-1;
	while( i < j )
	{
		while( (arr[i] <= arr[0]) && (i < (len-1)) )
			i++;

		while( (arr[j] > arr[0]) && (j > 0) )
			j--;

		if(i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[0], &arr[j]);

	quickSort(&arr[0], j);
	quickSort(&arr[j+1], len-j-1);
}

void printArr(int *arr, int len)
{
	printf("[ ");
	for(int i = 0; i < len; i++)
		printf("%d, ", arr[i]);
	printf("\b\b ]\n");
}

