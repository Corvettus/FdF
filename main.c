#include "minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "fdf.h"

//0,0, 500,1000



double percent(int start, int end, int current)
{
    double placement;
    double distance;
    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_koord current, t_koord start, t_koord end, t_koord delta)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (current.color == end.color)
        return (current.color);
    if (delta.x > delta.y)
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

void	draw_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	const int deltaX = abs(line.k2.x - line.k1.x);
	const int deltaY = abs(line.k2.y - line.k1.y);
	const int signX = line.k1.x < line.k2.x ? 1 : -1;
	const int signY = line.k1.y < line.k2.y ? 1 : -1;
	t_koord   tmp;
	t_koord   delta;

	//
	int error = deltaX - deltaY;
	//
	tmp.x = line.k1.x;
	tmp.y = line.k1.y;
	tmp.z = line.k1.z;
	tmp.color = line.k1.color;
	delta.x = deltaX;
	delta.y = deltaY;
	delta.z = abs(line.k2.z - line.k1.z);
	delta.color = abs(line.k2.color - line.k1.color);
	mlx_pixel_put(mlx_ptr, win_ptr, line.k2.x, line.k2.y, get_color(tmp, line.k1, line.k2, delta));
	while(tmp.x != line.k2.x || tmp.y != line.k2.y) 
	{
		mlx_pixel_put(mlx_ptr, win_ptr, tmp.x, tmp.y, get_color(tmp, line.k1, line.k2, delta));
		const int error2 = error * 2;
		//
		if(error2 > -deltaY) 
		{
			error -= deltaY;
			tmp.x += signX;
		}
		if(error2 < deltaX) 
		{
			error += deltaX;
			tmp.y += signY;
		}
	}
}

void	draw_blue_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	const int deltaX = abs(line.k2.x - line.k1.x);
	const int deltaY = abs(line.k2.y - line.k1.y);
	const int signX = line.k1.x < line.k2.x ? 1 : -1;
	const int signY = line.k1.y < line.k2.y ? 1 : -1;
	//
	int error = deltaX - deltaY;
	//
	mlx_pixel_put(mlx_ptr, win_ptr, line.k2.x, line.k2.y, 0x0000CD);
	while(line.k1.x != line.k2.x || line.k1.y != line.k2.y) 
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.k1.x, line.k1.y, 0x0000CD);
		const int error2 = error * 2;
		//
		if(error2 > -deltaY) 
		{
			error -= deltaY;
			line.k1.x += signX;
		}
		if(error2 < deltaX) 
		{
			error += deltaX;
			line.k1.y += signY;
		}
	}
}

int	connect(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
	int		deltax;
	int		deltay;
	int		error;
	int		deltaerror;
	int		x, y;
	int		diry;

	deltax = ft_abs(x1 - x0); //20
	deltay = ft_abs(y1 - y0); //20
	error = 0;
	deltaerror = deltay; //20
	y = y0; //70
	diry = y1 - y0; //-20
	if (diry > 0)
		diry = 1;
	if (diry < 0)
		diry = -1; //+
	x = x0; //320
	if (x < x1)
	{
		while (x < x1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			error = error + deltaerror;
			if (2 * error >= deltax)
			{
				y = y + diry;
				error = error - deltax;
			}
			x++;
		}
	}
	else if (x > x1)
	{
		while (x > x1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			error = error + deltaerror;
			if (2 * error >= deltax)
			{
				y = y + diry;
				error = error - deltax;
			}
			x--;
		}
	}
	else if (y < y1)
	{
		while (y < y1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			y++;
		}
	}
	else
	{
		while (y > y1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			y--;
		}
	}
	return (0);
}

int	connect_2(void *mlx_ptr, void *win_ptr, double x0, double y0, double x1, double y1)
{
	double	deltax;
	double	deltay;
	double	error;
	double	deltaerror;
	double	x, y;
	double	diry;

	deltax = ft_abs(x1 - x0); //20
	deltay = ft_abs(y1 - y0); //20
	error = 0;
	deltaerror = deltay; //20
	y = y0; //70
	diry = y1 - y0; //-20
	if (diry > 0)
		diry = 1;
	if (diry < 0)
		diry = -1; //+
	x = x0; //320
	if (x < x1)
	{
		while (x < x1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			error = error + deltaerror;
			if (2 * error >= deltax)
			{
				y = y + diry;
				error = error - deltax;
			}
			x++;
		}
	}
	else
	{
		while (x > x1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			error = error + deltaerror;
			if (2 * error >= deltax)
			{
				y = y + diry;
				error = error - deltax;
			}
			x--;
		}
	}
	return (0);
}

void	print_oxoy(void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (i < 2000)
	{
		mlx_string_put(mlx_ptr, win_ptr, i, 10, 0xFFFFFF, ft_itoa(i));
		connect(mlx_ptr, win_ptr, 0, i, 2000, i);
		connect(mlx_ptr, win_ptr, i, 0, i, 2000);
		mlx_string_put(mlx_ptr, win_ptr, 10, i, 0xFFFFFF, ft_itoa(i));
		i += 100;
	}
	connect(mlx_ptr, win_ptr, 0, 0, 2000, 0);
	connect(mlx_ptr, win_ptr, 0, 0, 0, 2000);
	//connect(mlx_ptr, win_ptr, 320, 70, 300, 90);
	//connect(mlx_ptr, win_ptr, 100, 200, 500, 200);
}

void	print_map(void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (i < 11)
	{
		connect(mlx_ptr, win_ptr, 300 - (i * 20), 50 + (i * 20), 660 - (i * 20), 410 + (i * 20));
		i++;
	}
	i = 0;
	while (i < 19)
	{
		connect(mlx_ptr, win_ptr, 300 + (i * 20), 50 + (i * 20), 100 + (i * 20), 250 + (i * 20));
		i++;
	}
	//connect(mlx_ptr, win_ptr, 300, 50, 280, 70);
	//connect(mlx_ptr, win_ptr, 280, 70, 300, 90);
	//connect(mlx_ptr, win_ptr, 320, 70, 300, 90);
	//connect(mlx_ptr, win_ptr, 100, 200, 500, 200);
}

void	move_all_left(t_koord **vertex, void *mlx_ptr, void *win_ptr, int len_i, int len_j, int mode)
{
	int		i;
	int		j;
	t_line	line;
	int		prev_x1;
	int		prev_x2;
	int		prev_y1;
	int		prev_y2;

	mlx_clear_window(mlx_ptr, win_ptr);
	i = 0;
	while (i < len_i)
	{
		j = 0;
		while (j < len_j)
		{
			if (j < len_j - 1)
			{
				line.k1 = vertex[i][j];
				line.k2 = vertex[i][j + 1];
				prev_x1 = line.k1.x;
				prev_x2 = line.k2.x;
				prev_y1 = line.k1.y;
				prev_y2 = line.k2.y;
				if (mode == 1)
				{
					line.k1.x = (prev_x1 - prev_y1) * cos(0.523599);
					line.k1.y = (prev_x1 + prev_y1) * sin(0.523599) - line.k1.z;
					line.k2.x = (prev_x2 - prev_y2) * cos(0.523599);
					line.k2.y = (prev_x2 + prev_y2) * sin(0.523599) - line.k2.z;
				}
/* 				line.k1.x += 500;
				line.k1.y += 500;
				line.k2.x += 500;
				line.k2.y += 500; */
//				if (line.k1.z == line.k2.z && line.k1.z == 30)
//					draw_blue_line(mlx_ptr, win_ptr, line);
//				else
				draw_line(mlx_ptr, win_ptr, line);
			}
			if (i < len_i - 1)
			{
				line.k1 = vertex[i][j];
				line.k2 = vertex[i + 1][j];
				prev_x1 = line.k1.x;
				prev_x2 = line.k2.x;
				prev_y1 = line.k1.y;
				prev_y2 = line.k2.y;
				if (mode == 1)
				{
 					line.k1.x = (prev_x1 - prev_y1) * cos(0.523599);
					line.k1.y = (prev_x1 + prev_y1) * sin(0.523599) - line.k1.z;
					line.k2.x = (prev_x2 - prev_y2) * cos(0.523599);
					line.k2.y = (prev_x2 + prev_y2) * sin(0.523599) - line.k2.z;
				}
/* 				line.k1.x += 500;
				line.k1.y += 500;
				line.k2.x += 500;
				line.k2.y += 500; */
//				if (line.k1.z == line.k2.z && line.k1.z == 30)
//					draw_blue_line(mlx_ptr, win_ptr, line);
//				else
				draw_line(mlx_ptr, win_ptr, line);
			}
			j++;
		}
		i++;
	}
}

int ft_key_events(int key, t_mlx *mlx)
{
	if (key == 53 || key == 49)
		exit(EXIT_SUCCESS);
	else if (key == 1 || key == 126)
	{
		//up
	}
	else if (key == 0 || key == 123)
	{
		// left
	}
	else if (key == 1 || key == 125)
	{
		// down
	}
	else if (key == 2 || key == 124)
	{
		// right
	}
	else if (key == 12)
	{
		// down gradient
	}
	else if (key == 14)
	{
		// up gradient
	}
	else if (key == 36 || key == 76)
	{
		// isometr
	}
    return (0);
}



int ft_mouse_events(int button, int x, int y, t_mlx *mlx)
{
	
	return (0);
}

/* int ft_rotate_keys(int key, void *mlx)
{
    (void)mlx;
	if (key == 126)
	{
		// OX up
	}
	else if (key == 123)
	{
		// OY left
	}
	else if (key == 125)
	{
		// OX down
	}
	else if (key == 124)
	{
		// OY right
	}
    exit(0);
} */

int	main(int argc, char **argv)
{
	int		deltax;
	int		deltay;
	int		error;
	int		deltaerror;
	int		x1, x0, y1, y0, x, y;
	int		diry;
	void	*mlx_ptr, *win_ptr, *param;
	int		max_z;
	
	int tmp;

	int i;
	int	j;
	int	len_i;
	int	len_j;
	t_line	line;
	int	prev_x1;
	int	prev_x2;
	int	prev_y1;
	int	prev_y2;
	int	**matrica;
	t_koord	**vertex;
	t_return_read_file	ret;
	int mode;

	if (argc != 2)
		return (0);
	mode = 1;
	// ВЫВОД МАТРИЦЫ
	ret = read_file(argc, argv);
	matrica = ret.matr;
	len_i = ret.ret_i;
	len_j = ret.ret_j;
	/* i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 19)
		{
			ft_putnbr(matrica[i][j]);
			if (matrica[i][j] == 0)
				ft_putchar(' ');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	} */
	vertex = make_field(len_i, len_j, matrica, &max_z);
	fill_color(len_i, len_j, vertex, max_z, 0x00000A, 0xA00000);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HIEGHT, "My Window");
	//mlx_new_image(mlx_ptr, 500, 500);
	//printf("%f\n", cos(60 * (M_PI / 180)));
	print_oxoy(mlx_ptr, win_ptr);
	i = 0;
	while (i < len_i)
	{
		j = 0;
		while (j < len_j)
		{
			if (j < len_j - 1)
			{
				line.k1 = vertex[i][j];
				line.k2 = vertex[i][j + 1];
				prev_x1 = line.k1.x;
				prev_x2 = line.k2.x;
				prev_y1 = line.k1.y;
				prev_y2 = line.k2.y;
				if (mode == 1)
				{
					line.k1.x = (prev_x1 - prev_y1) * cos(0.523599);
					line.k1.y = (prev_x1 + prev_y1) * sin(0.523599) - line.k1.z;
					line.k2.x = (prev_x2 - prev_y2) * cos(0.523599);
					line.k2.y = (prev_x2 + prev_y2) * sin(0.523599) - line.k2.z;
				}
/* 				line.k1.x += 500;
				line.k1.y += 500;
				line.k2.x += 500;
				line.k2.y += 500; */
//				if (line.k1.z == line.k2.z && line.k1.z == 30)
//					draw_blue_line(mlx_ptr, win_ptr, line);
//				else
				draw_line(mlx_ptr, win_ptr, line);
			}
			if (i < len_i - 1)
			{
				line.k1 = vertex[i][j];
				line.k2 = vertex[i + 1][j];
				prev_x1 = line.k1.x;
				prev_x2 = line.k2.x;
				prev_y1 = line.k1.y;
				prev_y2 = line.k2.y;
				if (mode == 1)
				{
 					line.k1.x = (prev_x1 - prev_y1) * cos(0.523599);
					line.k1.y = (prev_x1 + prev_y1) * sin(0.523599) - line.k1.z;
					line.k2.x = (prev_x2 - prev_y2) * cos(0.523599);
					line.k2.y = (prev_x2 + prev_y2) * sin(0.523599) - line.k2.z;
				}
/* 				line.k1.x += 500;
				line.k1.y += 500;
				line.k2.x += 500;
				line.k2.y += 500; */
//				if (line.k1.z == line.k2.z && line.k1.z == 30)
//					draw_blue_line(mlx_ptr, win_ptr, line);
//				else
				draw_line(mlx_ptr, win_ptr, line);
			}
			j++;
		}
		i++;
	}
	mlx_hook(win_ptr, 2, 0, ft_key_events, mlx_ptr);
	mlx_hook(win_ptr, 4, 0, ft_mouse_events, mlx_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
