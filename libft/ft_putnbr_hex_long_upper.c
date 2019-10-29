/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_long_upper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:36:41 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 04:46:55 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex_long_upper(unsigned long long n)
{
	if (n < 16)
	{
		if (n < 10)
			ft_putchar('0' + n);
		else
			ft_putchar('A' + (n % 10));
	}
	else
	{
		ft_putnbr_hex_long_upper(n / 16);
		n = n % 16;
		if (n < 10)
			ft_putchar('0' + n);
		else
			ft_putchar('A' + (n % 10));
	}
}
