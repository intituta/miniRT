/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:40:26 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/06 11:05:52 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*concat_here(char *str1, char *str2, int read)
{
	int		i;
	int		size1;
	int		size2;
	char	*together;

	size1 = ft_strlen(str1);
	size2 = ft_strlen(str2);
	if (read < size2)
		size2 = read;
	together = malloc(size1 + size2 + 1);
	if (!together)
		return (NULL);
	i = -1;
	while (++i < size1)
		together[i] = str1[i];
	i--;
	while (++i < size1 + size2)
		together[i] = str2[i - size1];
	together[i] = '\0';
	free(str1);
	return (together);
}

char	*advance_through(char *this)
{
	int	i;

	i = 0;
	while (this[i] && ((this[i] >= 9 && this[i] <= 13) || this[i] == 32))
		i++;
	while (this[i] && ((this[i] >= '0' && this[i] <= '9')
			|| this[i] == '.' || this[i] == '-'))
		i++;
	return (this + i + (this[i] == ','));
}
