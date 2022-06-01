/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:25:21 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/01 18:27:30 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_tracing(void *mlx, void *window, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y;
	int			color;
	float		x_angle;
	float		y_angle;
	float		x_ray;
	float		y_ray;
	t_v			*ray;
	t_vplane	*vplane;

	mlx_y = 0;
	vplane = get_view_plane(scene->width, scene->height, scene->cams->fov);
	y_angle = (scene->height / 2);
	while (y_angle >= (scene->height / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vector(x_ray, y_ray, -1);
			vec_normalize(ray);
			if (sphere_intersect(scene->cams, ray, scene->sphere))
				color = 16317995;
			else
				color = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			//printf("mlx_x = %d mlx_y = %d\n", mlx_x, mlx_y);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}

t_vplane	*get_view_plane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	fov = 1;
	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		error_exit(-1);
	aspect_ratio = width / height;
	vplane->width = 1;
	//vplane->width = tan(fov / 2 * (M_PI / 180));
	//vplane->width *= 2;
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}
