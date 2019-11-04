/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:17:41 by tlynesse          #+#    #+#             */
/*   Updated: 2019/11/04 06:41:12 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# define WIN_WIDTH 1920
# define WIN_HIEGHT 1080
# define X_WIDTH (WIN_WIDTH * WIN_WIDTH / WIN_HIEGHT)
# define X_HEIGHT (WIN_HIEGHT * WIN_WIDTH / WIN_HIEGHT)

typedef struct	s_koord
{
	int	x;
	int	y;
	int	z;
	int color;
}				t_koord;

typedef struct	s_line
{
	struct s_koord	k1;
	struct s_koord	k2;
}				t_line;

typedef struct	s_field
{
	struct s_koord	**vertex;
}				t_field;

typedef struct	s_return_read_file
{
	int				**matr;
	int				ret_i;
	int				ret_j;
}				t_return_read_file;

typedef struct	s_mlx
{
	void	*mlx;
	
}				t_mlx;


t_return_read_file	read_file();

t_koord	**make_field(int i, int j, int **matr, int *max_z);
void	fill_color(int len_i, int len_j, t_koord **vertex, int max_z, int zero_color, int max_color);

#endif
