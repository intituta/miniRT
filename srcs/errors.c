/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:39:11 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/06 12:59:49 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	operate_key_press(int key, t_scene *sc)
{	
	if (key == 53)
		exit(0);
	else if (key == 12)
		sc->camera->coord.y = sc->camera->coord.y - 1;
	else if (key == 14)
		sc->camera->coord.y = sc->camera->coord.y + 1;
	else if (key == 13)
		sc->camera->coord.z = sc->camera->coord.z - 1;
	else if (key == 1)
		sc->camera->coord.z = sc->camera->coord.z + 1;
	else if (key == 0)
		sc->camera->coord.x = sc->camera->coord.x - 1;
	else if (key == 2)
		sc->camera->coord.x = sc->camera->coord.x + 1;
	if (put_image(sc))
		exit_program("Error\nInvalid put image\n");
}

int	exit_program(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

int	color_error(int *col)
{
	if (col[0] < 0 || col[0] > 255)
		return (1);
	if (col[1] < 0 || col[1] > 255)
		return (1);
	if (col[2] < 0 || col[2] > 255)
		return (1);
	return (0);
}

int	object_error(t_objs *this)
{
	t_v3	aux;

	initialize_v3(&aux);
	if (color_error(this->color))
		return (1);
	if (this->type == 'p' || this->type == 'c')
	{
		if (distance3(this->or, aux) > 1
			|| distance3(this->or, aux) < -1
			|| distance3(this->or, aux) == 0)
			return (1);
	}
	if ((this->type == 'c' || this->type == 's') && this->params.x <= 0)
		return (1);
	if (this->type == 'c' && this->params.y <= 0)
		return (1);
	return (0);
}

int	file_error(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2 || !argv[1])
		return (1);
	while (argv[1][i])
		i++;
	if (argv[1][i - 3] != '.' || argv[1][i - 2] != 'r' || argv[1][i - 1] != 't')
		return (1);
	return (0);
}
