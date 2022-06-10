/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp_pl_cy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:43:28 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/10 12:54:14 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	parse_sp(t_struct *o)
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
	tmp->diametr = atof(o->strs[2]);
	ft_xyz(tmp, xyz);
	xyz = ft_split(o->strs[3], ',');
	if (ft_check_count(xyz, 3))
		return (1);
	ft_rgb(tmp, xyz);
	if (tmp->r < 0 || tmp->r > 255 || tmp->g < 0
		|| tmp->g > 255 || tmp->b < 0 || tmp->b > 255)
		return (1);
	return (0);
}
