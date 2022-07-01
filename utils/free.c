/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:48:56 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/01 10:52:16 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_list2(t_struct *o)
{
	while (o->list)
	{
		free(o->list->content);
		free(o->list);
		o->list = o->list->next;
	}
	while (o->ambient_light)
	{
		free(o->ambient_light->id);
		free(o->ambient_light);
		o->ambient_light = o->ambient_light->next;
	}
}

void	free_list(t_struct *o)
{
	int	i;

	i = -1;
	while (o->figures)
	{
		free(o->figures->id);
		free(o->figures);
		o->figures = o->figures->next;
	}
	while (++i < o->cam_lst_size)
	{
		free(o->cams->id);
		free(o->cams);
		o->cams = o->cams->next;
	}
	while (o->lights)
	{
		free(o->lights->id);
		free(o->lights);
		o->lights = o->lights->next;
	}
	free_list2(o);
}
