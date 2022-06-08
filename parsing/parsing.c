/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:08:26 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/08 16:00:50 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	ft_check_count(char **strs, int count)
{
	int		i;

	i = 0;
	while (strs[i])
		i++;
	if (i != count)
		return (1);
	return (0);
}

void	create_list(t_struct *o)
{
	if (!o->final_list)
		o->final_list = ft_lstnew(NULL);
	else
		ft_lstadd_back(&o->list, ft_lstnew(NULL));
}

int	parse_a(t_struct *o)
{
	int		i;
	t_list	*tmp;
	char	**rgb;

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
	tmp->r = ft_atoi(rgb[0]);
	tmp->g = ft_atoi(rgb[1]);
	tmp->b = ft_atoi(rgb[2]);
	if (tmp->range < 0 || tmp->range > 1 || tmp->r < 0 || tmp->r > 255
		|| tmp->g < 0 || tmp->g > 255 || tmp->b < 0 || tmp->b > 255)
		return (1);
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
	return (0);
}

int	if_else(t_struct *o)
{
	if (ft_strlen(o->strs[0]) == 1 && o->strs[0][0] == 'A')
		if (parse_a(o))
			return (1);
	// else if (strs[*i][0] == 'C')
	// 	parse_c(strs);
	// else if (strs[*i][0] == 'L')
	// 	parse_l(strs);
	// else if (strs[*i][0] == 's' && strs[*i][1] == 'p')
	// 	parse_sp(strs);
	// else if (strs[*i][0] == 'p' && strs[*i][1] == 'l')
	// 	parse_pl(strs);
	// else if (strs[*i][0] == 'c' && strs[*i][1] == 'y')
	// 	parse_cy(strs);
	return (0);
}

int	parsing(t_struct *o)
{
	int		i;
	t_list	*tmp;

	tmp = o->list;
	while (tmp)
	{	
		i = 0;
		o->strs = ft_split(tmp->content, ' ');
		if (if_else(o))
			return (1);
		while (o->strs[i])
			free(o->strs[i++]);
		free(o->strs);
		tmp = tmp->next;
	}
	return (0);
}
