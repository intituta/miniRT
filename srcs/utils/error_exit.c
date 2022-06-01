/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:09:09 by kferterb          #+#    #+#             */
/*   Updated: 2022/05/30 18:16:47 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_exit(int code)
{
	if (code == -1)
		write(STDERR_FILENO, "Error: Can't allocate memory\n", 29);
	exit(code);
}
