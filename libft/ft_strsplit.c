/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:40:45 by medesmon          #+#    #+#             */
/*   Updated: 2019/01/20 21:10:10 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	freestr(char **str, int i)
{
	if (!str[i])
	{
		while (--i >= 0 && str[i])
			ft_strdel(&str[i]);
		free(str);
		return (1);
	}
	else
		return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str2;

	if (!s || !(str2 = (char **)malloc(sizeof(*str2) *
					(ft_countwords(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_countwords(s, c))
	{
		k = 0;
		str2[i] = ft_strnew(ft_get_word_len(&s[j], c) + 1);
		if (freestr(str2, i))
			return (NULL);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str2[i][k++] = s[j++];
		str2[i++][k] = '\0';
	}
	str2[i] = 0;
	return (str2);
}
