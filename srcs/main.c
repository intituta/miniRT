/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:26:57 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/01 18:00:07 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	void		*mlx;
	void		*window;
	t_v			*sphere_center;
	t_sphere	*sphere;
	t_v			*cam_origin;
	t_camera	*cam;
	t_v			*cam_direction;
	t_scene		*scene;

	mlx = mlx_init();
	sphere_center = new_vector(0, 0, -30);
	sphere = new_sphere(sphere_center, 12 / 2);
	cam_origin = new_vector(0, 0, 0);
	cam_direction = new_vector(0, 0, -1);
	cam = new_cam(cam_origin, cam_direction, 70);
	scene = new_scene(cam, sphere);
	scene->width = 800;
	scene->height = 600;
	window = mlx_new_window(mlx, scene->width, scene->height, "EXPERIMENT");
	ray_tracing(mlx, window, scene);
	//free_scene(scene);
	mlx_loop(mlx);
	return (0);
}
