#include "sort.h"

/**
* swap - Swaps two integers
* @a: First integer
* @b: Second integer
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
* lomuto_partition - Partitions the array using Lomuto scheme
* @array: The array
* @low: Starting index
* @high: Ending index
* @size: Size of the array (for printing)
*
* Return: The pivot index
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}

/**
* quicksort_recursive - Recursively applies quick sort
* @array: The array to be sorted
* @low: Starting index
* @high: Ending index
* @size: Size of the array
*/
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quicksort_recursive(array, low, pi - 1, size);
		quicksort_recursive(array, pi + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using
*				the Quick sort algorithm (Lomuto partition scheme)
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
