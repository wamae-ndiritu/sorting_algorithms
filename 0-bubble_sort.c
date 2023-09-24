#include "sort.h"

/**
 * bubble_sort - Sorts an arrau of integers in ASC order
 * using Bubble sort algorithm
 *
 * @array: point to an array of integers
 * @size: size of the array
 *
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			int temp;

			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
