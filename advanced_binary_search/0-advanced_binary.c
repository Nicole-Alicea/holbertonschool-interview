#include <stdio.h>

/**
 * print_array - Prints the elements of a subarray.
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 *
 * Description: This function prints the elements of the subarray
 * from index `start` to `end`, separated by commas, for visualization
 * during binary search.
 */
void print_array(int *array, size_t start, size_t end)
{
    printf("Searching in array: ");
    for (size_t i = start; i <= end; i++)
    {
        printf("%d", array[i]);
        if (i < end)
            printf(", ");
    }
    printf("\n");
}

/**
 * recursive_binary - Performs a recursive binary search.
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the current search range.
 * @end: Ending index of the current search range.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of `value` if found,
 * or -1 if `value` is not present in the array.
 *
 * Description: This function recursively searches for `value` in the
 * subarray defined by the indices `start` to `end`. It ensures that the
 * first occurrence of `value` is returned when duplicates are present.
 */
int recursive_binary(int *array, size_t start, size_t end, int value)
{
    if (start > end)
        return -1; /* Base case: value not found */

    print_array(array, start, end); /* Print the current subarray */

    size_t mid = start + (end - start) / 2; /* Calculate middle index */

    /* Check if the middle element is the target value */
    if (array[mid] == value)
    {
        /* Check if it is the first occurrence */
        if (mid == start || array[mid - 1] != value)
        {
            return mid;
        }
        /* Otherwise, continue searching in the left subarray */
        return recursive_binary(array, start, mid - 1, value);
    }

    else if (array[mid] > value)
    {
        /* Search in the left subarray */
        return recursive_binary(array, start, mid - 1, value);
    }

    else
    {
        /* Search in the right subarray */
        return recursive_binary(array, mid + 1, end, value);
    }
}

/**
 * advanced_binary - Searches for the first occurrence of a value in a sorted array.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of `value` if found,
 * or -1 if `value` is not present in the array or if `array` is NULL.
 *
 * Description: This function performs a binary search using recursion
 * to locate the first occurrence of `value` in the array. It ensures
 * that each subarray being searched is printed for debugging purposes.
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array || size == 0)
        return -1; /* Handle edge cases where the array is NULL or empty */

    /* Call the recursive binary search function */
    return recursive_binary(array, 0, size - 1, value);
}
