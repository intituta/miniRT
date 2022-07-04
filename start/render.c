/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:36:25 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/04 21:45:39 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_list	*get_view_plane(float width, float height, float fov)
{
	t_list	*vplane;
	float	aspect_ratio;

	vplane = malloc(sizeof(t_list));
	if (!vplane)
		exit(write(2, "error malloc", 12));
	aspect_ratio = width / height;
	vplane->vp_width = tan(fov / 2 * (M_PI / 180));
	vplane->vp_width *= 2;
	vplane->vp_height = vplane->vp_width / aspect_ratio;
	vplane->vp_x_pixel = vplane->vp_width / width;
	vplane->vp_y_pixel = vplane->vp_height / height;
	return (vplane);
}

t_list	*new_vector(float x, float y, float z)
{
	t_list	*vec;

	vec = malloc(sizeof(t_list));
	if (!vec)
		exit(write(2, "error malloc", 12));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

float	vec_length(t_list *vec)
{
	float	result;

	result = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (result);
}

void	vec_normalize(t_list *vec)
{
	float	length;

	length = vec_length(vec);
	vec->x /= length;
	vec->y /= length;
	vec->z /= length;
}

t_list	*vec_substract(t_list *vec1, t_list *vec2)
{
	t_list	*result;

	result = new_vector(vec1->x - vec2->x,
			vec1->y - vec2->y, vec1->z - vec2->z);
	return (result);
}

float	vec_dot_product(t_list *vec1, t_list *vec2)
{
	float	result;

	result = ((vec1->x * vec2->x) + vec1->y * vec2->y + (vec1->z * vec2->z));
	return (result);
}

int	sphere_intersect(t_list *cam, t_list *ray, t_list *sphere)
{
	float	b;
	float	c;
	float	discr;
	float	dist_1;
	float	dist_2;
	t_list	*cam_sphere;

	dist_1 = 0;
	dist_2 = 0;
	cam_sphere = vec_substract(cam, sphere);
	b = 2 * (vec_dot_product(cam_sphere, ray));
	c = vec_dot_product(cam_sphere, cam_sphere) - (sphere->diametr * sphere->diametr);
	discr = (b * b) - (4 * c);
	free(cam_sphere);
	if (discr < 0)
		return (0);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) + sqrt(discr)) / 2;
	if (dist_1 > 0)
		return (1);
	return (0);
}

void	render(t_struct *o)
{
	float	x_angle;
	float	y_angle;
	int		mlx_x;
	int		mlx_y;
	float	y_ray;
	float	x_ray;
	int		color;

	mlx_y = 0;
	o->view_plane = get_view_plane(o->w_width, o->w_height, o->cams->fov);
	y_angle = o->w_height / 2;
	while (y_angle >= (o->w_height / 2) * (-1))
	{
		y_ray = y_angle * o->view_plane->vp_y_pixel;
		x_angle = (o->w_width / 2) * (-1);
		mlx_x = 0;
		while (x_angle <= o->w_width / 2)
		{
			x_ray = x_angle * o->view_plane->vp_x_pixel;
			o->ray = new_vector(x_ray, y_ray, -1);
			vec_normalize(o->ray);
			if (sphere_intersect(o->cams, o->ray, o->figures))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(o->mlx_ptr, o->win_ptr, mlx_x, mlx_y, color);
			free(o->ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}
