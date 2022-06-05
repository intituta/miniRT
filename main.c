/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:26:57 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/05 12:53:22 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int	open_file(char *av, t_list *list)
{
	int		fd;
	char	*input;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		input = ft_gnl(fd);
		if (!input || !input[0])
			break ;
		free(input);
	}
	free(input);
	return (0);
}

int	check_format(int ac, char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (len <= 3 || (ft_strncmp(av[1] + (len - 3), ".rt", 3)) != 0)
		return (1);
	if (ac == 3 && (ft_strlen(av[2]) != 6 || ft_strncmp(av[2], "--save", 6)))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	list;

	if (ac != 2 && ac != 3)
		return (write(2, "bad arguments\n", 14));
	if (check_format(ac, av))
		return (write(2, "bad arguments\n", 14));
	if (open_file(av[1], &list))
		return (write(2, "bad file\n", 9));
	return (0);
}
