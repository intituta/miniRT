/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_a_c_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:30:07 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/10 11:41:55 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	parse_l(t_struct *o)
{
	t_list	*tmp;
	char	**xyz;

	tmp = o->final_list;
	if (ft_check_count(o->strs, 4))
		return (1);
	xyz = ft_split(o->strs[1], ',');
	if (ft_check_count(xyz, 3))
		return (1);
	create_list(o);
	tmp = ft_lstlast(o->final_list);
	tmp->id = ft_strdup(o->strs[0]);
	tmp->range = atof(o->strs[2]);
	ft_xyz(tmp, xyz);
	xyz = ft_split(o->strs[3], ',');
	if (ft_check_count(xyz, 3))
		return (1);
	ft_rgb(tmp, xyz);
	if (tmp->range < 0 || tmp->range > 1 || tmp->r < 0 || tmp->r > 255
		|| tmp->g < 0 || tmp->g > 255 || tmp->b < 0 || tmp->b > 255)
		return (1);
	return (0);
}

int	parse_c(t_struct *o)
{
	t_list	*tmp;
	char	**xyz;

	tmp = o->final_list;
	if (ft_check_count(o->strs, 4))
		return (1);
	xyz = ft_split(o->strs[1], ',');
	if (ft_check_count(xyz, 3))
		return (1);
	create_list(o);
	tmp = ft_lstlast(o->final_list);
	tmp->id = ft_strdup(o->strs[0]);
	ft_xyz(tmp, xyz);
	xyz = ft_split(o->strs[2], ',');
	if (ft_check_count(xyz, 3))
		return (1);
	tmp->n_vec1 = atof(xyz[0]);
	tmp->n_vec2 = atof(xyz[1]);
	tmp->n_vec3 = atof(xyz[2]);
	ft_free(xyz);
	tmp->fov = ft_atoi(o->strs[3]);
	if (tmp->n_vec1 + tmp->n_vec2 + tmp->n_vec3 < -1 || tmp->n_vec1
		+ tmp->n_vec2 + tmp->n_vec3 > 1 || tmp->fov > 180 || tmp->fov < 0)
		return (1);
	return (0);
}

int	parse_a(t_struct *o)
{
	int		i;
	t_list	*tmp;
	char	**rgb;

	tmp = o->final_list;
	i = 0;
	if (ft_check_count(o->strs, 3))
		return (1);
	rgb = ft_split(o->strs[2], ',');
	if (ft_check_count(rgb, 3))
		return (1);
	create_list(o);
	tmp = ft_lstlast(o->final_list);
	tmp->id = ft_strdup(o->strs[0]);
	tmp->range = atof(o->strs[1]);
	ft_rgb(tmp, rgb);
	if (tmp->range < 0 || tmp->range > 1 || tmp->r < 0 || tmp->r > 255
		|| tmp->g < 0 || tmp->g > 255 || tmp->b < 0 || tmp->b > 255)
		return (1);
	return (0);
}
