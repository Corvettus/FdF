/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:17:41 by tlynesse          #+#    #+#             */
/*   Updated: 2019/11/04 18:48:47 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include "get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
#include <fcntl.h>

# define WIN_WIDTH 1920
# define WIN_HIEGHT 1080

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int color;
}				t_point;

typedef struct	s_line
{
	struct s_point	a;
	struct s_point	b;
}				t_line;
typedef struct	s_mlx
{
	void	*mlx;
	t_point	**field;
	int		mode;
	t_point	max;
	int		min_color;
	int		delta_px;
}				t_mlx;

t_mlx	*read_file(int ac, char **av);

void	fill_color(t_mlx *mlx);

double	percent(int start, int end, int current);
int		get_light(int start, int end, double percentage);
int		get_color(t_point current, t_point start, t_point end, t_point delta);

int		ft_key_events(int key, t_mlx *mlx);
int		ft_mouse_events(int button, int x, int y, t_mlx *mlx);

t_mlx	*free_mlx_ptr(t_mlx **mlx);

#endif
