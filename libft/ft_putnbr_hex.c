/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:36:52 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 04:45:48 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex(unsigned int n)
{
	if (n < 16)
	{
		if (n < 10)
			ft_putchar('0' + n);
		else
			ft_putchar('a' + (n % 10));
	}
	else
	{
		ft_putnbr_hex(n / 16);
		n = n % 16;
		if (n < 10)
			ft_putchar('0' + n);
		else
			ft_putchar('a' + (n % 10));
	}
}
