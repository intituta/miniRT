/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:08:26 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/23 19:09:12 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	cycle_cams(t_struct *o)
{
	t_list	*tmp;

	o->cam_lst_size = ft_lstsize(o->cams);
	tmp = ft_lstlast(o->cams);
	tmp->next = o->cams;
}

int	if_else(t_struct *o, int *err)
{
	if (ft_strlen(o->strs[0]) == 1 && o->strs[0][0] == 'A')
			*err = parse_a(o);
	else if (ft_strlen(o->strs[0]) == 1 && o->strs[0][0] == 'C')
		*err = parse_c(o);
	else if (ft_strlen(o->strs[0]) == 1 && o->strs[0][0] == 'L')
		*err = parse_l(o);
	else if (ft_strlen(o->strs[0]) == 2 && !ft_strncmp(o->strs[0], "sp", 2))
		*err = parse_sp(o);
	else if (ft_strlen(o->strs[0]) == 2 && !ft_strncmp(o->strs[0], "pl", 2))
		*err = parse_pl(o);
	else if (ft_strlen(o->strs[0]) == 2 && !ft_strncmp(o->strs[0], "cy", 2))
		*err = parse_cy(o);
	else
		return (1);
	return (0);
}

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

t_list	*create_list(t_list *list)
{
	if (!list)
		list = ft_lstnew(NULL);
	else
		ft_lstadd_back(&list, ft_lstnew(NULL));
	return (list);
}

int	parsing(t_struct *o)
{
	int		err;
	t_list	*tmp;

	tmp = o->list;
	while (tmp)
	{	
		err = 0;
		o->strs = ft_split(tmp->content, ' ');
		if (if_else(o, &err) || err)
			return (ft_free(o->strs), 1);
		ft_free(o->strs);
		tmp = tmp->next;
	}
	return (0);
}
