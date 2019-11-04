# include "fdf.h"

t_mlx	*read_file(int ac, char **av)
{
	t_mlx	*ret;
	int		fd;
	char	*line;
	int		i;
	int		j;
	int		prev_k;
	int		k;
	int		gnl_ret;

	if ((ret = (t_mlx*)malloc(sizeof(t_mlx))) == NULL ||
	(ret = (void*)malloc(sizeof(void))) == NULL)
		return (free_mlx_ptr(&ret));
	fd = open(av[1], 0);
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
	ret->max.y = i;
	ret->max.x = k;
	if ((ret->field = (t_point**)malloc(sizeof(t_point*) * ret->max.y)) == NULL)
		return (free_mlx_ptr(&ret));
	i = -1;
	while (++i < ret->max.y)
		if ((ret->field[i] = (t_point*)malloc(sizeof(t_point) * ret->max.x)) == NULL)
			return (free_mlx_ptr(&ret));
	i = 0;
	fd = open(av[1], 0);
	while ((gnl_ret = get_next_line(fd, &line)) > 0)
	{
		j = 0;
		k = 0;
		while (line[j])
		{
			ret->field[i][k].z = ft_atoi(&line[j]);
			k++;
			while (line[j] && line[j] != ' ')
				j++;
			while (line[j] && line[j] == ' ')
				j++;
		}
		i++;
	}
	if (gnl_ret == -1)
	{
		ft_putendl("Reading ERROR!");
		return (free_mlx_ptr(&ret));
	}
	if (ft_strequ(av[2], "0"))
		ret->mode = 0;
	else if (ft_strequ(av[2], "1"))
		ret->mode = 1;
	else
	{
		ft_putendl("ARGS ERROR!");
		return (free_mlx_ptr(&ret));
	}
	close(fd);
	return (ret);
}