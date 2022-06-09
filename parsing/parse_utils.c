/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:31:55 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/09 20:32:21 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_rgb(t_list *tmp, char **rgb)
{
	tmp->r = ft_atoi(rgb[0]);
	tmp->g = ft_atoi(rgb[1]);
	tmp->b = ft_atoi(rgb[2]);
	ft_free(rgb);
}

void	ft_xyz(t_list *tmp, char **xyz)
{
	tmp->x = atof(xyz[0]);
	tmp->y = atof(xyz[1]);
	tmp->z = atof(xyz[2]);
	ft_free(xyz);
}
