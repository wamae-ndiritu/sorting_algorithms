#include "sort.h"

/**
 * selection_sort - sorts items in the ASC order
 * using the Selection sort algorithm
 *
 * @array: pointer to an array of integers
 * @size: size of the array
 *
 * Return: Nothing.
 */


void selection_sort(int *array, size_t size)
{
	int min_val;
	size_t i, j, min_index;

	for (i = 0; i < size; i++)
	{
		int temp;

		min_val = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (min_val > array[j])
			{
				min_index = j;
				min_val = array[j];
			}
		}
		if (array[i] != min_val)
		{
			temp = array[i];
			array[i] = min_val;
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
