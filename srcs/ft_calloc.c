/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:39:19 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/05 14:39:25 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s_out;
	size_t	i;

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
