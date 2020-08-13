/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_get_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 19:18:45 by coline            #+#    #+#             */
/*   Updated: 2020/08/13 17:34:51 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_elements(t_cub *cub)
{
	char	*line;
	int		ret;
	int		line_num;

	line_num = 1;
	while ((ret = get_next_line(cub->map.fd, &line)) >= 0)
	{
		if (line && *line != '\0')
		{
			if (ismapline(line))
				break ;
			if (get_id(line, cub, line_num))
			{
				ft_free_safe(&line);
				return (-1);
			}
		}
		ft_free_safe(&line);
		line_num++;
	}
	if (!(check_all_info(&line, cub)))
		return (0);
	ft_free_safe(&line);
	return (1);
}

int		ismapline(char *line)
{
	int	i;

	i = 0;
	while (line && ischarmap(line[i]) >= 0)
		i++;
	if (line[i] == 0)
		return (1);
	return (0);
}

int		get_info(char *line, t_cub *cub, int line_num)
{
	int	i;

	i = 0;
	while (line && line[i] == ' ')
		i++;
	if (line[i] == 'R')
		return (process_res(line, i + 1, cub, line_num));
	else if (line[i] == 'F' || line[i] == 'C')
		return (process_color(line, i + 1, cub, line_num));
	else
		return (process_texture(line, i + 1, cub, line_num));
}

int		get_id(char *line, t_cub *cub, int line_num)
{
	int	ret;

	if ((ret = check_is_id(line, cub)))
	{
		if (ret == 1)
			return (ft_error(2, line_num, "", cub));
		else if (ret == 2)
			return (ft_error(3, 0, cub->win.error, cub));
	}
	else if (get_info(line, cub, line_num))
		return (-1);
	return (0);
}
