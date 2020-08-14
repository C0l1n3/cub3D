/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:27:51 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/13 17:20:50 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**int		stop_sounds(void)
**{
**	return (system("(" KILL_COMMAND " " PLAYER " )" OPTIONS));
**}
**
**int		play_sound(char *path)
**{
**	char	command[1000];
**
**	ft_bzero(command, 1000);
**	ft_strlcat(command, "(" PLAYER " ", 1000);
**	ft_strlcat(command, path, 1000);
**	ft_strlcat(command, BACKGROUND ") " OPTIONS, 1000);
**	return (system(command));
**}
*/

int		find_wall_dir(t_cub *cub)
{
	if (cub->game.player.v_angle >= 0 && cub->game.player.v_angle <= 180
	&& cub->game.player.h_dist <= cub->game.player.v_dist)
		return (0);
	else if (cub->game.player.v_angle > 180 && cub->game.player.v_angle <= 360
	&& cub->game.player.h_dist < cub->game.player.v_dist)
		return (1);
	else if (cub->game.player.v_angle >= 90 && cub->game.player.v_angle <= 270
	&& cub->game.player.h_dist > cub->game.player.v_dist)
		return (2);
	else
		return (3);
}

int		fill_walls(t_cub *cub)
{
	double	ray;
	int		i;

	i = 0;
	cub->game.player.v_angle = (cub->game.player.o_angle + 30 <= 360) ?
	cub->game.player.o_angle + 30 : cub->game.player.o_angle + 30 - 360;
	while (i < cub->win.r_width)
	{
		find_ignore_angle(cub);
		ray = cast(cub) * cos(degree_to_radian(ft_abs(cub->game.player.o_angle
		- cub->game.player.v_angle)));
		ray = ((cub->win.block_size / ray) *
		((cub->win.r_width / 2) / tan(degree_to_radian(30))));
		fill_ray(cub, i, find_wall_dir(cub), ray);
		(cub->game.player.v_dist < cub->game.player.h_dist) ?
		touch_sprite(cub, i, cub->game.player.new_unit_v_co) :
		touch_sprite(cub, i, cub->game.player.new_unit_h_co);
		process_sub_angle(cub, i);
		i++;
	}
	return (0);
}

void	process_sub_angle(t_cub *cub, int i)
{
	double	temp_angle;
	double	test;

	temp_angle =
	(cub->game.player.o_angle + 30 > 360) ?
	(cub->game.player.o_angle + 30 - 360) - cub->game.player.v_angle
	: cub->game.player.o_angle + 30 - cub->game.player.v_angle;
	test = atan(0.5 - ((double)i / cub->win.r_width)) * 180 / M_PI;
	cub->game.sub_angle = 30 - temp_angle - test;
	cub->game.player.v_angle = cub->game.player.v_angle - cub->game.sub_angle;
	if (cub->game.player.v_angle < 0)
		cub->game.player.v_angle = 360 - ft_abs(cub->game.player.v_angle);
}

int		fill_ray(t_cub *cub, int i, int d, double wall)
{
	int			j;
	int			start;
	double		ratio[2];
	double		pixel;
	int			color;

	j = 0;
	ratio[0] = (double)cub->map.tex[d].width / cub->win.block_size;
	ratio[1] = (double)cub->map.tex[d].height / wall;
	start = wall > cub->win.r_height ? 0 : (cub->win.r_height -
	wall) * 0.5;
	pixel = wall > cub->win.r_height ?
	(wall - cub->win.r_height) * 0.5 * ratio[1] : 0;
	while (j < cub->win.r_height && j < wall)
	{
		color = (int)pixel * cub->map.tex[d].width +
		(int)(cub->game.player.pos_on_wall * ratio[0]) - 1 > 0 ?
		cub->map.tex[d].data[((int)pixel * cub->map.tex[d].width +
		(int)(cub->game.player.pos_on_wall * ratio[0]) - 1)]
		: cub->map.tex[d].data[cub->map.tex[d].width];
		cub->win.base.data[(start + j) * cub->win.r_width + i] = color;
		pixel += ratio[1];
		j++;
	}
	return (1);
}
