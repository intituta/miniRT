/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:33:38 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/08 12:12:17 by kferterb         ###   ########.fr       */
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
int		parsing(t_struct *o);

#endif
