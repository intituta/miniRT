/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:43:14 by kferterb          #+#    #+#             */
/*   Updated: 2022/05/31 11:44:33 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_camera	*new_cam(t_v *origin, t_v *direction, float fov)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		error_exit(-1);
	cam->origin = origin;
	cam->direction = direction;
	cam->fov = fov;
	return (cam);
}
