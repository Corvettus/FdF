/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 02:35:59 by medesmon          #+#    #+#             */
/*   Updated: 2019/02/06 04:10:49 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*mem;

	if (!(mem = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(mem, (int)'\0', size + 1);
	return (mem);
}
