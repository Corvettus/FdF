/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 08:33:12 by tlynesse          #+#    #+#             */
/*   Updated: 2019/11/04 21:13:23 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int get_color(t_point current, t_point start, t_point end, t_point delta)
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
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
    percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
    percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

void	fill_color(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->max.x)
	{
		j = 0;
		while (j < mlx->max.y)
		{
			mlx->field[i][j].color =  + (mlx->max.color - mlx->min_color)
            * mlx->field[i][j].z / mlx->max.z;
			//((matr[i][len_j - j - 1] * 3) * (16 * 16 + 16 + 1)) % (16 * 16 * 16)
			j++;
		}
		i++;
	}
}
/* 
void    ft_paint(void *win_ptr, t_mlx *mlx)
{
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
				draw_line(mlx_ptr, win_ptr, line);
			}
			j++;
		}
		i++;
	}
} */