/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggorilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:40:55 by ggorilla          #+#    #+#             */
/*   Updated: 2019/11/10 19:47:12 by ggorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//написать инклуд и что-то про бафсайз

int get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE];
	static char	*new[12000];
	int			sizeofline;
	int			i;

	i = 0;
	//случай с концом строки
	//**line = '\0';
	while (!ft_strchr(new[fd], "\n") && read(fd, &buf, BUFF_SIZE))  //ошибка чтения?
		new[fd] = ft_strjoin(new[fd], &buf);  //освободить память???
	while (*new[fd] != '\n') //если нет \n???
	{
		*line[i] == *new[fd];
		i++;
		new[fd]++;
	}
	if (*new[fd] == '\n')
		new[fd]++;	

/*
 1) считываем в buf кусок файла размером BUFF_SIZE;
 2) buf перекидываем в new;
 ! повторяем эти действия, приписывая в new новые bufы, ПОКА в new[fd] не окажется \n;
 3) когда в new[fd] встретился символ \n, переписываем все до этого символа в line;
 4) стираем в new[fd] все до символа \n, включая его;
 ! повторяем
 */
}
