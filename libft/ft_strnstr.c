/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:07:09 by medesmon          #+#    #+#             */
/*   Updated: 2019/01/14 09:11:45 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	unsigned int	pos;
	unsigned int	i;

	if (!*str2)
		return ((char*)str1);
	pos = 0;
	while (str1[pos] && pos < n)
	{
		i = 0;
		while (str2[i] == str1[pos + i] && pos + i < n)
		{
			if (str2[i + 1] == '\0')
				return ((char *)str1 + pos);
			i++;
		}
		pos++;
	}
	return (0);
}
