#include "sort.h"

/**
 * merge - merging left and right
 * @array: The array to be sorted
 * @left: left char
 * @left_size: size of the left;
 * @right: right char
 * @right_size: Number of elements in the array
 * Return: sorted array
 */
int merge(int *array, int *left, int left_size, int *right, int right_size)
{
	int i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < left_size)
	{
		array[k++] = left[i++];
	}
	while (j < right_size)
	{
		array[k++] = right[j++];
	}
	return (*array);
}

/**
 * merge_sort - sorts an array of ints in asc order using Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	size_t mid = size / 2;
	int *left = (int *)malloc(mid * sizeof(int));
	int *right = (int *)malloc((size - mid) * sizeof(int));

	if (left == NULL || right == NULL)
	{
		free(left);
		free(right);
		return;
	}
	if (size <= 1)
	{
		return;
	}
	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(right, size - mid);
	merge(array, left, mid, right, size - mid);
	printf("[Done]: ");
	print_array(array, size);
	free(left);
	free(right);
}
