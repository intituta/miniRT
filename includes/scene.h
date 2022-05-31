/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:49:03 by kferterb          #+#    #+#             */
/*   Updated: 2022/05/31 14:19:08 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct s_scene
{
	t_camera	*cams;
	t_sphere	*sphere;
	float		width;
	float		height;
}	t_scene;

t_scene	*new_scene(t_camera *cam, t_sphere *sphere);

#endif
