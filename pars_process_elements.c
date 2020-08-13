/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_process_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:25:16 by coline            #+#    #+#             */
/*   Updated: 2020/08/13 16:24:14 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		process_res(char *line, int i, t_cub *cub, int l)
{
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
		cub->win.r_width = mini_atoi(line, &i);
	else
		return (ft_error(5, l, "", cub));
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
		cub->win.r_height = mini_atoi(line, &i);
	else
		return (ft_error(5, l, "", cub));
	if (cub->win.r_width < 0 || cub->win.r_height < 0)
		return (1);
	while (line[i] == ' ')
		i++;
	if (line[i] != 0)
		return (ft_error(5, l, "", cub));
	return (0);
}

int		process_color(char *line, int i, t_cub *cub, int l)
{
	char	c_f;
	int		rgb[3];
	int		j;
	char	*temp;

	c_f = (line[i - 1] == 'C') ? 'C' : 'F';
	j = 0;
	while (line[i] == ' ')
		i++;
	temp = ft_strtrim(line + i, " ");
	if (check_format_rgb(temp) == -1)
		return (ft_error(6, l, "", cub));
	i = 0;
	while (temp && temp[i] && j < 3)
	{
		rgb[j] = mini_atoi(temp, &i);
		if (temp[i])
			i++;
		if (rgb[j] < 0 || rgb[j] > 255)
			return (ft_error(6, l, "", cub));
		j++;
	}
	free(temp);
	fill_color(c_f, cub, rgb);
	return (0);
}

void	fill_color(char c, t_cub *cub, int *rgb)
{
	if (c == 'C')
		cub->map.c_color = ft_rgb_to_int(rgb[0], rgb[1], rgb[2]);
	else if (c == 'F')
		cub->map.f_color = ft_rgb_to_int(rgb[0], rgb[1], rgb[2]);
}

int		find_dir(char *line, int i)
{
	if (line[i - 1] == 'S' && line[i] == 'O')
		return (1);
	if (line[i - 1] == 'S' && line[i] == ' ')
		return (4);
	if (line[i - 1] == 'N')
		return (0);
	if (line[i - 1] == 'E')
		return (2);
	if (line[i - 1] == 'W')
		return (3);
	return (-1);
}

int		process_texture(char *line, int i, t_cub *cub, int l)
{
	char	*path;
	int		dir;
	char	*temp;
	int		ret;

	ret = 0;
	dir = find_dir(line, i);
	if (line[i] == 'O' || line[i] == 'E' || line[i] == 'A')
		i++;
	while (line[i] == ' ')
		i++;
	temp = ft_substr(line, i, ft_strlen(line));
	if (!(path = ft_strtrim(temp, " ")))
		ret = ft_error(7, l, "", cub);
	else if (check_texture_path(path) == 2)
		ret = ft_error(8, l, "", cub);
	else if (check_texture_path(path) == 1)
		ret = ft_error(9, l, path, cub);
	if (!ret)
		cub->map.text[dir] = ft_strdup(path);
	ft_free_safe(&path);
	ft_free_safe(&temp);
	return (ret);
}
