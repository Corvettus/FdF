#include "minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>
# include "fdf.h"

//0,0, 500,1000

void	draw_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	const int deltaX = abs(line.k2.x - line.k1.x);
	const int deltaY = abs(line.k2.y - line.k1.y);
	const int signX = line.k1.x < line.k2.x ? 1 : -1;
	const int signY = line.k1.y < line.k2.y ? 1 : -1;
	//
	int error = deltaX - deltaY;
	//
	mlx_pixel_put(mlx_ptr, win_ptr, line.k2.x, line.k2.y, 0xFF0000);
	while(line.k1.x != line.k2.x || line.k1.y != line.k2.y) 
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.k1.x, line.k1.y, 0xFF0000);
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

int	main(int argc, char **argv)
{
	int		deltax;
	int		deltay;
	int		error;
	int		deltaerror;
	int		x1, x0, y1, y0, x, y;
	int		diry;
	void	*mlx_ptr, *win_ptr;
	
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

	if (argc != 2)
		return (0);
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
	vertex = make_field(len_i, len_j, matrica);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 2000, "Lil Peep");
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
				line.k1.x = (prev_x1 - prev_y1) * cos(0.523599);
				line.k1.y = (prev_x1 + prev_y1) * sin(0.523599) - line.k1.z;
				line.k2.x = (prev_x2 - prev_y2) * cos(0.523599);
				line.k2.y = (prev_x2 + prev_y2) * sin(0.523599) - line.k2.z;
				line.k1.x += 500;
				line.k1.y += 500;
				line.k2.x += 500;
				line.k2.y += 500;
				if (line.k1.z == line.k2.z && line.k1.z == 30)
					draw_blue_line(mlx_ptr, win_ptr, line);
				else
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
				line.k1.x = (prev_x1 - prev_y1) * cos(0.523599);
				line.k1.y = (prev_x1 + prev_y1) * sin(0.523599) - line.k1.z;
				line.k2.x = (prev_x2 - prev_y2) * cos(0.523599);
				line.k2.y = (prev_x2 + prev_y2) * sin(0.523599) - line.k2.z;
				line.k1.x += 500;
				line.k1.y += 500;
				line.k2.x += 500;
				line.k2.y += 500;
				if (line.k1.z == line.k2.z && line.k1.z == 30)
					draw_blue_line(mlx_ptr, win_ptr, line);
				else
					draw_line(mlx_ptr, win_ptr, line);
			}
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}