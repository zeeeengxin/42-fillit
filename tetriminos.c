#include "fillit.h"

static void		valid_helper(t_piece tet, int row, int col, int *count)
{
	int	c;

	c = *count;
	if ((row - 1) >= 0 && tet.shape[row - 1][col] == BLOCK)
		c++;
	if ((row + 1) <= 3 && tet.shape[row + 1][col] == BLOCK)
		c++;
	if ((col - 1) >= 0 && tet.shape[row][col - 1] == BLOCK)
		c++;
	if ((col + 1) <= 3 && tet.shape[row][col + 1] == BLOCK)
		c++;
	*count = c;
}


static int		valid_tet(t_piece tet, int count, int block)
{
	int i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			if (tet.shape[i][j] == BLOCK)
			{
				valid_helper(tet, i, j, &count);
				block++;
			}
		}
	}
	if ((count == 6 || count == 8) && block == 4)
		return (1);
	return (0);
}

static int		create_tet(char **buff, t_piece *tet)
{
	int	i;
	int	j;
	char *str;

	str = *buff;
	i = 0;
	while (i < SIZE && (*str))
	{
		j = 0;
		while (j < SIZE && (*str))
		{
			if (*str != BLOCK && *str != EMPTY)
				return (0);
			tet->shape[i][j] = *str;
			str++;
			j++;
		}
		if (*str != '\n')
			return (0);
		str++;
		i++;
	}
	*buff = str;
	return (1);
}

int 			ft_tet(char *buff, t_piece *tet)
{
	int i;
	int count;
	int block;

	i = 0; // to remember how many pieces we create
	count = 0;
	block = 0;
	while (*buff && i < MAX_PIECES)
	{
		if(!create_tet(&buff, &tet[i]))
			return (0); // from buff to pieces, also check \n and character '#''.'
		if (!(valid_tet(tet[i], count, block)))
			return (0); // validate each piece
		if (*buff == '\0' || (*buff == '\n' && *(buff + 1) != '\0'))
		{
			if (*buff == '\n')
				buff++;
			tet[i].name = i + 'A'; //set up name
		}
		else
			return (0);
		i++;
	}
	return (i);
}