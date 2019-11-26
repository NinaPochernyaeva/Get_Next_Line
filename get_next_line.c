/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggorilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:40:55 by ggorilla          #+#    #+#             */
/*   Updated: 2019/11/25 19:57:20 by ggorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	mem_to_line(char **mem, char **line, int fd)
{
	int i;

	i = 0;
	while (mem[fd][i] != '\n' && mem[fd][i] != '\0')
		i++;
	*line = ft_strsub(mem[fd], 0, i);
	if (*line == NULL)
		return (-1);
	if (mem[fd][i] != '\0')
		mem[fd] = ft_strsubfree(&(mem[fd]), i + 1,
								ft_strlen(mem[fd]) - i - 1);
	if (*(mem[fd]) == '\0')
		ft_strdel(&(mem[fd]));
	return (1);
}

int	buf_to_mem(char *buf, char **line, char **mem, const int fd)
{
	if (mem[fd] == NULL)
	{
		mem[fd] = ft_strdup((const char *)buf);
		if (mem[fd] == NULL)
			return (-1);
	}
	else
	{
		mem[fd] = ft_strjoinfree(&(mem[fd]), (const char *)buf);
		if (!mem[fd])
			return (-1);
	}
	if (ft_strchr(mem[fd], '\n') != NULL)
		return (mem_to_line(mem, line, fd));
	return (-2);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*mem[11000];
	int			ret;
	int			ret1;
	int 		ret2;

	if (fd < 0 || fd > 10999 || read(fd, NULL, 0) < 0)
		return (-1);
	if (mem[fd] != NULL && ft_strchr(mem[fd], '\n') != NULL)
		return (mem_to_line(mem, line, fd));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ret1 = buf_to_mem(buf, line, mem, fd);
		if (ret1 != -2)
			return (ret1);
	}
	if (ret == 0 && (mem[fd] == NULL || mem[fd][0] == '\0'))
		return (0);
	ret2 = mem_to_line(mem, line, fd);
	ft_strdel(&(mem[fd]));
	return (ret2);
}