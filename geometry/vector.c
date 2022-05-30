/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:44:15 by kferterb          #+#    #+#             */
/*   Updated: 2022/05/30 18:56:26 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v	*new_vector(float x, float y, float z)
{
	t_v	*v;

	v = malloc(sizeof(t_v));
	if (!v)
		error_exit(-1);
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_v	*vec_substract(t_v *v1, t_v *v2)
{
	t_v	*res;

	res = new_vector(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
	return (res);
}

float	vec_length(t_v *v)
{
	float	res;

	res = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	return (res);
}

void	vec_normalize(t_v *v)
{
	float	len;

	len = vec_length(v);
	v->x /= len;
	v->y /= len;
	v->z /= len;
}

float	vec_dot_product(t_v *v1, t_v *v2)
{
	float	res;

	res = ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
	return (res);
}
