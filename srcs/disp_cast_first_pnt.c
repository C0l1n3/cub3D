/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_cast_first_pnt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:46:17 by coline            #+#    #+#             */
/*   Updated: 2020/08/07 12:47:55 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_first_hpoint(t_cub *cub)
{
	double	i;
	double	angle;

	angle = cub->game.player.v_angle;
	i = (angle >= 0 && angle < 180) ? -1 : 0;
	cub->game.player.new_unit_h_co[1] =
	(angle >= 0 && angle < 180) ?
	(cub->game.player.grid_co[1] * cub->win.block_size) :
	((cub->game.player.grid_co[1] + 1) * cub->win.block_size);
	cub->game.player.new_grid_h_co[1] = (cub->game.player.new_unit_h_co[1] +
	i) / cub->win.block_size;
	first_xh(cub, &angle);
	cub->game.player.new_grid_h_co[0] = cub->game.player.new_unit_h_co[0]
	/ cub->win.block_size;
	if ((cub->game.player.v_angle < 90 || cub->game.player.v_angle > 270)
	&& cub->game.player.new_grid_h_co[0] * cub->win.block_size ==
	cub->game.player.new_unit_h_co[0])
		cub->game.player.new_grid_h_co[0]++;
	if (cub->game.player.v_angle >= 0 && cub->game.player.v_angle < 180)
		cub->game.player.h_quotient[1] = cub->win.block_size * -1;
	if (cub->game.player.v_angle >= 180 && cub->game.player.v_angle < 360)
		cub->game.player.h_quotient[1] = cub->win.block_size;
	cub->game.player.h_quotient[0] = cub->win.block_size /
	tan(degree_to_radian(cub->game.player.v_angle));
}

void	first_xh(t_cub *cub, double *angle)
{
	if (cub->game.player.v_angle >= 0 && cub->game.player.v_angle < 90)
		cub->game.player.new_unit_h_co[0] = cub->game.player.unit_co[0] +
		((cub->game.player.unit_co[1] - cub->game.player.new_unit_h_co[1])
		/ tan(degree_to_radian(*angle)));
	if (cub->game.player.v_angle >= 90 && cub->game.player.v_angle < 180)
	{
		*angle = cub->game.player.v_angle - 90;
		cub->game.player.new_unit_h_co[0] = cub->game.player.unit_co[0] -
		(tan(degree_to_radian(*angle)) *
		(cub->game.player.unit_co[1] - cub->game.player.new_unit_h_co[1]));
	}
	if (cub->game.player.v_angle >= 180 && cub->game.player.v_angle < 270)
	{
		*angle = cub->game.player.v_angle - 180;
		cub->game.player.new_unit_h_co[0] = cub->game.player.unit_co[0] -
		((cub->game.player.new_unit_h_co[1] - cub->game.player.unit_co[1])
		/ tan(degree_to_radian(*angle)));
	}
	if (cub->game.player.v_angle >= 270 && cub->game.player.v_angle <= 360)
	{
		*angle = cub->game.player.v_angle - 270;
		cub->game.player.new_unit_h_co[0] = cub->game.player.unit_co[0] +
		((cub->game.player.new_unit_h_co[1] - cub->game.player.unit_co[1])
		* tan(degree_to_radian(*angle)));
	}
}

void	find_first_vpoint(t_cub *cub)
{
	double	i;
	double	angle;

	angle = cub->game.player.v_angle;
	i = (cub->game.player.v_angle > 90 && cub->game.player.v_angle < 270) ?
	-1 : 0;
	cub->game.player.new_unit_v_co[0] =
	(cub->game.player.v_angle > 90 && cub->game.player.v_angle < 270) ?
	cub->game.player.grid_co[0] * cub->win.block_size :
	(cub->game.player.grid_co[0] + 1) * cub->win.block_size;
	cub->game.player.new_grid_v_co[0] = (cub->game.player.new_unit_v_co[0] +
	i) / cub->win.block_size;
	first_xv(cub, &angle);
	cub->game.player.new_grid_v_co[1] = cub->game.player.new_unit_v_co[1] /
	cub->win.block_size;
	if (cub->win.block_size * cub->game.player.new_unit_h_co[1] ==
	cub->game.player.new_grid_v_co[1] && (cub->game.player.v_angle <= 90
	|| cub->game.player.v_angle >= 270))
		cub->game.player.new_grid_v_co[1]++;
	if (cub->game.player.v_angle > 90 && cub->game.player.v_angle < 270)
		cub->game.player.v_quotient[0] = cub->win.block_size * -1;
	if (cub->game.player.v_angle <= 90 || cub->game.player.v_angle >= 270)
		cub->game.player.v_quotient[0] = cub->win.block_size;
	cub->game.player.v_quotient[1] = cub->win.block_size *
	tan(degree_to_radian(cub->game.player.v_angle));
}

void	first_xv(t_cub *cub, double *angle)
{
	if (cub->game.player.v_angle >= 0 && cub->game.player.v_angle < 90)
		cub->game.player.new_unit_v_co[1] = cub->game.player.unit_co[1] -
		(tan(degree_to_radian(*angle)) * (cub->game.player.new_unit_v_co[0] -
		cub->game.player.unit_co[0]));
	if (cub->game.player.v_angle >= 90 && cub->game.player.v_angle < 180)
	{
		*angle = cub->game.player.v_angle - 90;
		cub->game.player.new_unit_v_co[1] = cub->game.player.unit_co[1] -
		((cub->game.player.unit_co[0] - cub->game.player.new_unit_v_co[0])
		/ tan(degree_to_radian(*angle)));
	}
	if (cub->game.player.v_angle >= 180 && cub->game.player.v_angle < 270)
	{
		*angle = cub->game.player.v_angle - 180;
		cub->game.player.new_unit_v_co[1] = cub->game.player.unit_co[1] +
		(tan(degree_to_radian(*angle)) * (cub->game.player.unit_co[0] -
		cub->game.player.new_unit_v_co[0]));
	}
	if (cub->game.player.v_angle >= 270 && cub->game.player.v_angle < 360)
	{
		*angle = cub->game.player.v_angle - 270;
		cub->game.player.new_unit_v_co[1] = cub->game.player.unit_co[1] +
		((cub->game.player.new_unit_v_co[0] - cub->game.player.unit_co[0])
		/ tan(degree_to_radian(*angle)));
	}
}

void	find_ignore_angle(t_cub *cub)
{
	double	x;
	double	y;
	double	g_x;
	double	g_y;
	double	sz;

	x = cub->game.player.unit_co[0];
	y = cub->game.player.unit_co[1];
	g_x = cub->game.player.grid_co[0];
	g_y = cub->game.player.grid_co[1];
	sz = cub->win.block_size;
	cub->game.ignore_angle[0] = atan((x - ((g_x) * sz)) / y) * 180 / M_PI;
	cub->game.ignore_angle[1] = atan(((g_x + 1) * sz - x) / y) * 180 / M_PI;
	cub->game.ignore_angle[2] = atan((y - (g_y) * sz) /
	(cub->map.m_width * sz - x)) * 180 / M_PI;
	cub->game.ignore_angle[3] = atan(((g_y + 1) * sz - y) /
	(cub->map.m_width * sz - x)) * 180 / M_PI;
	cub->game.ignore_angle[4] = atan(((g_x + 1) * sz - x) /
	(cub->map.m_height * sz - y)) * 180 / M_PI;
	cub->game.ignore_angle[5] = atan((x - ((g_x) * sz)) /
	(cub->map.m_height * sz - y)) * 180 / M_PI;
	cub->game.ignore_angle[6] = atan(((g_y + 1) * sz - y) / x) * 180 / M_PI;
	cub->game.ignore_angle[7] = atan((y - (g_y) * sz) / x) * 180 / M_PI;
}
