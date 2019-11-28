/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggorilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:40:55 by ggorilla          #+#    #+#             */
/*   Updated: 2019/11/27 20:54:58 by ggorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	write_to_line(char **new, char **line, int fd)
{
	int	i;

	i = 0;
	while (new[fd][i] != '\n' && new[fd][i] != '\0')
		i++;
	if (!(*line = ft_strsub(new[fd], 0, i)))
		return (-1);
	if (new[fd][i] != '\0')
		new[fd] = ft_strsubfree(&(new[fd]), i + 1,
								ft_strlen(new[fd]) - i - 1);
	if (*(new[fd]) == '\0')
		ft_strdel(&(new[fd]));
	return (1);
}

static int	read_from_buff(char *buff, char **line, char **new, const int fd)
{
	if (new[fd] == NULL)
	{
		if (!(new[fd] = ft_strdup((const char *)buff)))
			return (-1);
	}
	else
	{
		if (!(new[fd] = ft_strjoinfree1(new[fd], (const char *)buff)))
			return (-1);
	}
	if (ft_strchr(new[fd], '\n') != NULL)
		return (write_to_line(new, line, fd));
	return (-2);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*new[10500];
	int			ret;
	int			ret1;
	int			ret2;

	if (fd < 0 || fd > 10499 || read(fd, NULL, 0) < 0)
		return (-1);
	if (new[fd] != NULL && ft_strchr(new[fd], '\n') != NULL)
		return (write_to_line(new, line, fd));
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((ret1 = read_from_buff(buff, line, new, fd)) != -2)
			return (ret1);
	}
	if (ret == 0 && (new[fd] == NULL || new[fd][0] == '\0'))
		return (0);
	ret2 = write_to_line(new, line, fd);
	ft_strdel(&(new[fd]));
	return (ret2);
}
