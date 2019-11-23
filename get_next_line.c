/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggorilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:40:55 by ggorilla          #+#    #+#             */
/*   Updated: 2019/11/23 18:38:48 by ggorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//написать инклуд и что-то про бафсайз

char		buf[BUFF_SIZE];
static char	*new[12000];
//int		sizeofline;
int			i;

//read(...) < 0

int		ft_symb_no(char *a, char b)
{
	int i;

	i = 0;
	while (a[i] != b)
		i++;
	return i;
}

void	ft_move(char *a, int i)
{
	
}

int		main()
{
	while (read(fd, &buf, BUFF_SIZE) >= 0)
	{
		new[fd] = ft_strjoin(new[fd], buf);
		if (ft_strchr(new[fd], "\n"))
		{//перекинуть все до \n в line, очистить new[fd] до \n
			i = ft_symb_no(new[fd], '\n');
			line = ft_strncpy(line, new[fd], i);

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
}

/*
 1) считываем в buf кусок файла размером BUFF_SIZE;
 2) buf перекидываем в new;
 ! повторяем эти действия, приписывая в new новые bufы, ПОКА в new[fd] не окажется \n;
 3) когда в new[fd] встретился символ \n, переписываем все до этого символа в line;
 4) стираем в new[fd] все до символа \n, включая его;
 ! повторяем
 */
