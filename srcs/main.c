/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:39:53 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/05 18:49:03 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../includes/minirt.h"

void	check_parse(t_scene *sc)
{
	if (!sc->obj_list)
		exit_program("Error\nNo figures\n");
	if (!sc->camera)
		exit_program("Error\nNo camera\n");
	if (!sc->f_light)
		exit_program("Error\nNo light\n");
}

t_scene	*init_struct(void)
{
	t_scene	*new_sc;

	new_sc = malloc(sizeof(t_scene));
	if (!new_sc)
		return (NULL);
	new_sc->up_v.x = 0;
	new_sc->up_v.z = 0;
	new_sc->a_lum = -1;
	new_sc->up_v.y = -1;
	new_sc->camera = NULL;
	new_sc->f_light = NULL;
	new_sc->obj_list = NULL;
	new_sc->width = WIDTH;
	new_sc->height = HEIGHT;
	new_sc->a_color = ft_calloc(3, sizeof(int));
	return (new_sc);
}

t_mlx_show	*init_mlx(t_scene *sc)
{
	t_mlx_show		*the_show;

	the_show = malloc(sizeof(t_mlx_show));
	if (!the_show)
		exit_program("Error\nAllocation Impossible\n");
	the_show->mlx_ptr = mlx_init();
	the_show->mlx_img = mlx_new_image(the_show->mlx_ptr, sc->width, sc->height);
	the_show->data = mlx_get_data_addr(the_show->mlx_img,
			&the_show->bpp, &the_show->size_line, &the_show->endian);
	the_show->win_ptr = mlx_new_window(the_show->mlx_ptr, sc->width,
			sc->height, "miniRT");
	mlx_hook(the_show->win_ptr, 2, (1L << 0), operate_key_press, NULL);
	mlx_hook(the_show->win_ptr, 17, (1L << 17), exit_program, NULL);
	the_show->bpp = 600;
	return (the_show);
}

void	start(t_mlx_show *the_show)
{
	mlx_clear_window(the_show->mlx_ptr, the_show->win_ptr);
	mlx_put_image_to_window(the_show->mlx_ptr, the_show->win_ptr,
		the_show->mlx_img, 0, 0);
	mlx_loop(the_show->mlx_ptr);
}

int	main(int argc, char **argv)
{
	int			fd;
	char		*file_str;
	t_scene		*sc_now;
	t_mlx_show	*the_show;

	if (argc < 2 || argc > 3 || file_error(argc, argv))
		exit_program("Error\nWrong Arguments\nUsage: ./miniRT *.rt\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_program("Error\nCouln't read or find file\n");
	file_str = ft_read(fd);
	if (!ft_strlen(file_str))
		exit_program("Error\nInvalid arguments\n");
	sc_now = init_struct();
	parsing(file_str, sc_now);
	free(file_str);
	check_all(sc_now);
	the_show = init_mlx(sc_now);
	put_image(sc_now, the_show);
	if (argc == 2)
		start(the_show);
	exit(0);
}
