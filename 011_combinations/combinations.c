#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************* Function Prototypes *******************************************/
void printArr(int *arr, int len);
void combinations(int *arr, int len, int r, int *out, int outlen);
/************* Main Function *************************************************/
void main()
{
	int arr[] = {1, 2, 5, 7};
	int len = sizeof(arr)/sizeof(int);
	int count = 0;
	int out[4] = {0};
	int outLen = 3;

	printf("Input: ");
	printArr(arr, len);

	combinations(arr, len, outLen-1, out, outLen);

		
}

/************* Function Definitions ******************************************/
void printArr(int *arr, int len)
{
	for(int i = 0; i < len; i++)
		printf("%s%d%s", (i==0)?"[ ":"",arr[i], (i+1<len)?", ":" ]\n");
}

void combinations(int *arr, int len, int r, int *out, int outlen)
{
	int i = 0, j = 0, k = 0, tmp = 0;
	int *newArr = NULL;

	// Limiting condition
	if(r == 0)
	{
		for(i = 0; i < len; i++){
			out[r] = arr[i];
			printArr(out, outlen);
		}
		return;
	}

	for(i = 0; i < len; i++)
	{
		k = 0;
		newArr = malloc(sizeof(int)*(len-1));
		// This loop will create a newArr with one less digit than
		// original array removed digit will be in tmp
		for(j = 0; j < len; j++)
		{
			if(i != j)
				newArr[k++] = arr[j];
			else
				tmp = arr[j];
		}
		out[r] = tmp;
		combinations(newArr, len-1, r-1, out, outlen);
		free(newArr);
	}

	return;
}

