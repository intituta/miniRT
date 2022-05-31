/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:38:12 by kferterb          #+#    #+#             */
/*   Updated: 2022/05/31 11:45:03 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_camera
{
	t_v		*origin;
	t_v		*direction;
	float	fov;
}	t_camera;

t_camera	*new_cam(t_v *origin, t_v *direction, float fov);

#endif
