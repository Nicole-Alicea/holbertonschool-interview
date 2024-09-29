#include "sandpiles.h"

/**
 * p - Prints a 3x3 grid of integers.
 * @grid: A 3x3 array representing the grid to be printed.
 *
 * Description: This function prints the values of a 3x3 grid of integers
 *              in a matrix format, with a space between each element in
 *              a row and a newline after each row.
 *
 * Return: Nothing (void).
 */

void p(int grid[3][3])
{
    int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - Computes the sum of two 3x3 sandpile grids.
 * @grid1: A 3x3 array representing the first sandpile grid.
 * @grid2: A 3x3 array representing the second sandpile grid.
 *
 * Description: This function adds two 3x3 sandpile grids element-wise.
 *              If any element in the result exceeds or equals 4, the grid
 *              "topples" by redistributing the values to its neighboring
 *              cells until all elements are less than 4. The function
 *              recursively topples the grid as necessary, printing each
 *              intermediate state after toppling begins.
 *
 *              The function follows the rules of the "sandpile" mathematical
 *              model, where each grid element represents a pile of sand
 *              grains.
 *              When any pile contains 4 or more grains, it topples by
 *              distributing grains to its neighbors.
 *
 * Return: Nothing (void).
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, count = 0;
	int grid3[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int grid4[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] < 4)
				count++;
		}
	if (count != 9)
	{
		printf("=\n");
		p(grid1);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (grid1[i][j] >= 4)
				{
					grid3[i][j] += grid1[i][j] - 4;
					if ((i - 1) >= 0 && (i - 1) < 3)
						grid3[i - 1][j] += 1;
					if ((i + 1) >= 0 && (i + 1) < 3)
						grid3[i + 1][j] += 1;
					if ((j - 1) >= 0 && (j - 1) < 3)
						grid3[i][j - 1] += 1;
					if ((j + 1) >= 0 && (j + 1) < 3)
						grid3[i][j + 1] += 1;
				}
				else
					grid3[i][j] += grid1[i][j];
		sandpiles_sum(grid3, grid4);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid1[i][j] = grid3[i][j];
	}
}