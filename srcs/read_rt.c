/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:40:21 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/05 17:41:06 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

char	*ft_read(int fd)
{
	int		i_read;
	char	*buf;
	char	*result;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	result = malloc(BUFFER_SIZE + 1);
	if (!result)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	result[0] = '\0';
	i_read = read(fd, buf, BUFFER_SIZE);
	while (i_read)
	{
		result = concat_here(result, buf, i_read);
		i_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (i_read < 0)
		return (NULL);
	return (result);
}

int	process_element(t_scene *sc, char *begin)
{
	if (begin[0] == 'A')
	{
		if (sc->a_lum >= 0)
			return ((sc->a_lum = -444));
		else
			return (process_ambiance(sc, begin));
	}
	if (begin[0] == 'C' && !sc->camera)
		return (process_camera(sc, begin));
	else if (begin[0] == 'C' && sc->camera)
		exit_program("Error\nMultiple cameras in sight\n");
	if (begin[0] == 'L')
		return (process_light(sc, begin));
	return (process_object(sc, begin));
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
			if (process_element(this_scene, all_elements[i]) < 0)
				exit_program("Error\nIncorrect formatting\n");
		free(all_elements[i]);
	}
	free(all_elements[i]);
	free(all_elements);
	return (0);
}
