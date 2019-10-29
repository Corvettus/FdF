/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_8_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:36:26 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 04:44:50 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_8_long(unsigned long long int n)
{
	if (n < 8)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr_8_long(n / 8);
		n = n % 8;
		ft_putchar('0' + n);
	}
}
