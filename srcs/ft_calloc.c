/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:39:19 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/05 18:04:04 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s_out;

	i = 0;
	if (!s)
		return ;
	s_out = (char *)s;
	while (i < n)
	{
		s_out[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*cpy;

	cpy = malloc(nmemb * size);
	if (!cpy)
		exit_program("Error\nMemory allocation failed !\n");
	ft_bzero(cpy, size * nmemb);
	return (cpy);
}
