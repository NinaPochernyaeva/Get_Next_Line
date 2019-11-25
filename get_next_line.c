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

char		buf[BUFF_SIZE];
static char	*new[12000];
int			i;

int	ft_symb_no(char *a, char b)
{
	int i;

	i = 0;
	while (a[i] != b)
		i++;
	return (i);
}

int	get_next_line(const int fd, char **line)
{
	if (fd < 0 || fd > 10240 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1); //случаи ошибок
	while (read(fd, &buf, BUFF_SIZE) >= 0)
	{
		new[fd] = ft_strjoin(new[fd], buf);
		if (ft_strchr(new[fd], '\n'))
		{
			i = ft_symb_no(new[fd], '\n');
			*line = ft_strncpy(*line, new[fd], i);
			new[fd] = ft_strsub(new[fd], i + 1, ft_strlen(new[fd]) - i - 1);
			return (1);
		}
		else if (read(fd, &buf, BUFF_SIZE) == 0) //дочитали
		{
			*line = ft_strcpy(*line, new[fd]);
			ft_strdel(&new[fd]);
			return (0);
		}
	}
}