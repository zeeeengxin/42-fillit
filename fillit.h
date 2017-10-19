#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define SIZE 4
# define MAX_PIECES 26
# define MAX_FILE_SIZE 550 // maximum size is actually 26 * 21 + 1 (\0) = 547
# define MIN_SQR 2
# define BLOCK '#'
# define EMPTY '.'
# define MAX_BOARD 104
# define FLOOD '@'

int		g_nb;
char	g_board[MAX_BOARD][MAX_BOARD];

typedef struct		s_piece
{
	char			name;
	char			shape[4][4];
}					t_piece;


int		ft_tet(char *buff, t_piece *tet);
void	ft_fillit(t_piece *tet);
int		ft_fill_board(t_piece *tet, int size, int index);

int waste_too_many(int size, int need, int ocupied);



void	ft_putstr(char const *s);
void	ft_bzero(void *s, size_t n);


#endif