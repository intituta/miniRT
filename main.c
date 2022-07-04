/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:26:57 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/04 20:23:20 by kferterb         ###   ########.fr       */
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
		if (tmp->id[0] == 's' && tmp->id[1] == 'p')
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
	tmp = o->ambient_light;
	while (tmp)
	{
		if (tmp->id[0] == 'A')
			print_a(tmp);
		printf("======Ambient=====\n");
		tmp = tmp->next;
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
		if (!input)
			break ;
		if (input[0] == '\0')
		{
			free(input);
			continue ;
		}
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

void	init_struct(t_struct *o)
{
	o->w_width = 800;
	o->w_height = 600;
	o->lst_size = 0;
	o->cam_lst_size = 0;
	o->xyz = NULL;
	o->cams = NULL;
	o->list = NULL;
	o->strs = NULL;
	o->lights = NULL;
	o->figures = NULL;
	o->mlx_ptr = NULL;
	o->win_ptr = NULL;
	o->view_plane = NULL;
	o->ambient_light = NULL;
}

int	main(int ac, char **av)
{
	t_struct	o;

	init_struct(&o);
	if (ac != 2 && ac != 3)
		return (write(2, "bad arguments\n", 14));
	if (check_format(ac, av))
		return (write(2, "bad format\n", 11));
	if (open_file(av[1], &o))
		return (write(2, "bad file\n", 9));
	o.lst_size = ft_lstsize(o.list);
	if (!o.lst_size)
		return (free_list(&o), write(2, "invalid arguments\n", 18));
	if (parsing(&o))
		return (free_list(&o), write(2, "invalid parse\n", 14));
	if (ft_lstsize(o.ambient_light) != 1)
		return (free_list(&o), write(2, "invalid ambient\n", 16));
	if (o.cam_lst_size <= 0)
		return (free_list(&o), write(2, "no camera\n", 10));
	if (ft_lstsize(o.figures) <= 0)
		return (free_list(&o), write(2, "no figures\n", 11));
	//print_lists(&o);
	start(&o);
	free_list(&o);
	return (0);
}
