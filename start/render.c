/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:36:25 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/04 12:34:02 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	render(t_struct *o)
{
	o->y = -o->height / 2;
	o->img = mlx_new_image(o->mlx_ptr, o->width, o->height);
	o->addr = mlx_get_data_addr(o->img, &o->bpp, &o->line_lenght, &o->endian);
	while (++o->y < o->height / 2 - 1)
	{
		o->x = -o->width / 2;
		while (++o->x < o->width / 2 - 1)
		{
			mlx_pixel_put(o->mlx_ptr, o->win_ptr, o->x + o->width / 2, o->y + o->height / 2, 0xFFFFFF);
		}
	}
}
