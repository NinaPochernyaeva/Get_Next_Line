/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggorilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:40:55 by ggorilla          #+#    #+#             */
/*   Updated: 2019/11/10 20:52:50 by ggorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//написать инклуд и что-то про бафсайз

char		buf[BUFF_SIZE];
static char	*new[12000];
int			sizeofline;
int			i;

//read(...) < 0

while (read(fd, &buf, BUFF_SIZE) >= 0)
{
	new = ft_strjoin(new, buf);
	if (ft_strchr(new[fd], "\n"))
	{
		i = 0;
		while (*new[fd] != '\n')
		{
			*line[i] == *new[fd];
			i++;
			free(new[fd]);  //??
			new[fd]++;  //очистить new?
		}
		if (*new[fd] == '\n')
			new[fd]++;
		return (1);
	}
	if (!new[fd] && read(fd, &buf, BUFF_SIZE) == 0)
		return (0);
	if (read(fd, &buf, BUFF_SIZE) == 0)
	{
		line = ft_strcpy(line, new);
		ft_strdel(new);
		return (1);
	}
}

/*
 1) считываем в buf кусок файла размером BUFF_SIZE;
 2) buf перекидываем в new;
 ! повторяем эти действия, приписывая в new новые bufы, ПОКА в new[fd] не окажется \n;
 3) когда в new[fd] встретился символ \n, переписываем все до этого символа в line;
 4) стираем в new[fd] все до символа \n, включая его;
 ! повторяем
 */
}
