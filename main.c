/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:12:17 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/13 16:03:33 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	init_struct(&cub);
	if ((argc > 3 || argc < 2 || extension(argv[1]))
	|| (argc == 3 && ft_strncmp(argv[2], "--save", 6)))
		return (ft_error_two(0, &cub));
	cub.map.fd = open(argv[1], O_RDONLY);
	if (read(cub.map.fd, 0, 0) < 0)
		return (ft_error_two(5, &cub));
	if ((get_elements(&cub)) != 0 || get_map(&cub))
		return (-1);
	ft_printf("File Ok\n");
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		create_bmp(&cub);
	else
	{
		ft_cub(&cub);
		looping(&cub);
	}
	return (0);
}
