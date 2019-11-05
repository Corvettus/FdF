/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:59:48 by tlynesse          #+#    #+#             */
/*   Updated: 2019/11/05 02:16:24 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*free_mlx_ptr(t_mlx **mlx)
{
	int i;
	
	if (mlx == NULL || *mlx == NULL)
		return (NULL);
	if ((*mlx)->mlx != NULL)
		free ((*mlx)->mlx);
	if ((*mlx)->field != NULL)
	{
		i = -1;
		while (++i < (*mlx)->max.y)
			if ((*mlx)->field[i] != NULL)
				free((*mlx)->field[i]);
		free((*mlx)->field);
	}
	return (NULL);
}