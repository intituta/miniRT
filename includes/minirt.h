/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:33:38 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/09 20:33:14 by kferterb         ###   ########.fr       */
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

# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_struct
{
	int		lst_size;
	char	**strs;
	t_list	*list;
	t_list	*final_list;
}	t_struct;

char	*ft_gnl(int fd);

void	ft_free(char **strs);
void	create_list(t_struct *o);
void	ft_rgb(t_list *tmp, char **rgb);
void	ft_xyz(t_list *tmp, char **xyz);

int		parsing(t_struct *o);
int		parse_a(t_struct *o);
int		parse_c(t_struct *o);
int		ft_check_count(char **strs, int count);

#endif
