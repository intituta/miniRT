/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp_pl_cy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:43:28 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/28 13:00:38 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_cy(t_list	*tmp)
{
	if (tmp->n_vec1 + tmp->n_vec2 + tmp->n_vec3 < -1
		|| tmp->n_vec1 + tmp->n_vec2 + tmp->n_vec3 > 1
		|| tmp->r < 0 || tmp->r > 255 || tmp->g < 0 || tmp->g > 255
		|| tmp->b < 0 || tmp->b > 255 || tmp->diametr <= 0 || tmp->height <= 0)
		return (1);
	return (0);
}

int	parse_cy(t_struct *o)
{
	t_list	*tmp;

	if (ft_check_count(o->strs, 6))
		return (1);
	o->xyz = ft_split(o->strs[1], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	o->figures = create_list(o->figures);
	tmp = ft_lstlast(o->figures);
	tmp->id = ft_strdup(o->strs[0]);
	ft_xyz(tmp, o->xyz);
	o->xyz = ft_split(o->strs[2], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	ft_normalize(tmp, o->xyz);
	tmp->diametr = ft_atof(o->strs[3]);
	tmp->height = ft_atof(o->strs[4]);
	o->xyz = ft_split(o->strs[5], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	ft_rgb(tmp, o->xyz);
	if (check_cy(tmp))
		return (1);
	return (0);
}

int	parse_pl(t_struct *o)
{
	t_list	*tmp;

	if (ft_check_count(o->strs, 4))
		return (1);
	o->xyz = ft_split(o->strs[1], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	o->figures = create_list(o->figures);
	tmp = ft_lstlast(o->figures);
	tmp->id = ft_strdup(o->strs[0]);
	ft_xyz(tmp, o->xyz);
	o->xyz = ft_split(o->strs[2], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	ft_normalize(tmp, o->xyz);
	o->xyz = ft_split(o->strs[3], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	ft_rgb(tmp, o->xyz);
	if (tmp->n_vec1 + tmp->n_vec2 + tmp->n_vec3 < -1
		|| tmp->n_vec1 + tmp->n_vec2 + tmp->n_vec3 > 1 || tmp->r < 0
		|| tmp->r > 255 || tmp->g < 0 || tmp->g > 255 || tmp->b < 0
		|| tmp->b > 255)
		return (1);
	return (0);
}

int	parse_sp(t_struct *o)
{
	t_list	*tmp;

	if (ft_check_count(o->strs, 4))
		return (1);
	o->xyz = ft_split(o->strs[1], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	o->figures = create_list(o->figures);
	tmp = ft_lstlast(o->figures);
	tmp->id = ft_strdup(o->strs[0]);
	tmp->diametr = ft_atof(o->strs[2]);
	ft_xyz(tmp, o->xyz);
	o->xyz = ft_split(o->strs[3], ',');
	if (ft_check_count(o->xyz, 3))
		return (1);
	ft_rgb(tmp, o->xyz);
	if (tmp->diametr <= 0 || tmp->r < 0 || tmp->r > 255
		|| tmp->g < 0 || tmp->g > 255 || tmp->b < 0 || tmp->b > 255)
		return (1);
	return (0);
}
