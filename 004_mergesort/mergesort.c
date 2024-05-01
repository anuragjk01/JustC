#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mergeSort(int *arr, int len);
void printArr(int *arr, int len);

void main()
{
	int arr[] = {2, 7, 4, 2, 0, 6, 9, 8, 1, 3, 5};
	int len = sizeof(arr)/sizeof(*arr);

	printArr(arr, len);
	mergeSort(arr, len);
	printArr(arr, len);

}

void mergeSort(int *arr, int len)
{
	int *arr1 = NULL;
	int *arr2 = NULL;
	int len1 = 0;
	int len2 = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	if(len == 1)
		return;

	len1 = len/2;
	len2 = len - len/2;

	// Recursive splitting (returns when it cannot be splitted further)
	mergeSort(&arr[0], len1);
	mergeSort(&arr[len1], len2);

	// Temp arrays
	arr1 = malloc(len1*sizeof(int));
	memcpy(arr1, &arr[0], len1*sizeof(int));
	arr2 = malloc((len2)*sizeof(int));
	memcpy(arr2, &arr[len1], len2*sizeof(int));


	// Merging the arrays in a sorted manner
	for(i = 0; i < len; i++)
	{
		// There are items left in both arrays
		if((j < len1) && (k < len2))
		{
			if(arr1[j] < arr2[k])
			{
				arr[i] = arr1[j++];
			}
			else
			{
				arr[i] = arr2[k++];
			}
		}
		// No more items in arr1, copy rest of arr2 without any check
		else if(j >= len1)
		{
			arr[i] = arr2[k++];
		}
		// No more items in arr2, copy rest of arr1 without any check
		else if(k >= len2)
		{
			arr[i] = arr1[j++];
		}
	}
}

void printArr(int *arr, int len)
{
	printf("[ ");
	for(int i = 0; i < len; i++)
		printf("%d, ", arr[i]);
	printf("\b\b ]\n");
}

