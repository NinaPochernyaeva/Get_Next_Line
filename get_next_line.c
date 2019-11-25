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

static int	write_to_line(char **line, char **new, int fd)
{
	char	*new_new;
	int		i;
	int		j;

	i = 0;
	while (new[fd][i] != '\0' && new[fd][i] != '\n')
		i++;
	if ((*line = ft_strsub(new[fd], 0, i)) == NULL)
		return (-1);
	i++;
	j = 0;
	while (new[fd][i + j] != '\0')
		j++;
	new_new = ft_strsub(new[fd], i, j);
	free(new[fd]);
	new[fd] = new_new;
	return (1);
}

static int	read_from_file(int fd, char **new)
{
	char	buf[BUFF_SIZE + 1];
	int		r;
	char	*new_new;

	r = 0;
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		if (!new[fd])
		{
			if (!(new[fd] = ft_strdup(buf)))
				return (-1);
		}
		else
		{
			if (!(new_new = ft_strjoin(new[fd], buf)))
				return (-1);
			free(new[fd]);
			new[fd] = new_new;
		}
		if (ft_strchr(new[fd], '\n') != NULL)
			return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static const unsigned int	MAX_FD_SIZE;
	static char					*new[10240];
	int							r;

	MAX_FD_SIZE = 10240;
	if (fd < 0 || fd > 10240 || read(fd, NULL, 0) < 0)
		return (-1);
	r = 0;
	if (new[fd] != NULL && ft_strchr(new[fd], '\n') != NULL)
		return (write_to_line(line, new, fd));
	else
	{
		r = read_from_file(fd, new);
		if ((r == -1)
			return (r);
//		write_to_line(line, new, fd)
		if (r == 0 && (new[fd] == NULL || new[fd][0] == '\0'))
			return (0);
		return (write_to_line(line, new, fd));
	}
}
