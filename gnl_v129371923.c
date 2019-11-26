//
// Created by Gragas Gorilla on 26/11/2019.
//

#include "get_next_line.h"

int mem_to_line(char **mem, int fd, char **line)
{
	int i;
//	int j;

	i = 0;
	while (mem[fd][i] != '\n' && mem[fd][i] != '\0')
		i++;
	if(!(*line = ft_strsub(mem[fd], 0, i)))
		return (-1);
	if (mem[fd][i] != '\0')
		mem[fd] = ft_strsubfree(&(mem[fd]), i + 1,
				ft_strlen(mem[fd]) - i - 1);
	if (mem[fd][0] == '\0')
		ft_strdel(&(mem[fd]));
	return (1);
}

int buf_to_mem(char *buf, char **mem, int fd, char **line)
{
	if (mem[fd] == NULL)
	{
		if (!(mem[fd] = ft_strdup(buf)))
			return (-1);
	}
	else
	{
		if (!(mem[fd] = ft_strjoinfree1(&(mem[fd]), buf)))
			return (-1);
	}
	if (ft_strchr(mem[fd], '\n') != NULL)
		return (mem_to_line(mem, fd, line));
	return (-2);
}

int get_next_line(const int fd, char **line)
{
	char	*mem[1024];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int 		ret2;
	int 		ret3;

	if (fd < 0 || fd >= 11000 || read(fd, NULL, 0) < 0)
		return (-1);
	if (mem[fd] != NULL && ft_strchr(mem[fd], '\n') != NULL)
		mem_to_line(mem, fd, line);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ret2 = buf_to_mem(buf, mem, fd, line);
		if (ret2 != -2)
			return (ret2);
	}
	if (ret == 0 && (mem[fd] == NULL || mem[fd][0] == '\0'))
		return (0);
	ret3 = mem_to_line(mem, fd, line);
	ft_strdel(&mem[fd]);
	return (ret3);
}