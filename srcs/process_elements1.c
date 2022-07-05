/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_elements1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:40:09 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/05 14:40:12 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

char	*process_cylinder(char *begin, t_objs *ob)
{
	char	*it;

	it = get_some_d(&ob->or, 3, begin);
	if (!it)
		return (NULL);
	ob->or = normalize(ob->or);
	it = get_some_d(&ob->params, 2, it);
	if (!it)
		return (NULL);
	it = get_some_i(ob->color, 3, it);
	if (!it)
		return (NULL);
	ob->type = 'c';
	return (it);
}

char	*process_plane(char *begin, t_objs *ob)
{
	char	*it;

	it = get_some_d(&ob->or, 3, begin);
	ob->or = normalize(ob->or);
	if (!it)
		return (NULL);
	it = get_some_i(ob->color, 3, it);
	if (!it)
		return (NULL);
	ob->type = 'p';
	return (it);
}

char	*process_sphere(char *begin, t_objs *ob)
{
	char	*it;

	it = get_some_d(&ob->params, 1, begin);
	if (!it)
		return (NULL);
	it = get_some_i(ob->color, 3, it);
	if (!it)
		return (NULL);
	ob->type = 's';
	return (it);
}

int	process_object(t_scene *sc, char *begin)
{
	char	*it;
	t_objs	*ob;

	if ((ft_strncmp(begin, "sp", 2) && ft_strncmp(begin, "pl", 2)
			&& ft_strncmp(begin, "cy", 2)) || !ft_isspace(begin[2]))
		exit_program("ERROR: unknown element\n");
	ob = push_new_object(&(sc->obj_list));
	if (!ob)
		return (-11);
	it = get_some_d(&ob->coord, 3, begin + 2);
	if (!it)
		return (-41);
	if (!ft_strncmp(begin, "cy", 2))
		it = process_cylinder(it, ob);
	else if (!ft_strncmp(begin, "pl", 2))
		it = process_plane(it, ob);
	else if (!ft_strncmp(begin, "sp", 2))
		it = process_sphere(it, ob);
	if (!it)
		return (-41);
	return (1);
}
