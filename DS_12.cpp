#include<stdio.h>
#define SIZE 8
int tmp[SIZE];

void merge(int arr[], int left, int right)
{
	int L, R, k, a;
	int mid = (left + right) / 2;
	L = left;
	R = mid + 1;
	k = left;
	while (L<=mid&&R<=right)
	{
		tmp[k++] = arr[L] <= arr[R] ? arr[L++] : arr[R++];
	}
	if (L > mid)
	{
		for (a = R; a <= right; a++)
		{
			tmp[k++] = arr[a];
		}
	}
	else
	{
		for (a = L; a <= mid; a++)
		{
			tmp[k++] = arr[a];
		}
	}

	for (a = left; a <= right; a++)
	{
		arr[a] = tmp[a];
	}
}
void mergeSort(int arr[], int left, int right)
{
	int mid;
	int k;
	printf("(arr[], %d, %d) È£Ãâ\n", left, right);
	for (k= left; k < right+1; k++){
		printf("[%d] %d  ", k, arr[k]);
		printf("\n");
	}

	if (left == right){
		mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, right);
	}

	
}

int main()
{
	int arr[SIZE] = { 7,6,5,8,3,5,9,1 };

	mergeSort(arr, 0, SIZE - 1);

	for (int i = 0; i < SIZE;i++)
	{
		printf("%d ", arr[i]);
	}
}
