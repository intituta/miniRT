/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:39:06 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/01 11:01:50 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	ft_count_word(char const *s)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
		if (!set_checker(s[i]) && (set_checker(s[i + 1]) || s[i + 1] == '\0'))
			count++;
	return (count);
}

static void	*ft_mem_free(char **str, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		free(str[i]);
	free(str);
	return (NULL);
}

static int	ft_len_word(char const *s)
{
	int	len;

	len = 0;
	while (!set_checker(s[len]) && s[len] != '\0')
		len++;
	return (len);
}

static char	**ft_fill_word(char const *s, int count, char **str)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (++i < count)
	{
		while (set_checker(*s))
			s++;
		len = ft_len_word(s);
		str[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!str[i])
			return (ft_mem_free(str, count));
		j = -1;
		while (++j < len)
		{
			str[i][j] = *s;
			s++;
		}
		str[i][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}

char	**split_mod(char const *s)
{
	char	**str;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count_word(s);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	str = ft_fill_word(s, count, str);
	return (str);
}
