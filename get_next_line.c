/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 04:23:01 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 21:36:45 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	divide_tmp(char **line,
		char *fd_lines[FD_MAX_NUM], char **tmp, int fd)
{
	int		len;

	if (!**tmp)
	{
		ft_strdel(tmp);
		return (0);
	}
	len = ft_strclen(*tmp, '\n');
	*line = ft_strsub(*tmp, 0, len - 1);
	if (!(tmp[0][len - 2]))
		fd_lines[fd] = ft_strnew(0);
	else
	{
		fd_lines[fd] =
			ft_strsub(*tmp, len, ft_strlen(*tmp + len - 1));
		if (!fd_lines[fd])
			return (-1);
	}
	ft_strdel(tmp);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	ssize_t		ret;
	static char	*fd_lines[FD_MAX_NUM];

	if (!line || BUFF_SIZE <= 0 || fd < 0 || fd > FD_MAX_NUM - 1 ||
			(ret = read(fd, buff, 0)) < 0)
		return (-1);
	if (fd_lines[fd])
		tmp = ft_strdup(fd_lines[fd]);
	else
		tmp = ft_strnew(0);
	ft_strdel(&fd_lines[fd]);
	if (!ft_strchr(tmp, '\n'))
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			tmp = ft_strdel1join(tmp, buff);
			if (ft_strchr(buff, '\n'))
				break ;
		}
	if (ret < 0 || !tmp)
		return (-1);
	return (divide_tmp(line, fd_lines, &tmp, fd));
}
