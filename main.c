# include "fdf.h"

void	draw_line(t_mlx *mlx, void *win_ptr, t_line line)
{
	const int	deltaX = abs(line.b.x - line.a.x);
	const int	deltaY = abs(line.b.y - line.a.y);
	const int	signX = line.a.x < line.b.x ? 1 : -1;
	const int	signY = line.a.y < line.b.y ? 1 : -1;
	t_point		tmp;
	t_point		delta;

	int error = deltaX - deltaY;
	tmp.x = line.a.x;
	tmp.y = line.a.y;
	tmp.z = line.a.z;
	tmp.color = line.a.color;
	delta.x = deltaX;
	delta.y = deltaY;
	delta.z = abs(line.b.z - line.a.z);
	delta.color = abs(line.b.color - line.a.color);
	fill_color(mlx);
	while(tmp.x != line.b.x || tmp.y != line.b.y) 
	{
		mlx_pixel_put(mlx->mlx, win_ptr, tmp.x, tmp.y, get_color(tmp, line.a, line.b, delta));
		if(error * 2 > -deltaY) 
		{
			error -= deltaY;
			tmp.x += signX;
		}
		if(error * 2 < deltaX) 
		{
			error += deltaX;
			tmp.y += signY;
		}
	}
}

void	iso_lines(t_line *line)
{	
	int		prev_x1;
	int		prev_x2;
	int		prev_y1;
	int		prev_y2;

	prev_x1 = line->a.x;
	prev_x2 = line->b.x;
	prev_y1 = line->a.y;
	prev_y2 = line->b.y;
 	line->a.x = (prev_x1 - prev_y1) * cos(0.523599);
	line->b.y = (prev_x1 + prev_y1) * sin(0.523599) - line->a.z;
	line->a.x = (prev_x2 - prev_y2) * cos(0.523599);
	line->b.y = (prev_x2 + prev_y2) * sin(0.523599) - line->b.z;
}
/* 
void	ft_draw_pic(t_mlx *mlx, void *win_ptr, t_line line)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->max.y)
	{
		j = 0;
		while (j < mlx->max.x)
		{
			if (j < mlx->max.x - 1)
			{
				line.a = mlx->field[i][j];
				line.b = mlx->field[i][j + 1];
				if (mlx->mode == 1)
					iso_lines(&line);
				draw_line(mlx->mlx, win_ptr, line);
			}
			if (i < mlx->max.y - 1)
			{
				line.a = mlx->field[i][j];
				line.b = mlx->field[i + 1][j];
				if (mlx->mode == 1)
					iso_lines(&line);
				draw_line(mlx->mlx, win_ptr, line);
			}
			*j++;
		}
		i++;
	}
}
 */
int		ft_key_events(int key, t_mlx *mlx)
{
	if (key == 53 || key == 49)
		exit(EXIT_SUCCESS);
	return (0);
}

int		main(int ac, char **av)
{
	void	*win_ptr;
	t_mlx	*mlx;
	int		i;
	int		j;
	t_line	line;

	if (ac != 3)
		return (0);
	mlx = read_file(ac, av);
	mlx->mlx = mlx_init();
	win_ptr = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HIEGHT, "My Window");
	i = -1;
	while (++i < mlx->max.y)
	{
		j = -1;
		while (++j < mlx->max.x)
		{
			if (j < mlx->max.x - 1)
			{
				line.a = mlx->field[i][j];
				line.b = mlx->field[i][j + 1];
				if (mlx->mode == 1)
					iso_lines(&line);
				draw_line(mlx->mlx, win_ptr, line);
			}
			if (i < mlx->max.y - 1)
			{
				line.a = mlx->field[i][j];
				line.b = mlx->field[i + 1][j];
				if (mlx->mode == 1)
					iso_lines(&line);
				draw_line(mlx->mlx, win_ptr, line);
			}
		}
	}
	mlx_hook(win_ptr, 2, 0, ft_key_events, mlx->mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
