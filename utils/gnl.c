/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:37:21 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/30 20:15:32 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

char	*ft_gnl(int fd)
{	
	int		i;
	int		r;
	char	*buf;
	char	*res;

	i = 0;
	while (1)
	{
		buf = malloc(sizeof(char) * 2);
		r = read(fd, buf, 1);
		if (!r || (buf[0] == '\n' && i > 0))
			break ;
		if (!i && buf[0] == '\n')
		{
			res = malloc(1);
			res[0] = '\0';
			break ;
		}
		buf[1] = '\0';
		if (!i)
			res = ft_strdup(buf);
		else
			res = ft_strjoin(res, buf, 1, 0);
		free(buf);
		i++;
	}
	free(buf);
	return (res);
}
