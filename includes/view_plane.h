/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_plane.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:00:05 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/01 16:06:55 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_PLANE_H
# define VIEW_PLANE_H

typedef struct s_vplane
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}	t_vplane;

t_vplane	*get_view_plane(float width, float height, float fov);
void		ray_tracing(void *mlx, void *window, t_scene *scene);
int			sphere_intersect(t_camera *cam, t_v *ray, t_sphere *sphere);

#endif
