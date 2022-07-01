/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:37:21 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/01 16:24:47 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

char	*ft_gnl(int fd)
{	
	int		r[2];
	char	*buf;
	char	*res;

	r[1] = 0;
	while (1)
	{
		buf = malloc(sizeof(char) * 2);
		if (!buf)
			exit(write(2, "error malloc", 12));
		r[0] = read(fd, buf, 1);
		if (!r[0] || (r[1] > 0 && buf[0] == '\n'))
			break ;
		if (!r[1] && buf[0] == '\n')
		{
			res = malloc(1);
			if (!res)
				exit(write(2, "error malloc", 12));
			res[0] = '\0';
			break ;
		}
		buf[1] = '\0';
		if (!r[1]++)
			res = ft_strdup(buf);
		else
			res = ft_strjoin(res, buf, 1, 0);
		free(buf);
	}
	return (free(buf), res);
}
