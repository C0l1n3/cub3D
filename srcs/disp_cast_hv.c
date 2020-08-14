/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_cast_hv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:59:12 by coline            #+#    #+#             */
/*   Updated: 2020/08/07 12:48:34 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_h_quotient(t_cub *cub, int a)
{
	cub->game.player.new_unit_h_co[0] += cub->game.player.h_quotient[0];
	cub->game.player.new_unit_h_co[1] += cub->game.player.h_quotient[1];
	if (cub->game.player.new_unit_h_co[0] >= 0)
		cub->game.player.new_grid_h_co[0] =
		cub->game.player.new_unit_h_co[0] / cub->win.block_size;
	else
		cub->game.player.new_grid_h_co[0] = -1;
	cub->game.player.new_grid_h_co[1] = (cub->game.player.new_unit_h_co[1] + a)
	/ cub->win.block_size;
}

void	add_v_quotient(t_cub *cub, int a)
{
	cub->game.player.new_unit_v_co[0] += cub->game.player.v_quotient[0];
	cub->game.player.new_unit_v_co[1] += cub->game.player.v_quotient[1];
	if (cub->game.player.new_unit_v_co[0] >= 0)
		cub->game.player.new_grid_v_co[0] =
		(cub->game.player.new_unit_v_co[0] + a) / cub->win.block_size;
	else
		cub->game.player.new_grid_v_co[0] = -1;
	if (cub->game.player.new_unit_v_co[1] >= 0)
		cub->game.player.new_grid_v_co[1] = cub->game.player.new_unit_v_co[1]
		/ cub->win.block_size;
	else
		cub->game.player.new_grid_v_co[1] = -1;
}

void	find_horizontal(t_cub *cub)
{
	double	a;

	a = 0;
	if (is_horizontal_angle(cub, cub->game.player.v_angle))
	{
		find_first_hpoint(cub);
		if (cub->game.player.v_angle >= 180 && cub->game.player.v_angle < 360)
			cub->game.player.h_quotient[0] = cub->game.player.h_quotient[0] *
			-1;
		if (cub->game.player.v_angle >= 0 && cub->game.player.v_angle < 180)
			a = -1;
		while (!is_empty(cub, cub->game.player.new_grid_h_co[0],
		cub->game.player.new_grid_h_co[1]))
			add_h_quotient(cub, a);
	}
	else
	{
		cub->game.player.new_unit_h_co[0] = -1;
		cub->game.player.new_unit_h_co[1] = -1;
	}
}

void	find_vertical(t_cub *cub)
{
	double	a;

	a = 0;
	if (is_vertical_angle(cub, cub->game.player.v_angle))
	{
		find_first_vpoint(cub);
		if ((cub->game.player.v_angle >= 0 && cub->game.player.v_angle <= 90)
		|| (cub->game.player.v_angle <= 360 && cub->game.player.v_angle >= 270))
			cub->game.player.v_quotient[1] = cub->game.player.v_quotient[1] *
			-1;
		if (cub->game.player.v_angle > 90 && cub->game.player.v_angle < 270)
			a = -1;
		while (!is_empty(cub, cub->game.player.new_grid_v_co[0],
		cub->game.player.new_grid_v_co[1]))
			add_v_quotient(cub, a);
	}
	else
	{
		cub->game.player.new_unit_v_co[0] = -1;
		cub->game.player.new_unit_v_co[1] = -1;
	}
}
