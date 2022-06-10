/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:08:26 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/10 13:00:15 by kferterb         ###   ########.fr       */
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
		ft_lstadd_back(&o->final_list, ft_lstnew(NULL));
}

int	parsing(t_struct *o)
{
	int		i;
	int		err;
	t_list	*tmp;

	i = -1;
	tmp = o->list;
	while (++i < o->lst_size)
	{	
		err = 0;
		o->strs = ft_split(tmp->content, ' ');
		if (ft_strlen(o->strs[0]) == 1 && o->strs[0][0] == 'A')
			err = parse_a(o);
		else if (ft_strlen(o->strs[0]) == 1 && o->strs[0][0] == 'C')
			err = parse_c(o);
		else if (ft_strlen(o->strs[0]) == 1 && o->strs[0][0] == 'L')
			err = parse_l(o);
		else if (ft_strlen(o->strs[0]) == 2 && !ft_strncmp(o->strs[0], "sp", 2))
			err = parse_sp(o);
		else
			return (ft_free(o->strs), 1);
		if (err)
			return (ft_free(o->strs), 1);
		ft_free(o->strs);
		tmp = tmp->next;
	}
	return (0);
}
