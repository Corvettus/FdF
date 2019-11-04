/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:41:28 by tlynesse          #+#    #+#             */
/*   Updated: 2019/11/04 18:35:56 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_joining_buff(const int fd, char **tmp,
				ssize_t *ret, char buff[BUFF_SIZE + 1])
{
	char	*temp;

	if (!ft_strchr(*tmp, '\n'))
		while (*tmp && (*ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[*ret] = 0;
			temp = ft_strjoin(*tmp, buff);
			ft_strdel(tmp);
			*tmp = temp;
			if (ft_strchr(buff, '\n'))
				break ;
		}
}

static int	ft_final_countdown(const int fd, char **tmp,
				char *fd_lines[FD_MAX_NUM], char **line)
{
	size_t	len;

	if (!**tmp)
	{
		ft_strdel(tmp);
		return (0);
	}
	len = ft_strclen(*tmp, '\n');
	*line = ft_strsub(*tmp, 0, len);
	if (!(*tmp)[len])
		fd_lines[fd] = ft_strnew(0);
	else if (!(fd_lines[fd] =
			ft_strsub(*tmp, len + 1, ft_strlen(*tmp + len + 1))))
		return (-1);
	ft_strdel(tmp);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*fd_lines[FD_MAX_NUM];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		ret;

	if (!line || BUFF_SIZE <= 0 ||
			fd < 0 || fd > FD_MAX_NUM - 1 || (ret = read(fd, buff, 0)) < 0)
		return (-1);
	*line = 0;
	if (fd_lines[fd])
		tmp = ft_strdup(fd_lines[fd]);
	else
		tmp = ft_strnew(0);
	ft_strdel(&fd_lines[fd]);
	ft_joining_buff(fd, &tmp, &ret, buff);
	if (!tmp || ret < 0)
		return (-1);
	return (ft_final_countdown(fd, &tmp, fd_lines, line));
}
