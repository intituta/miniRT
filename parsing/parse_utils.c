/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:31:55 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/11 14:19:56 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	*ft_atof_utils(char *str, int *dot, int *count)
{
	int	i;
	int	*mass;

	i = -1;
	while (str[++i])
	{
		if ((str[i] < 48 && str[i] != 46) || str[i] > 58)
			exit(write(2, "error\n", 6));
		if (str[i] == 46)
			(*dot)++;
	}
	if (*dot > 1)
		exit (write(2, "error\n", 7));
	else if (*dot == 0)
		*dot = i;
	mass = malloc(sizeof(int *) * i - 1);
	*count = i;
	i = -1;
	while (str[++i])
		if (str[i] != 46)
			mass[i] = str[i] - 48;
	else
		*dot = i;
	return (mass);
}

double	ft_atof(char *str)
{
	int		i;
	int		count;
	int		*mass;
	int		flag[2];
	double	res;

	i = -1;
	res = 0;
	flag[0] = 0;
	flag[1] = 0;
	if (str[0] == '-')
	{
		free(str);
		str = ft_substr(str, 1, ft_strlen(str));
		flag[1] = 1;
	}
	mass = ft_atof_utils(str, &flag[0], &count);
	while (++i < flag[0])
		res = res + (double)mass[i] * (pow(10, flag[0] - i - 1));
	while (++i < count)
		res = res + (double)mass[i] * (pow(10, flag[0] - i - 1) * 10);
	if (flag[1])
		res = res * -1;
	return (free(mass), res);
}

void	ft_normalize(t_list *tmp, char **xyz)
{
	tmp->n_vec1 = ft_atof(xyz[0]);
	tmp->n_vec2 = ft_atof(xyz[1]);
	tmp->n_vec3 = ft_atof(xyz[2]);
	ft_free(xyz);
}

void	ft_rgb(t_list *tmp, char **rgb)
{
	tmp->r = ft_atoi(rgb[0]);
	tmp->g = ft_atoi(rgb[1]);
	tmp->b = ft_atoi(rgb[2]);
	ft_free(rgb);
}

void	ft_xyz(t_list *tmp, char **xyz)
{
	tmp->x = ft_atof(xyz[0]);
	tmp->y = ft_atof(xyz[1]);
	tmp->z = ft_atof(xyz[2]);
	ft_free(xyz);
}
