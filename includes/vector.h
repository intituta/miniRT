/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:40:40 by kferterb          #+#    #+#             */
/*   Updated: 2022/05/30 16:40:28 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_v
{
	float	x;
	float	y;
	float	z;
}	t_v;

void	vec_normalize(t_v *v);

float	vec_length(t_v *v);
float	vec_dot_product(t_v *v1, t_v *v2);

t_v		*vec_substract(t_v *v1, t_v *v2);
t_v		*new_vector(float x, float y, float z);

#endif
