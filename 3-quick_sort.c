#include "sort.h"

/**
 * swap_items - Swaps items at different indeces
 *
 * @a: pointer to the element at index
 * @b: pointer to the other element at another index
 *
 * Return: Nothing.
 */

void swap_items(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partition the elements using
 * the Lomuto Partition Scheme
 *
 * @array: pointer to the array to be partitioned
 * @low: The starting of subarray to be partitioned
 * @high: The ending of the subarray to be
 * partitioned
 *
 * Return: returns the index of the pivot element
 */

size_t lomuto_partition(int *array, size_t low, size_t high)
{
	int pivot = array[high];
	size_t i, j;

	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_items(&array[i], &array[j]);
		}
	}

	swap_items(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort - Sorts an array of integers in
 * the ASC order using the Quick Sort algorithm
 *
 * @array: pointer to an array of integers to be sorted
 * size: the size of the array to be sorted
 *
 * Return: Nothing.
 */

void quick_sort(int *array, size_t size)
{
	size_t pivotIndex = lomuto_partition(array, 0, size - 1);

	printf("Pivot Index: %ld\n", pivotIndex);
	print_array(array, size);

	if (pivotIndex > 0)
		quick_sort(array, pivotIndex);
	if (pivotIndex < size - 1)
	{
		quick_sort(array + pivotIndex + 1, size - pivotIndex - 1);
	}
}
