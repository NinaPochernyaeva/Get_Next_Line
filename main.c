/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttawna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:48:36 by ttawna            #+#    #+#             */
/*   Updated: 2019/10/03 18:55:32 by ttawna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int 	main(void)
{
	char	*l;
	int		fd;
	int 	fd2;
	int		flag;
	int 	ret;
	int 	ret2;

//        printf("sssss");
	fd2 = open("dick2", O_RDONLY);
	fd = open("a.txt", O_RDONLY);
	flag = 0;
	ret2 = 1;
	while ((ret = get_next_line(fd, &l)) >= 0)
	{
		printf("FILE1: |%s|\n", l);
		ft_strdel(&l);
		printf("ret == %d\n", ret);
//		if (flag == 1)
//		{
//			while ((ret2 = get_next_line(fd2, &l)) >= 0)
//			{
//				printf("FILE2: |%s|\n", l);
//				printf("ret2 == %d\n", ret2);
//				ft_strdel(&l);
//				if (ret2 == 0)
//					break ;
//			}
//			flag = 0;
//			printf("gnl must have ret 0. It returned %d\n", ret2);
//		}
		if (ret2 > 0)
			flag = 1;
		if (ret == 0)
			break ;
	}
	printf("gnl must have ret 0. It returned %d\n", ret);
	if (l != NULL)
		ft_strdel(&l);
	close(fd);
    return (0);
}