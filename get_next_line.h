/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggorilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 23:53:49 by ggorilla          #+#    #+#             */
/*   Updated: 2019/11/24 00:14:12 by ggorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 15

# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"
# include "unistd.h"
# include <stdlib.h>
# include "libft/libft.h"

int		ft_symb_no(char *a, char b);
int		get_next_line(const int fd, char **line);
#endif
