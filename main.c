/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:26:57 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/10 17:34:55 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void	print_cy(t_list *tmp)
{
	printf("id = %s\n", tmp->id);
	printf("X = %f\n", tmp->x);
	printf("Y = %f\n", tmp->y);
	printf("Z = %f\n", tmp->z);
	printf("X norme = %f\n", tmp->n_vec1);
	printf("Y norme = %f\n", tmp->n_vec2);
	printf("Z norme = %f\n", tmp->n_vec3);
	printf("diametr = %f\n", tmp->diametr);
	printf("R = %d\n", tmp->r);
	printf("G = %d\n", tmp->g);
	printf("B = %d\n", tmp->b);
}

void	print_pl(t_list *tmp)
{
	printf("id = %s\n", tmp->id);
	printf("X = %f\n", tmp->x);
	printf("Y = %f\n", tmp->y);
	printf("Z = %f\n", tmp->z);
	printf("X norme = %f\n", tmp->n_vec1);
	printf("Y norme = %f\n", tmp->n_vec2);
	printf("Z norme = %f\n", tmp->n_vec3);
	printf("R = %d\n", tmp->r);
	printf("G = %d\n", tmp->g);
	printf("B = %d\n", tmp->b);
}

void	print_sp(t_list *tmp)
{
	printf("id = %s\n", tmp->id);
	printf("X = %f\n", tmp->x);
	printf("Y = %f\n", tmp->y);
	printf("Z = %f\n", tmp->z);
	printf("diametr = %f\n", tmp->diametr);
	printf("R = %d\n", tmp->r);
	printf("G = %d\n", tmp->g);
	printf("B = %d\n", tmp->b);
}

void	print_l(t_list *tmp)
{
	printf("id = %s\n", tmp->id);
	printf("range = %f\n", tmp->range);
	printf("X = %f\n", tmp->x);
	printf("Y = %f\n", tmp->y);
	printf("Z = %f\n", tmp->z);
	printf("R = %d\n", tmp->r);
	printf("G = %d\n", tmp->g);
	printf("B = %d\n", tmp->b);
}

void	print_c(t_list *tmp)
{
	printf("id = %s\n", tmp->id);
	printf("X = %f\n", tmp->x);
	printf("Y = %f\n", tmp->y);
	printf("Z = %f\n", tmp->z);
	printf("X norme = %f\n", tmp->n_vec1);
	printf("Y norme = %f\n", tmp->n_vec2);
	printf("Z norme = %f\n", tmp->n_vec3);
	printf("fov = %d\n", tmp->fov);
}

void	print_a(t_list *tmp)
{
	printf("id = %s\n", tmp->id);
	printf("range = %f\n", tmp->range);
	printf("R = %d\n", tmp->r);
	printf("G = %d\n", tmp->g);
	printf("B = %d\n", tmp->b);
}

void	print_lists(t_struct *o)
{
	int		i;
	t_list	*tmp;

	tmp = o->figures;
	while (tmp)
	{
		if (tmp->id[0] == 'A')
			print_a(tmp);
		else if (tmp->id[0] == 's' && tmp->id[1] == 'p')
			print_sp(tmp);
		else if (tmp->id[0] == 'p' && tmp->id[1] == 'l')
			print_pl(tmp);
		else if (tmp->id[0] == 'c' && tmp->id[1] == 'y')
			print_cy(tmp);
		printf("=====figures======\n");
		tmp = tmp->next;
	}
	i = -1;
	tmp = o->cams;
	while (++i < o->cam_lst_size)
	{
		if (tmp->id[0] == 'C')
			print_c(tmp);
		printf("======camera=====\n");
		tmp = tmp->next;
	}
	tmp = o->lights;
	while (tmp)
	{
		if (tmp->id[0] == 'L')
			print_l(tmp);
		printf("======lights=====\n");
		tmp = tmp->next;
	}
}

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	ft_free_list(t_struct *o)
{
	int	i;

	i = -1;
	while (o->list)
	{
		free(o->list->content);
		free(o->list);
		o->list = o->list->next;
	}
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
}

int	open_file(char *av, t_struct *o)
{
	int		fd;
	char	*input;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		input = ft_gnl(fd);
		if (!input || !input[0])
			break ;
		if (!o->list)
			o->list = ft_lstnew(ft_strdup(input));
		else
			ft_lstadd_back(&o->list, ft_lstnew(ft_strdup(input)));
		free(input);
	}
	free(input);
	return (0);
}

int	check_format(int ac, char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (len <= 3 || (ft_strncmp(av[1] + (len - 3), ".rt", 3)) != 0)
		return (1);
	if (ac == 3 && (ft_strlen(av[2]) != 6 || ft_strncmp(av[2], "--save", 6)))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_struct	o;

	if (ac != 2 && ac != 3)
		return (write(2, "bad arguments\n", 14));
	if (check_format(ac, av))
		return (write(2, "bad format\n", 11));
	if (open_file(av[1], &o))
		return (write(2, "bad file\n", 9));
	o.lst_size = ft_lstsize(o.list);
	if (!o.lst_size)
		return (ft_free_list(&o), write(2, "no arguments\n", 13));
	if (parsing(&o))
		return (ft_free_list(&o), write(2, "invalid parse\n", 14));
	cycle_cams(&o);
	print_lists(&o);
	ft_free_list(&o);
	return (0);
}
