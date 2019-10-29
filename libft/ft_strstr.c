/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 08:51:50 by medesmon          #+#    #+#             */
/*   Updated: 2019/01/14 09:03:17 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int	pos;
	int	i;

	if (!*str2)
		return ((char*)str1);
	pos = 0;
	while (str1[pos])
	{
		i = 0;
		while (str2[i] == str1[pos + i])
		{
			if (str2[i + 1] == '\0')
				return ((char *)str1 + pos);
			i++;
		}
		pos++;
	}
	return (0);
}
