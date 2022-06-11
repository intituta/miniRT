/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_a_c_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:30:07 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/10 19:50:19 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	parse_l(t_struct *o)
{
	t_list	*tmp;

	if (ft_check_count(o->strs, 4))
		return (1);
	o->xyz = ft_split(o->strs[1], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	o->lights = create_list(o->lights);
	tmp = ft_lstlast(o->lights);
	tmp->id = ft_strdup(o->strs[0]);
	tmp->range = ft_atof(o->strs[2]);
	ft_xyz(tmp, o->xyz);
	o->xyz = ft_split(o->strs[3], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	ft_rgb(tmp, o->xyz);
	if (tmp->range < 0 || tmp->range > 1 || tmp->r < 0 || tmp->r > 255
		|| tmp->g < 0 || tmp->g > 255 || tmp->b < 0 || tmp->b > 255)
		return (1);
	return (0);
}

int	parse_c(t_struct *o)
{
	t_list	*tmp;

	if (ft_check_count(o->strs, 4))
		return (1);
	o->xyz = ft_split(o->strs[1], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	o->cams = create_list(o->cams);
	tmp = ft_lstlast(o->cams);
	tmp->id = ft_strdup(o->strs[0]);
	ft_xyz(tmp, o->xyz);
	o->xyz = ft_split(o->strs[2], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	ft_normalize(tmp, o->xyz);
	tmp->fov = ft_atoi(o->strs[3]);
	if (tmp->n_vec1 + tmp->n_vec2 + tmp->n_vec3 < -1 || tmp->n_vec1
		+ tmp->n_vec2 + tmp->n_vec3 > 1 || tmp->fov > 180 || tmp->fov < 0)
		return (1);
	return (0);
}

int	parse_a(t_struct *o)
{
	t_list	*tmp;
	char	**rgb;

	if (ft_check_count(o->strs, 3))
		return (1);
	rgb = ft_split(o->strs[2], ',');
	if (ft_check_count(rgb, 3))
		return (1);
	o->figures = create_list(o->figures);
	tmp = ft_lstlast(o->figures);
	tmp->id = ft_strdup(o->strs[0]);
	tmp->range = ft_atof(o->strs[1]);
	ft_rgb(tmp, rgb);
	if (tmp->range < 0 || tmp->range > 1 || tmp->r < 0 || tmp->r > 255
		|| tmp->g < 0 || tmp->g > 255 || tmp->b < 0 || tmp->b > 255)
		return (1);
	return (0);
}
