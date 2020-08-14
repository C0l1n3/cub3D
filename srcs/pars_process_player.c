/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_process_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:17:02 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/04 16:30:29 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	process_player(t_cub *cub, int x, int y, char letter)
{
	double	middle;

	cub->win.block_size = cub->win.r_width / 30;
	middle = cub->win.block_size / 2;
	cub->game.dist_to_plane = (cub->win.r_width / 2)
	/ (tan(degree_to_radian(60)));
	cub->game.sub_angle = (double)60 / (double)cub->win.r_width;
	cub->game.player.pos_on_wall = 0;
	cub->game.player.grid_co[0] = x;
	cub->game.player.grid_co[1] = y;
	cub->game.player.unit_co[0] = middle + (cub->win.block_size * x);
	cub->game.player.unit_co[1] = middle + (cub->win.block_size * y);
	cub->game.player.init_dir = letter;
	process_o_angle(cub, letter);
}

void	process_o_angle(t_cub *cub, char letter)
{
	if (letter == 'N')
	{
		cub->game.player.o_angle = 90;
		cub->game.player.o_vector[0] = 0;
		cub->game.player.o_vector[1] = -1;
	}
	if (letter == 'S')
	{
		cub->game.player.o_angle = 270;
		cub->game.player.o_vector[0] = 0;
		cub->game.player.o_vector[1] = 1;
	}
	if (letter == 'E')
	{
		cub->game.player.o_angle = 360;
		cub->game.player.o_vector[0] = 1;
		cub->game.player.o_vector[1] = 0;
	}
	if (letter == 'W')
	{
		cub->game.player.o_angle = 180;
		cub->game.player.o_vector[0] = -1;
		cub->game.player.o_vector[1] = 0;
	}
}
