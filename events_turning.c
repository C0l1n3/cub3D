/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_turning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:35:19 by coline            #+#    #+#             */
/*   Updated: 2020/08/07 12:58:53 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**int	mouse(int x, int y, t_cub *cub)
**{
**	static int		center;
**	int				i;
**
**	if (!(center))
**		center = cub->win.r_width / 2;
**	if (x != center)
**		cub->game.player.o_angle = (cub->game.player.o_angle - ((x - center)
**		* (0.5)) > 0) ? cub->game.player.o_angle - ((x - center) * (0.5)) :
**		360 - (x - center) * (0.5) - cub->game.player.o_angle;
**	center = x;
**	i = y;
**	if (i != 0)
**		i = 0;
**	return (0);
**}
*/

void	cub_turn(t_cub *cub, char side)
{
	if (side == 'R')
		cub->game.player.o_angle = (cub->game.player.o_angle +
		((double)(cub->win.r_width * 0.002)) < 360) ?
		cub->game.player.o_angle + ((double)(cub->win.r_width * 0.002))
		: ((double)(cub->win.r_width * 0.002)) + cub->game.player.o_angle
		- 360;
	else if (side == 'L')
		cub->game.player.o_angle =
		(cub->game.player.o_angle - ((double)(cub->win.r_width * 0.002))
		> 0) ? cub->game.player.o_angle
		- ((double)(cub->win.r_width * 0.002)) : 360 -
		(((double)(cub->win.r_width * 0.002)) - cub->game.player.o_angle);
}
