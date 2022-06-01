/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:04:56 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/01 16:28:52 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	sphere_intersect(t_camera *cam, t_v *ray, t_sphere *sphere)
{
	float		b;
	float		c;
	float		discr;
	float		dist_1;
	float		dist_2;
	t_v			*cam_sphere;

	dist_1 = 0;
	dist_2 = 0;
	cam_sphere = vec_substract(cam->origin, sphere->center);
	b = 2 * (vec_dot_product(cam_sphere, ray));
	c = vec_dot_product(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4 * c);
	if (discr < 0)
		return (0);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) - sqrt(discr)) / 2;
	if (dist_1 > 0)
		return (1);
	//free(cam_sphere);
	return (0);
}
