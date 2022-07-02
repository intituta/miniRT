/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:33:38 by kferterb          #+#    #+#             */
/*   Updated: 2022/07/02 20:19:36 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "../minilibx/mlx.h"
# include "../libft/libft.h"

typedef struct s_struct
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	float	x;
	float	y;
	int		bpp;
	int		width;
	int		height;
	int		endian;
	int		lst_size;
	int		local_color;
	int		line_lenght;
	int		cam_lst_size;
	char	*addr;
	char	**xyz;
	char	**strs;
	t_list	*list;
	t_list	*cams;
	t_list	*lights;
	t_list	*figures;
	t_list	*ambient_light;
}	t_struct;

char	*ft_gnl(int fd);
char	**split_mod(char const *s);

t_list	*create_list(t_list *list);

void	start(t_struct *o);
void	render(t_struct *o);
void	ft_free(char **strs);
void	free_list(t_struct *o);
void	cycle_cams(t_struct *o);
void	rgb(t_list *tmp, char **rgb);
void	xyz(t_list *tmp, char **xyz);
void	normalize(t_list *tmp, char **xyz);

int		set_checker(char c);
int		parsing(t_struct *o);
int		parse_a(t_struct *o);
int		parse_c(t_struct *o);
int		parse_l(t_struct *o);
int		parse_sp(t_struct *o);
int		parse_pl(t_struct *o);
int		parse_cy(t_struct *o);
int		check_count(char **strs, int count);

double	ft_atof(char *str);

#endif
