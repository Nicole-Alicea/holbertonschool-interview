#include "holberton.h"

/**
 * is_error - Validates input arguments.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Description:
 * This function checks if the program receives exactly two arguments,
 * and if those arguments contain only numeric characters. If any of
 * these conditions fail, the function prints "Error" and exits the program
 * with a status of 98.
 *
 * Return: 0 on success (if all checks pass).
 */
int is_error(int argc, char **argv)
{
	int i, j;

	if (argc != 3)  /* Ensure exactly two arguments are provided */
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 1; i < argc; i++)  /* Validate each argument */
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')  /* Check if non-numeric */
			{
				printf("Error\n");
				exit(98);
			}
		}
	}

	return (0);  /* Return success if all checks pass */
}

/**
 * main - Entry point for the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Description:
 * This program multiplies two large positive integers provided as command-line
 * arguments. The multiplication is implemented manually using arrays to store
 * intermediate results, making it capable of handling integers larger than the
 * range supported by primitive types (e.g., `int` or `long`).
 *
 * Return:
 * - EXIT_SUCCESS (0) on successful completion.
 * - EXIT_FAILURE (1) if memory allocation for the result array fails.
 */
int main(int argc, char **argv)
{
	int len1, len2, carry, a, b, i, j;
	int *result;

	/* Validate input arguments */
	is_error(argc, argv);

	/* Calculate the lengths of the input strings */
	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);

	/* Handle edge case where any argument is "0" */
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		printf("0\n");
		return (EXIT_SUCCESS);
	}

	/* Allocate memory for the result array (initialized to 0) */
	result = calloc(len1 + len2, sizeof(*result));
	if (!result)  /* Check for memory allocation failure */
		return (EXIT_FAILURE);

	/* Perform multiplication digit-by-digit */
	for (i = len1 - 1; i >= 0; i--)
	{
    	carry = 0;
    	a = argv[1][i] - '0';  /* Convert char to int */
    	for (j = len2 - 1; j >= 0; j--)
		{
			b = argv[2][j] - '0';  /* Convert char to int */
			carry += result[i + j + 1] + (a * b);  /* Add product and carry */
			result[j + i + 1] = carry % 10;  /* Store the least significant digit */
			carry /= 10;  /* Update carry with the most significant digit */
		}
		if (carry > 0)
			result[i + j + 1] += carry;  /* Add remaining carry */
	}

	/* Skip leading zeros in the result array */
	a = result[0] == 0 ? 1 : 0;

	/* Print the final result */
	for (; a < len1 + len2; a++)
		printf("%d", result[a]);
	printf("\n");

	/* Free allocated memory */
	free(result);

	return (EXIT_SUCCESS);
}
