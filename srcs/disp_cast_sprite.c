/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_cast_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:47:43 by coline            #+#    #+#             */
/*   Updated: 2020/08/04 15:48:41 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	notable_cases(double *pnt, t_cub *cub, int nb)
{
	if ((cub->game.player.v_angle == 90 &&
	(cub->map.sprites[nb].start[0] >= pnt[0]
	&& pnt[0] >= cub->map.sprites[nb].end[0]
	&& pnt[1] <= cub->map.sprites[nb].start[1]
	&& cub->map.sprites[nb].start[1] <= cub->game.player.unit_co[1]))
	|| (cub->game.player.v_angle == 270
	&& (cub->map.sprites[nb].end[0] >= pnt[0]
	&& pnt[0] >= cub->map.sprites[nb].start[0]
	&& cub->game.player.unit_co[1] <= cub->map.sprites[nb].start[1]
	&& cub->map.sprites[nb].start[1] <= pnt[1])))
		return (pnt[0]);
	else if ((cub->game.player.v_angle == 0 || cub->game.player.v_angle == 360
	|| cub->game.player.v_angle == 180)
	&& ((cub->game.player.unit_co[0] <= cub->map.sprites[nb].start[0]
	&& cub->map.sprites[nb].start[0] <= pnt[0]
	&& cub->map.sprites[nb].start[1] >= pnt[1]
	&& pnt[1] >= cub->map.sprites[nb].end[1])
	|| (pnt[0] <= cub->map.sprites[nb].start[0]
	&& cub->map.sprites[nb].start[0] <= cub->game.player.unit_co[0]
	&& cub->map.sprites[nb].end[1] >= pnt[1]
	&& pnt[1] >= cub->map.sprites[nb].start[1])))
		return (cub->map.sprites[nb].end[0]);
	return (0);
}

double	notable_cases_two(double *pnt, t_cub *cub, int nb, double *coef)
{
	double common_y;

	common_y = 0;
	if (cub->game.player.o_angle == 180 || cub->game.player.o_angle == 0
	|| cub->game.player.o_angle == 360)
	{
		common_y = -1 * (coef[0] * cub->map.sprites[nb].end[0] + coef[2]);
		if (((cub->map.sprites[nb].start[1] <= common_y
		&& common_y <= cub->map.sprites[nb].end[1])
		|| (cub->map.sprites[nb].start[1] >= common_y
		&& common_y >= cub->map.sprites[nb].end[1]))
		&& ((cub->game.player.unit_co[0] <= cub->map.sprites[nb].start[0]
		&& cub->map.sprites[nb].start[0] <= pnt[0])
		|| (cub->game.player.unit_co[0] >= cub->map.sprites[nb].start[0]
		&& cub->map.sprites[nb].start[0] >= pnt[0])))
			return (common_y);
	}
	return (0);
}

double	cast_common_x(double *coef, double *pnt, t_cub *cub, int nb)
{
	double	x;

	if ((x = notable_cases(pnt, cub, nb)))
		return (x);
	else if ((x = notable_cases_two(pnt, cub, nb, coef)))
		return (x);
	else
		x = (coef[3] - coef[2]) / (coef[0] - coef[1]);
	if (pnt[0] <= x && x <= cub->game.player.unit_co[0]
	&& cub->map.sprites[nb].start[0] <= x && x <= cub->map.sprites[nb].end[0])
		return (x);
	else if (pnt[0] >= x && x >= cub->game.player.unit_co[0]
	&& cub->map.sprites[nb].start[0] >= x && x >= cub->map.sprites[nb].end[0])
		return (x);
	else if (pnt[0] >= x && x >= cub->game.player.unit_co[0]
	&& cub->map.sprites[nb].start[0] <= x && x <= cub->map.sprites[nb].end[0])
		return (x);
	else if (pnt[0] <= x && x <= cub->game.player.unit_co[0]
	&& cub->map.sprites[nb].start[0] >= x && x >= cub->map.sprites[nb].end[0])
		return (x);
	return (0);
}

void	dist_to_sprite(t_cub *cub, int nb, double *pnt, double *coef)
{
	double	common_x;
	double	common_y;
	double	temp;

	temp = ((pnt[1] - cub->game.player.unit_co[1]) /
	(cub->game.player.unit_co[0] - pnt[0]));
	common_x = (cub->game.player.o_angle == 0 ||
	cub->game.player.o_angle == 360 || cub->game.player.o_angle == 180) ?
	cub->map.sprites[nb].start[0] :
	(coef[3] - coef[2]) / (coef[0] - coef[1]);
	if (cub->game.player.v_angle == 90 || cub->game.player.v_angle == 270)
		common_x = pnt[0];
	common_y = (cub->game.player.o_angle == 90 ||
	cub->game.player.o_angle == 270 || cub->game.player.v_angle == 270
	|| cub->game.player.v_angle == 90) ?
	cub->map.sprites[nb].start[1] :
	(temp * common_x + ((-1 * pnt[1]) - (temp * pnt[0]))) * -1;
	cub->map.sprites[nb].dist_to_player = dist_two_pts(common_x, common_y,
	cub->game.player.unit_co[0], cub->game.player.unit_co[1]);
	cub->map.sprites[nb].touch[0] = common_x;
	cub->map.sprites[nb].touch[1] = common_y;
}

void	process_coef(t_cub *cub, double *pnt, int nb)
{
	cub->game.coef[0] = (cub->game.player.unit_co[0] - pnt[0] != 0) ?
	(pnt[1] - cub->game.player.unit_co[1]) / (cub->game.player.unit_co[0]
	- pnt[0]) : 0;
	cub->game.coef[1] =
	(cub->map.sprites[nb].start[1] - cub->map.sprites[nb].end[1])
	/ (cub->map.sprites[nb].end[0] - cub->map.sprites[nb].start[0]);
	cub->game.coef[2] = ((-1 * pnt[1]) - (cub->game.coef[0] * pnt[0]));
	cub->game.coef[3] = ((-1 * cub->map.sprites[nb].start[1]) -
	(cub->game.coef[1] * cub->map.sprites[nb].start[0]));
}
