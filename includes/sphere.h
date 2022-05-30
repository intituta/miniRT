/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:20:22 by kferterb          #+#    #+#             */
/*   Updated: 2022/05/30 18:39:22 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

typedef struct s_sphere
{
	t_v		*center;
	float	radius;
}	t_sphere;

t_sphere	*new_sphere(t_v *center, float radius);

#endif
