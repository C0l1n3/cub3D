/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 11:23:54 by coline            #+#    #+#             */
/*   Updated: 2020/08/04 17:02:43 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_empty(t_cub *cub, int x, int y)
{
	if (y < 0 || x < 0 || y >= cub->map.m_height || x >= cub->map.m_width)
		return (-1);
	if (cub->map.map_tab[y][x] != 1)
		return (0);
	return (1);
}

int		is_horizontal_angle(t_cub *cub, double angle)
{
	if (angle > cub->game.ignore_angle[2]
	&& angle < 180 - cub->game.ignore_angle[7])
		return (1);
	else if (angle > 180 + cub->game.ignore_angle[6]
	&& angle < 360 - cub->game.ignore_angle[3])
		return (1);
	return (0);
}

int		is_vertical_angle(t_cub *cub, double angle)
{
	if (angle >= 0 && angle < 90 - cub->game.ignore_angle[1])
		return (1);
	else if (angle > 270 + cub->game.ignore_angle[4]
	&& angle <= 360)
		return (1);
	else if (angle > 90 + cub->game.ignore_angle[0]
	&& angle < 270 - cub->game.ignore_angle[5])
		return (1);
	return (0);
}

double	cast(t_cub *cub)
{
	find_horizontal(cub);
	find_vertical(cub);
	cub->game.player.v_dist = 100000;
	cub->game.player.h_dist = 100000;
	dist_wall(cub);
	if (cub->game.player.h_dist < cub->game.player.v_dist)
		return (cub->game.player.h_dist);
	return (cub->game.player.v_dist);
}

void	dist_wall(t_cub *cub)
{
	double		sqr_o;
	double		sqr_t;

	if (is_empty(cub, cub->game.player.new_grid_v_co[0],
	cub->game.player.new_grid_v_co[1]) != -1 &&
	is_vertical_angle(cub, cub->game.player.v_angle))
	{
		sqr_o = cub->game.player.new_unit_v_co[0] - cub->game.player.unit_co[0];
		sqr_t = cub->game.player.new_unit_v_co[1] - cub->game.player.unit_co[1];
		cub->game.player.v_dist = sqrt((sqr_o * sqr_o) + (sqr_t * sqr_t));
	}
	if (is_empty(cub, cub->game.player.new_grid_h_co[0],
	cub->game.player.new_grid_h_co[1]) != -1
	&& is_horizontal_angle(cub, cub->game.player.v_angle))
	{
		sqr_o = cub->game.player.new_unit_h_co[0] - cub->game.player.unit_co[0];
		sqr_t = cub->game.player.new_unit_h_co[1] - cub->game.player.unit_co[1];
		cub->game.player.h_dist = sqrt((sqr_o * sqr_o) + (sqr_t * sqr_t));
	}
	if (cub->game.player.h_dist > cub->game.player.v_dist)
		cub->game.player.pos_on_wall = (double)cub->game.player.new_unit_v_co[1]
		- (cub->win.block_size * cub->game.player.new_grid_v_co[1]);
	else
		cub->game.player.pos_on_wall = (double)cub->game.player.new_unit_h_co[0]
		- (cub->win.block_size * cub->game.player.new_grid_h_co[0]);
}
