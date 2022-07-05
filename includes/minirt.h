/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:38:03 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/05 16:14:48 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define WIDTH 800
# define HEIGHT 600
# define ESC_KEY 65307
# define INF 2147483647
# define BUFFER_SIZE 128
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx/mlx.h"

typedef struct s_v3
{
	double	x;
	double	y;
	double	z;
}	t_v3;

typedef struct s_show
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}	t_mlx_show;

typedef struct s_objs
{
	char			type;
	t_v3			coord;
	t_v3			or;
	t_v3			params;
	t_v3			normal;
	int				*color;
	struct s_objs	*next;
}	t_objs;

typedef struct scene
{
	int				height;
	t_v3			up_v;
	int				width;
	double			a_lum;
	int				*a_color;
	t_objs			*obj_list;
	t_objs			*camera;
	t_objs			*f_light;
}	t_scene;

char			*read_everything(int fd);
int				process_everything(char *all, t_scene	*this_scene);
int				process_ambiance(t_scene *sc, char *begin);
int				process_camera(t_scene *sc, char *begin);
int				process_light(t_scene *sc, char *begin);
int				process_object(t_scene *sc, char *begin);
char			*get_some_d(t_v3 *things, int how_many, char *where_from);
char			*get_some_i(int *things, int how_many, char *where_from);

t_objs			*push_new_object(t_objs **begin_list);
t_v3			v_dup(t_v3 this);
void			initialize_v3(t_v3 *this);

int				object_error(t_objs *this);
int				check_all(t_scene *sc);
int				exit_program(char *str);
int				operate_key_press(int key);
int				color_error(int *col);
int				file_error(int argc, char **argv);

char			**ft_split(char const *s, char c);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*advance_through(char *this);
double			ft_strtod(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*concat_here(char *str1, char *str2, int read);
void			ft_putstr_fd(char *s, int fd);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isspace(char c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

t_v3			cross_product(t_v3 one, t_v3 other);
double			dot_p(t_v3 one, t_v3 other);
t_v3			scale_v(t_v3 v, double n);
t_v3			sub(t_v3 one, t_v3 other);
t_v3			normalize(t_v3 these3);
double			**compute_rotation(t_v3 orig, t_v3 dir, t_v3 up_v);
t_v3			rotate_cam(t_v3 origin, t_v3 trans, t_v3 up_v);
double			inter_sphere(t_v3 origin, t_v3 ray, t_objs *object);
double			inter_plane(t_v3 origin, t_v3 ray, t_objs *object);
double			inter_cylinder(t_v3 origin, t_v3 ray, t_objs *object);
t_v3			add_v(t_v3 one, t_v3 other);
double			distance3(t_v3 one, t_v3 other);
double			compute_plane(t_v3 origin, t_v3 ray, t_objs *obj,
					int procedure);
double			vcos(t_v3 a, t_v3 b);

int				put_it_on(t_scene *scene_now, t_mlx_show *the_show);
int				*get_color(t_v3 origin, t_v3 ray, t_objs *inter, t_scene *sc);
#endif