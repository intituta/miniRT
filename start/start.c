/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:34:25 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/04 19:46:30 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	quit(void)
{
	exit(0);
}

int	ft_key_hook(int key, t_struct *o)
{
	if (key == 53)
		exit(0);
	// if (key == 48)
	// 	ft_change_cam(o);
}

void	start(t_struct *o)
{
	o->mlx_ptr = mlx_init();
	o->win_ptr = mlx_new_window(o->mlx_ptr, o->w_width, o->w_height, "miniRT");
	render(o);
	mlx_hook(o->win_ptr, 2, 1L, ft_key_hook, o);
	mlx_hook(o->win_ptr, 17, 0L, &quit, NULL);
	mlx_loop(o->mlx_ptr);
}
