/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:39:53 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/07 10:18:33 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../includes/minirt.h"

void	print_guide(void)
{
	printf("Camera: W,A,S,D move the cam. ");
	printf("Q and E raise and lower the cam.\n");
	printf("Light: Num 8,4,5,6 move the light. ");
	printf("Num 7 and 9 raise and lower the light.\n");
}

void	check_parse(t_scene *sc)
{
	if (!sc->obj_list)
		exit_program("No figures\n");
	if (!sc->camera)
		exit_program("No camera\n");
	if (!sc->f_light)
		exit_program("No light\n");
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
		exit_program("Allocation impossible\n");
	the_show->mlx_ptr = mlx_init();
	the_show->mlx_img = mlx_new_image(the_show->mlx_ptr, sc->width, sc->height);
	the_show->data = mlx_get_data_addr(the_show->mlx_img,
			&the_show->bpp, &the_show->size_line, &the_show->endian);
	the_show->win_ptr = mlx_new_window(the_show->mlx_ptr, sc->width,
			sc->height, "miniRT");
	the_show->bpp = 600;
	return (the_show);
}

int	main(int argc, char **argv)
{
	int			fd;
	char		*file_str;
	t_scene		*sc;

	if (argc < 2 || argc > 3 || file_error(argc, argv))
		exit_program("Wrong Arguments\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_program("No read or find file\n");
	file_str = ft_read(fd);
	if (!ft_strlen(file_str))
		exit_program("Invalid arguments\n");
	sc = init_struct();
	parsing(file_str, sc);
	check_all(sc);
	sc->the_show = init_mlx(sc);
	if (put_image(sc))
		exit_program("Invalid put image\n");
	mlx_hook(sc->the_show->win_ptr, 2, 1L, key_hook, sc);
	mlx_hook(sc->the_show->win_ptr, 17, 1L, exit_program, NULL);
	print_guide();
	mlx_loop(sc->the_show->mlx_ptr);
	return (0);
}
