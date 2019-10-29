/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:33:08 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 04:42:31 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa(long long n)
{
	char				*mem;
	unsigned int		len;
	unsigned long long	neg;

	if (!(len = ft_count_num(n)))
		return (ft_strdup("0"));
	if (n < 0)
	{
		len++;
		neg = -n;
	}
	else
		neg = n;
	if (!(mem = ft_strnew(len)))
		return (NULL);
	while (neg)
	{
		mem[len - 1] = neg % 10 + '0';
		neg /= 10;
		len--;
	}
	if (n < 0)
		mem[0] = '-';
	return (mem);
}
