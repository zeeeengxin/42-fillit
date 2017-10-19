#include "fillit.h"

int	main(int argc, char **argv)
{
	t_piece		tet[MAX_PIECES];
	char		buff[MAX_FILE_SIZE];
	int			fd;
	int			ret;

	g_nb = 0;
	ft_bzero(buff, MAX_FILE_SIZE);
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1 ||
			(ret = read(fd, buff, MAX_FILE_SIZE)) <= 0 ||
			!(g_nb = ft_tet(buff, tet))) //store everything in a string, and then create each piece
				ft_putstr("error\n");
		else
			ft_fillit(tet); // the main function to calculate min sqr
		if (fd != -1)
			close(fd);
	}
	else
		ft_putstr("usage: ./fillit [file]\n");
	return (0);
}