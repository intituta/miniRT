/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:40:21 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/05 18:33:33 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

char	*ft_read(int fd)
{
	int		i_read;
	char	*buf;
	char	*result;

	buf = malloc(128 + 1);
	if (!buf)
		return (NULL);
	result = malloc(128 + 1);
	if (!result)
		return (NULL);
	buf[128] = '\0';
	result[0] = '\0';
	i_read = read(fd, buf, 128);
	while (i_read)
	{
		result = concat_here(result, buf, i_read);
		i_read = read(fd, buf, 128);
	}
	free(buf);
	if (i_read < 0)
		return (NULL);
	return (result);
}

int	parse_element(t_scene *sc, char *begin)
{
	if (begin[0] == 'A')
	{
		if (sc->a_lum >= 0)
			return ((sc->a_lum = -444));
		else
			return (parse_ambiance(sc, begin));
	}
	if (begin[0] == 'C' && !sc->camera)
		return (parse_camera(sc, begin));
	else if (begin[0] == 'C' && sc->camera)
		exit_program("Error\nMultiple cameras in sight\n");
	if (begin[0] == 'L')
		return (parse_light(sc, begin));
	return (parse_object(sc, begin));
}

int	parsing(char *all, t_scene *this_scene)
{
	int		i;
	char	**all_elements;

	i = -1;
	all_elements = ft_split(all, '\n');
	while (all_elements[++i])
	{
		if (all_elements[i][0])
			if (parse_element(this_scene, all_elements[i]) < 0)
				exit_program("Error\nIncorrect formatting\n");
		free(all_elements[i]);
	}
	free(all_elements[i]);
	free(all_elements);
	return (0);
}
