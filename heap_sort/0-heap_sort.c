#include "sort.h"

/**
 * sift_down - Restores the max heap property by sifting down an element
 * 
 * @array: The array to be heapified
 * @size: Total size of the array (used for printing)
 * @root: The index of the root node of the subtree to sift down
 * @end: The last index of the current heap
 *
 * This function ensures that the subtree rooted at @root maintains
 * the max heap property, where the parent node is greater than or equal
 * to its child nodes. If a swap is performed, the function recurses
 * to continue restoring the heap property.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t largest = root;
    size_t left_child = 2 * root + 1;
    size_t right_child = 2 * root + 2;

    /* Check if left child exists and is greater than the root */
    if (left_child <= end && array[left_child] > array[largest])
        largest = left_child;

    /* Check if right child exists and is greater than the largest so far */
    if (right_child <= end && array[right_child] > array[largest])
        largest = right_child;

    /* Swap if the largest is not the root */
    if (largest != root)
    {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        /* Print the array after each swap */
        print_array(array, size);

        /* Recursively sift down the affected subtree */
        sift_down(array, size, largest, end);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort
 * 
 * @array: Pointer to the array of integers
 * @size: Number of elements in the array
 *
 * This function first builds a max heap from the input array. Then it
 * repeatedly extracts the largest element (at the root of the heap) and places
 * it at the end of the array, reducing the heap size. After each swap,
 * the heap property is restored by calling sift_down. The array is printed
 * after each swap.
 */
void heap_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    /* Build the max heap by sifting down non-leaf nodes */
    for (ssize_t i = (size / 2) - 1; i >= 0; i--)
        sift_down(array, size, i, size - 1);

    /* Perform heap sort */
    for (ssize_t end = size - 1; end > 0; end--)
    {
        /* Swap the root of the heap (max element) with the last element */
        int temp = array[0];
        array[0] = array[end];
        array[end] = temp;

        /* Print the array after each swap */
        print_array(array, size);

        /* Restore the heap property for the reduced heap */
        sift_down(array, size, 0, end - 1);
    }
}
