/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:54:30 by medesmon          #+#    #+#             */
/*   Updated: 2019/01/17 18:47:27 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mem;
	int		len;
	int		i;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	mem = (char *)malloc((size_t)(len + 1));
	if (mem == NULL)
		return (NULL);
	while (i < len)
	{
		mem[i] = f(s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
