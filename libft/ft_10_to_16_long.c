/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_10_to_16_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:30:32 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 04:30:34 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_10_to_16_long(unsigned long long n)
{
	int					*num;
	unsigned long long	tsel;
	long				por;
	int					i;

	i = 0;
	num = 0;
	tsel = n;
	por = 1;
	while (tsel >= 1)
	{
		num = (tsel % 16 * por + num);
		por = por * 10;
		tsel = tsel / 16;
		i++;
	}
	num = tsel * por + num;
	return (i);
}
