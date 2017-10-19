#include "fillit.h"

void flood_fill(int x, int y, int size, int *flood)
{
	if (x < 0 || y < 0 || x >= size || y >= size)
		return;
	if (g_board[x][y] != EMPTY)
		return;
	g_board[x][y] = FLOOD;
	(*flood)++;
	flood_fill(x - 1, y, size, flood);
	flood_fill(x + 1, y, size, flood);
	flood_fill(x, y - 1, size, flood);
	flood_fill(x, y + 1, size, flood);
}

void recover_board(int size)
{
	int x;
	int y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (g_board[x][y] == FLOOD)
				g_board[x][y] = EMPTY;
			y++;
		}
		x++;
	}
}

int waste_too_many(int size, int need, int ocupied)
{
	int	waste;
	int x;
	int y;
	int flood;

	x = 0;
	waste = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			flood = 0;
			if (g_board[x][y] == EMPTY)
			{
				flood_fill(x, y, size, &flood);
				waste += flood % 4;
				if (need > size * size - ocupied - waste)
				{
					recover_board(size);
					return (1);
				}
			}
			y++;
		}
		x++;
	}
	recover_board(size);
	return (0);
}
