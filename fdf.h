/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:04:43 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/29 02:03:42 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define print_error ft_putendl("--------------------   HEWSTON, WE HAVE A PROBLEM UP HERE   --------------------");
# include "./libft/libft.h"

typedef struct	s_koord
{
	int	x;
	int	y;
	int	z;
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

t_return_read_file	read_file();

t_koord				**make_field(int i, int j, int **matr);

#endif
