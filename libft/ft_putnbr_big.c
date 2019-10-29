/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:36:34 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 04:53:35 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_big(unsigned long long n)
{
	if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr_big(n / 10);
		ft_putchar('0' + n % 10);
	}
}
