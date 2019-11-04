/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 23:11:11 by tlynesse          #+#    #+#             */
/*   Updated: 2019/10/19 16:12:30 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	res;

	res = 0;
	while ((char)s[res] != c && s[res] && res + 1 > res)
		res++;
	if (res + 1 < res)
		return (0);
	return (res);
}
