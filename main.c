/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 03:21:25 by tlynesse          #+#    #+#             */
/*   Updated: 2019/11/05 15:24:54 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	ft_px_put(t_mlx *mlx, t_point point, int color)
{
	if (point.x >= 0 && point.x < WIN_WIDTH &&
	point.y >= 0 && point.y < WIN_HIEGHT)
		mlx->data[point.x + point.y * WIN_WIDTH] = color;
		// *(unsigned int*)(mlx->data + point.x * mlx->bpp
		// + point.y * mlx->sl) = color;
}
/* 
void	fill_color(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->max.y)
	{
		j = 0;
		while (j < mlx->max.x)
		{
			*(mlx->data + j + i * WIN_WIDTH) = mlx->min_color + (mlx->max.color - mlx->min_color) * mlx->field[i][j].z / mlx->max.z;
			j++;
		}
		i++;
	}
}
 */
void	draw_line(t_mlx *mlx, void *win_ptr, t_line line)
{
	const int	signX = line.a.x < line.b.x ? 1 : -1;
	const int	signY = line.a.y < line.b.y ? 1 : -1;
	t_point		tmp;
	t_point		delta;

	(void)*win_ptr;
	int error;

	tmp.x = line.a.x;
	tmp.y = line.a.y;
	tmp.z = line.a.z;
	tmp.color = line.a.color;
	delta.x = ft_abs(line.b.x - line.a.x);
	delta.y = ft_abs(line.b.y - line.a.y);
	delta.z = ft_abs(line.b.z - line.a.z);
	delta.color = ft_abs(line.b.color - line.a.color);
	error = delta.x - delta.y;
	fill_color(mlx);
	while(tmp.x != line.b.x || tmp.y != line.b.y)
	{
		//mlx_pixel_put(mlx->mlx, win_ptr, tmp.x * 5 + 500, tmp.y * 5 + 500, 0xFFFFFF/*get_color(tmp, line.a, line.b, delta)*/);
		ft_px_put(mlx, tmp, get_color(tmp, line.a, line.b, delta));
		if(error * 2 > -delta.y)
		{
			error -= delta.y;
			tmp.x += signX;
		}
		if(error * 2 < delta.x) 
		{
			error += delta.x;
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
	printf("test\n");
	win_ptr = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HIEGHT, "My Window");
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HIEGHT);
	mlx->data = (int *)mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->sl), &(mlx->endn));
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
	mlx_put_image_to_window(mlx->mlx, win_ptr, mlx->img, 0, 0);
	mlx_hook(win_ptr, 2, 0, ft_key_events, mlx->mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
