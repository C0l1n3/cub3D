/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:53:47 by coline            #+#    #+#             */
/*   Updated: 2020/08/13 16:42:09 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_cub *cub)
{
	double	angle;
	double	a;
	double	b;

	a = 1;
	b = 1;
	angle = cub->game.player.o_angle;
	if (angle >= 90 && angle < 270)
		a = -1;
	if (angle >= 0 && angle < 180)
		b = -1;
	if (angle >= 90 && angle < 180)
		angle = 180 - angle;
	else if (angle >= 180 && angle < 270)
		angle = angle - 180;
	else if (angle >= 270 && angle <= 360)
		angle = 360 - angle;
	if (!is_empty(cub, (cub->game.player.unit_co[0] +
	cos(degree_to_radian(angle)) * (cub->win.r_height / 100) * a)
	/ cub->win.block_size, (cub->game.player.unit_co[1]
	+ sin(degree_to_radian(angle)) * (cub->win.r_height / 100) * b) /
	cub->win.block_size))
		add_value(cub, angle, a, b);
}

void	move_backward(t_cub *cub)
{
	double	angle;
	int		a;
	int		b;

	a = 1;
	b = 1;
	angle = cub->game.player.o_angle;
	if (angle < 90 || angle >= 270)
		a = -1;
	if (angle >= 180 && angle <= 360)
		b = -1;
	if (angle >= 90 && angle < 180)
		angle = 180 - angle;
	else if (angle >= 180 && angle < 270)
		angle -= 180;
	else if (angle >= 270 && angle <= 360)
		angle = 360 - angle;
	if (!is_empty(cub, (cub->game.player.unit_co[0] +
	cos(degree_to_radian(angle)) * (cub->win.r_height / 100) * a)
	/ cub->win.block_size, (cub->game.player.unit_co[1]
	+ sin(degree_to_radian(angle)) * (cub->win.r_height / 100) * b) /
	cub->win.block_size))
		add_value(cub, angle, a, b);
}

void	move_left(t_cub *cub)
{
	double	angle;
	int		a;
	int		b;

	a = 1;
	b = 1;
	angle = (cub->game.player.o_angle + 90 < 360) ?
	cub->game.player.o_angle + 90 : cub->game.player.o_angle + 90 - 360;
	if (angle >= 90 && angle < 270)
		a = -1;
	if (angle < 180)
		b = -1;
	if (angle >= 90 && angle < 180)
		angle = 180 - angle;
	else if (angle >= 180 && angle < 270)
		angle = angle - 180;
	else if (angle >= 270 && angle <= 360)
		angle = 360 - angle;
	if (!is_empty(cub, (cub->game.player.unit_co[0] +
	cos(degree_to_radian(angle)) * (cub->win.r_height / 100) * a)
	/ cub->win.block_size, (cub->game.player.unit_co[1] +
	sin(degree_to_radian(angle)) * (cub->win.r_height / 100) * b) /
	cub->win.block_size))
		add_value(cub, angle, a, b);
}

void	move_right(t_cub *cub)
{
	double	angle;
	int		a;
	int		b;

	angle = (cub->game.player.o_angle - 90 > 0) ?
	cub->game.player.o_angle - 90 : 360 - (90 - cub->game.player.o_angle);
	a = 1;
	b = 1;
	if (angle >= 90 && angle < 270)
		a = -1;
	if (angle < 180)
		b = -1;
	if (angle >= 90 && angle < 180)
		angle = 180 - angle;
	else if (angle >= 180 && angle < 270)
		angle = angle - 180;
	else if (angle >= 270 && angle <= 360)
		angle = 360 - angle;
	if (!is_empty(cub, (cub->game.player.unit_co[0] +
	cos(degree_to_radian(angle)) * (cub->win.r_height / 100) * a)
	/ cub->win.block_size, (cub->game.player.unit_co[1] +
	sin(degree_to_radian(angle)) * (cub->win.r_height / 100) * b) /
	cub->win.block_size))
		add_value(cub, angle, a, b);
}

void	add_value(t_cub *cub, double angle, int a, int b)
{
	cub->game.player.unit_co[0] += cos(degree_to_radian(angle))
	* (cub->win.r_height / 100) * a;
	cub->game.player.unit_co[1] += sin(degree_to_radian(angle))
	* (cub->win.r_height / 100) * b;
	cub->game.player.grid_co[0] = cub->game.player.unit_co[0]
	/ cub->win.block_size;
	cub->game.player.grid_co[1] = cub->game.player.unit_co[1]
	/ cub->win.block_size;
}
