/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:42:29 by medesmon          #+#    #+#             */
/*   Updated: 2019/01/20 19:15:49 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char				*mem;
	unsigned int		i;
	unsigned int		j;
	unsigned int		k;

	if (!s)
		return (0);
	i = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = 0;
	while (s[ft_strlen(s) - j - 1] == ' ' || s[ft_strlen(s) - j - 1] == '\n'
			|| s[ft_strlen(s) - j - 1] == '\t')
		j++;
	if ((int)ft_strlen(s) - (int)i - (int)j < 1)
		return (ft_strdup("\0"));
	if (!(mem = ft_memalloc((size_t)ft_strlen((char*)s) + 1 - i - j)))
		return (NULL);
	while (i < ft_strlen(s) - j)
		mem[k++] = s[i++];
	mem[k] = '\0';
	return (mem);
}
