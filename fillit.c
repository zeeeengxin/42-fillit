#include "fillit.h"

#include <stdio.h> // for testing

 static void print_board(int size)
{
	int i;
	int j;

	i = 0;
	while (i < size && i < MAX_BOARD)
	{
		j = 0;
		while (j < size && j < MAX_BOARD)
		{
			write(1, &g_board[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

static void	init_board(int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			g_board[i][j] = EMPTY;
			j++;
		}
		i++;
	}
}

void		ft_fillit(t_piece *tet)
{
	int		size;
	int     min;
	int     max;

	min = MIN_SQR;
	max = SIZE * g_nb;
	init_board(max);
	if (ft_fill_board(tet, min, 0))
	{
		print_board(min);
		return;
	}
	while (max - min > 1)
	{
		size = (max + min) / 2;
		init_board(size);
		if (ft_fill_board(tet, size, 0))
				max = size;
		else
				min = size;
	}
	init_board(max);
	ft_fill_board(tet, max, 0);
	print_board(max);
}