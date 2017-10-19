#include "fillit.h"

#include <stdio.h> // for testing

static int	test_piece(t_piece tet, int size, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (tet.shape[i][j] == BLOCK)
			{
				if (g_board[i + row][j + col] != EMPTY ||
					i + row < 0 || i + row >= size ||
					j + col < 0 || j + col >= size)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void	insert_piece(t_piece tet, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (tet.shape[i][j] == BLOCK)
			{
				g_board[i + row][j + col] = tet.name;
			}
			j++;
		}
		i++;
	}
}

static void	remove_piece(t_piece tet, int size, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if ((i + row >= 0 && i + row < size &&
				j + col >= 0 && j + col < size) &&
				g_board[i + row][j + col] == tet.name)
				{
					g_board[i + row][j + col] = EMPTY;
				}
			j++;
		}
		i++;
	}
}

int			ft_fill_board(t_piece *tet, int size, int index)
{
	int row;
	int col;

	row = -3;
	if (index == g_nb)
		return (1);
	while (row < size)
	{
		col = -3;
		while (col < size)
		{
			//printf("test (%d, %d)\n", row, col);//test

			if (test_piece(tet[index], size, row, col))
			{	
				//printf("test piece [%d] success at (%d, %d)\n", index, row, col);
				insert_piece(tet[index], row, col);
				
				if (!waste_too_many(size, (g_nb - index - 1) * 4, (1 + index) * 4))
				{
					if (ft_fill_board(tet, size, (index + 1)))
						return (1);
				}
				remove_piece(tet[index], size, row, col);
			}
			col++;
		}
		row++;
	}
	return (0);
}