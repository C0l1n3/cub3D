/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_process_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:43:10 by coline            #+#    #+#             */
/*   Updated: 2020/08/04 15:48:50 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		process_sprites(t_cub *cub)
{
	int			i;
	int			j;
	int			nb;

	j = 0;
	nb = 0;
	while (j < cub->map.m_height)
	{
		i = -1;
		while (++i < cub->map.m_width)
		{
			if (cub->map.map_tab[j][i] == 2)
			{
				process_pos_sprites(nb, i, j, cub);
				cub->map.sprites[nb].dist_to_player =
				dist_two_pts(cub->map.sprites[nb].middle[0],
				cub->map.sprites[nb].middle[1], cub->game.player.unit_co[0],
				cub->game.player.unit_co[1]);
				nb++;
			}
		}
		j++;
	}
	sort_sprites(cub);
	return (0);
}

void	process_pos_sprites(int nb, int x, int y, t_cub *cub)
{
	double	angle;
	int		coef[4];

	angle = cub->game.player.o_angle;
	coef[0] = (angle < 180) ? 1 : -1;
	coef[1] = (angle > 270 || angle < 90) ? 1 : -1;
	coef[2] = (angle > 180) ? 1 : -1;
	coef[3] = (angle >= 90 && angle < 270) ? 1 : -1;
	cub->map.sprites[nb].pos_x = x;
	cub->map.sprites[nb].pos_y = y;
	cub->map.sprites[nb].middle[0] = (x * cub->win.block_size) +
	(cub->win.block_size / 2);
	cub->map.sprites[nb].middle[1] = (y * cub->win.block_size) +
	(cub->win.block_size / 2);
	angle = (angle >= 90 && angle < 180) ? 180 - angle : angle;
	angle = (angle >= 180 && angle < 270) ? angle - 180 : angle;
	angle = (angle >= 270 && angle <= 360) ? 360 - angle : angle;
	cub->map.sprites[nb].start[0] = cub->map.sprites[nb].middle[0] +
	((sin(degree_to_radian(angle)) * (cub->win.block_size / 2)) * coef[0]);
	cub->map.sprites[nb].start[1] = cub->map.sprites[nb].middle[1] +
	((cos(degree_to_radian(angle)) * (cub->win.block_size / 2)) * coef[1]);
	cub->map.sprites[nb].end[0] = cub->map.sprites[nb].middle[0] +
	((sin(degree_to_radian(angle)) * (cub->win.block_size / 2)) * coef[2]);
	cub->map.sprites[nb].end[1] = cub->map.sprites[nb].middle[1] +
	((cos(degree_to_radian(angle)) * (cub->win.block_size / 2)) * coef[3]);
}

void	sort_sprites(t_cub *cub)
{
	int			count;
	int			i;
	t_sprite	tmp;

	count = 0;
	while (count < cub->map.sp_nb)
	{
		i = 0;
		while (i < (cub->map.sp_nb - 1))
		{
			if (cub->map.sprites[i].dist_to_player <
			cub->map.sprites[i + 1].dist_to_player)
			{
				tmp = cub->map.sprites[i];
				cub->map.sprites[i] = cub->map.sprites[i + 1];
				cub->map.sprites[i + 1] = tmp;
				i = -1;
			}
			i++;
		}
		count++;
	}
}
