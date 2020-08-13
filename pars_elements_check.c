/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_elements_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:44:22 by coline            #+#    #+#             */
/*   Updated: 2020/08/07 16:47:45 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_texture_path(char *path)
{
	int		fd;
	char	buf[1];
	int		ret;

	fd = open(path, O_RDONLY);
	ret = read(fd, buf, 1);
	if (ret <= -1)
		return (2);
	if (ret == 0)
		return (1);
	close(fd);
	return (0);
}

int		check_format_rgb(char *line)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (line && line[i] && j < 3)
	{
		while (ft_isdigit(line[i]) && j < 3)
			i++;
		if (line[i] == ',' && j < 2)
			i++;
		else if (j == 2)
			break ;
		else
			return (-1);
		j++;
	}
	while (line[i] == ' ')
		i++;
	if (!line[i])
		return (0);
	return (-1);
}
