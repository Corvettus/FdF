/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 08:46:47 by medesmon          #+#    #+#             */
/*   Updated: 2019/01/14 08:46:22 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char			*s;
	char			*ptr;
	int				fl2;

	fl2 = 0;
	s = (char *)str;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			ptr = s + i;
			fl2 = 1;
		}
		i++;
	}
	if (fl2 == 1)
		return (ptr);
	else if (c == '\0')
		return (s + i);
	else
		return (NULL);
}
