/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:38:49 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 04:38:51 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*new;

	len = ft_strlen(src);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (ft_strcpy(new, src));
}
