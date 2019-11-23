/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggorilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:40:55 by ggorilla          #+#    #+#             */
/*   Updated: 2019/11/23 17:44:36 by ggorilla         ###   ########.fr       */
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
	{//перекинуть все до \n в line, очистить new[fd] до \n
		/*i = 0;
		while (new[fd][i] != '\n') //переписать это говно, перекидывать все в new к началу
		{
			*line[i] == new[fd][i];
			i++;
		}
		free(*new[fd]);
		new[fd]++;*/
		return (1);
	}
	else if (!new[fd] && read(fd, &buf, BUFF_SIZE) == 0) //случай, когда что?
		return (0);
	else if (read(fd, &buf, BUFF_SIZE) == 0) //случай, когда весь файл - одна строка, нет ни одного \n
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
