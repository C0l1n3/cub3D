/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:36:18 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/15 17:07:03 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_screen_size(t_cub *cub)
{
	int	width;
	int height;

	mlx_get_screen_size(cub->win.mlx_ptr, &width, &height);
	if (cub->win.r_width > width || cub->win.r_height > height)
	{
		if (cub->win.r_width > width)
			cub->win.r_width = width;
		if (cub->win.r_height > height)
			cub->win.r_height = height;
	}
	return (0);
}

int		ft_error(int code, int line, char *id, t_cub *cub)
{
	ft_printf("ERROR,\n");
	if (code == 1)
		ft_printf("Arguments not valid\n");
	else if (code == 2)
		ft_printf("Wrong type identifier line %d\n", line);
	else if (code == 3)
		ft_printf("%s is set more than once\n", id);
	else if (code == 4)
		ft_printf("Resolution NULL or negative\n");
	else if (code == 5)
		ft_printf("Resolution must be format [R 1920 1080] line %d\n", line);
	else if (code == 6)
		ft_printf("C or F must be format [255,255,255] line %d\n", line);
	else if (code == 7)
		ft_printf("No path found for texture line %d\n", line);
	else if (code == 8)
		ft_printf("Could not find texture line %d\n", line);
	else if (code == 9)
		ft_printf("Nothing foudn in file %s\n", id);
	else if (code == 10)
		ft_printf("Type identifier %s is missing\n", id);
	ft_free_cub(cub);
	return (-1);
}

int		ft_error_two(int code, t_cub *cub)
{
	ft_printf("ERROR\n");
	if (code == 0)
		ft_printf("ARGUMENTS NOT VALID\n");
	if (code == 1)
		ft_printf("Incorrect char in map\n");
	if (code == 2)
		ft_printf("Your map has only one or no line/column\n");
	if (code == 3)
		ft_printf("Your map is either open\n");
	if (code == 4)
		ft_printf("You have too many or no hero, you fool...\n");
	if (code == 5)
		ft_printf("The file you have mentionned does not exist\n");
	if (code == 6)
		ft_printf("There is an empty line at the end of the map\n");
	ft_free_cub(cub);
	return (-1);
}

void	ft_free_cub(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->map.map_tab)
	{
		while (i < cub->map.m_height)
		{
			free_safe((void**)&(cub->map.map_tab[i]));
			i++;
		}
		free_safe((void**)&(cub->map.map_tab));
	}
	free_safe((void**)&(cub->map.sprites));
	if (cub->map.text)
	{
		i = 0;
		while (i < 5)
		{
			free_safe((void**)&(cub->map.text[i]));
			i++;
		}
		free_safe((void**)&(cub->map.text));
	}
	free_lstchar(cub->map.map_lines);
}

int		extension(char *str)
{
	char	*cub;

	cub = ".cub";
	while ((str = ft_strnstr(str, cub, ft_strlen(str))))
	{
		if (!str[4])
			return (0);
		str++;
	}
	return (-1);
}
