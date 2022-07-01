/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:40:50 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/01 16:24:56 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		exit(write(2, "error malloc", 12));
	j = -1;
	while (++j < i)
		str[j] = s1[j];
	str[j] = '\0';
	return (str);
}
