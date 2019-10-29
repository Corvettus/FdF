/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:36:56 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 04:46:17 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_uns(unsigned int n)
{
	if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr_uns(n / 10);
		ft_putchar('0' + n % 10);
	}
}
