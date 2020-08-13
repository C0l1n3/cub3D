/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_id_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:29:33 by coline            #+#    #+#             */
/*   Updated: 2020/08/13 17:43:24 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_error(t_cub *cub, char id)
{
	if (id == 'R')
		cub->win.error = "RESOLUTION";
	if (id == 'N')
		cub->win.error = "NORTH";
	if (id == 'S')
		cub->win.error = "SOUTH";
	if (id == 'E')
		cub->win.error = "EAST";
	if (id == 'W')
		cub->win.error = "WEST";
	if (id == 'C')
		cub->win.error = "CEILING";
	if (id == 'F')
		cub->win.error = "FLOOR";
	if (id == 'P')
		cub->win.error = "SPRITE";
}

int		check_multiple_id(char id, t_cub *cub)
{
	if ((id == 'R' && cub->win.r_width != -1)
	|| (id == 'C' && cub->map.c_color != -1)
	|| (id == 'F' && cub->map.f_color != -1)
	|| (id == 'P' && cub->map.text[4])
	|| (id == 'S' && cub->map.text[1])
	|| (id == 'N' && cub->map.text[0])
	|| (id == 'E' && cub->map.text[2])
	|| (id == 'W' && cub->map.text[3]))
	{
		fill_error(cub, id);
		return (1);
	}
	return (0);
}

int		missing_id(t_cub *cub)
{
	if (!cub->map.text[1] || !cub->map.text[0] || !cub->map.text[2]
	|| !cub->map.text[3] || !cub->map.text[4] || cub->map.c_color == -1
	|| cub->map.f_color == -1 || cub->win.r_width == -1)
	{
		if (cub->win.r_width == -1)
			cub->win.error = "RESOLUTION";
		else if (!cub->map.text[1])
			cub->win.error = "SOUTH";
		else if (!cub->map.text[2])
			cub->win.error = "EAST";
		else if (!cub->map.text[0])
			cub->win.error = "NORTH";
		else if (!cub->map.text[3])
			cub->win.error = "WEST";
		else if (cub->map.c_color == -1)
			cub->win.error = "CEILING";
		else if (cub->map.f_color == -1)
			cub->win.error = "FLOOR";
		else if (!cub->map.text[4])
			cub->win.error = "SPRITE";
		return (-1);
	}
	return (0);
}

int		check_is_id(char *line, t_cub *cub)
{
	int		i;
	char	id;

	i = 0;
	while (line && line[i] == ' ')
		i++;
	id = line[i];
	if (line[i] == 'S' && line[i + 1] == ' ')
		id = 'P';
	if (((line[i] == 'R' || line[i] == 'C' || line[i] == 'F' || line[i] == 'S')
	&& line[i + 1] == ' ')
	|| (((line[i] == 'S' && line[i + 1] == 'O')
	|| (line[i] == 'E' && line[i + 1] == 'A')
	|| (line[i] == 'W' && line[i + 1] == 'E')
	|| (line[i] == 'N' && line[i + 1] == 'O')) && ((line[i + 2] == ' '
	|| line[i + 2] == 0))))
	{
		if (check_multiple_id(id, cub))
			return (2);
		else
			return (0);
	}
	return (1);
}

int		check_all_info(char **line, t_cub *cub)
{
	int i;

	i = 0;
	while (*line[i] == ' ')
		i++;
	if (!(ischarmap(*line[i])) && missing_id(cub))
		return (ft_error(10, 0, cub->win.error, cub));
	else if (missing_id(cub))
		return (1);
	cub->map.map_lines = lstcharnew(*line);
	ft_free_safe(line);
	return (0);
}
