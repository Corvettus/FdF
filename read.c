# include "fdf.h"
# include "get_next_line.h"
#include <fcntl.h>

t_return_read_file	read_file(int argc, char **argv)
{
	t_return_read_file	ret;
	int		fd;
	char	*line;
	int		i;
	int		j;
	int		k;
	int		**table;
	int		ret_i;
	int		ret_j;

	fd = open(argv[1], 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		j = 0;
		k = 0;
		while (line[j])
		{
			k++;
			while (line[j] && line[j] != ' ')
				j++;
			while (line[j] && line[j] == ' ')
				j++;
		}
		i++;
	}
	ret_i = i;
	ret_j = k;
	table = (int **)malloc(sizeof(int *) * ret_i);
	i = -1;
	while (++i < ret_i)
		table[i] = (int *)malloc(sizeof(int) * ret_j);
	i = 0;
	fd = open(argv[1], 0);
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		j = 0;
		k = 0;
		while (line[j])
		{
			table[i][k] = ft_atoi(&line[j]);
			k++;
			while (line[j] && line[j] != ' ')
				j++;
			while (line[j] && line[j] == ' ')
				j++;
		}
		i++;
		print_error;
	}
	/* *matr = (int **)malloc(sizeof(int *) * 11);
	i = -1;
	while (++i < 11)
		*matr[i] = (int *)malloc(sizeof(int) * 19);
	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 19)
		{
			*matr[i][j] = table[i][j];
			j++;
		}
		i++;
	}


	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 19)
		{
			ft_putnbr(*matr[i][j]);
			if (*matr[i][j] == 0)
				ft_putchar(' ');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}*/
	close(fd);
	ret.matr = table;
	ret.ret_i = ret_i;
	ret.ret_j = ret_j;
	return (ret);
}