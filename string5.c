#include "main.h"

/**
 * free_grid - frees the grid gven as an input
 * @grid: the grid to free
 *
 * Return: void
 */

void free_grid(char **grid)
{
	int height = 0, i;

	if (!grid)
	{
		return;
	}
	for (i = 0; grid[i]; i++)
		height++;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
