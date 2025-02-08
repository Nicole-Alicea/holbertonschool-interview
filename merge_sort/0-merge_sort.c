#include "sort.h"

/**
 * merge - Merges two subarrays of an array during merge sort.
 * @array: The array to be sorted.
 * @size: The total size of the array.
 * @m: The middle index, dividing the left and right subarrays.
 * @temp: A temporary array used for merging.
 *
 * Description: This function merges two sorted halves of an array into a
 * single sorted subarray. It prints the left and right subarrays before
 * merging and the final merged result.
 */
void merge(int *array, int size, int m, int *temp)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, m);
	printf("[right]: ");
	print_array(array + m, size - m);

	for (i = 0, j = m, k = 0; k < size; k++)
	{
		if (j == size)
			temp[k] = array[i++];
		else if (i == m)
			temp[k] = array[j++];
		else if (array[j] < array[i])
			temp[k] = array[j++];
		else
			temp[k] = array[i++];
	}

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(temp, size);
}

/**
 * merge_main - Recursively splits and merges an array using merge sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @temp: A temporary array used for merging.
 *
 * Description: This function recursively divides the array into two halves,
 * sorts them using merge sort, and then merges them back together.
 */
void merge_main(int *array, size_t size, int *temp)
{
	int m;

	if (size < 2)
		return;

	m = size / 2;
	merge_main(array, m, temp);
	merge_main(array + m, size - m, temp);
	merge(array, size, m, temp);
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function initializes a temporary array, calls the
 * recursive merge_main function to perform sorting, and then frees the
 * temporary array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_main(array, size, temp);
	free(temp);
}
