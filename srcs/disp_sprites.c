/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:43:46 by coline            #+#    #+#             */
/*   Updated: 2020/08/04 15:46:58 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	touch_sprite(t_cub *cub, int i, double *pnt)
{
	int		nb;
	double	x;

	x = 0;
	nb = 0;
	while (nb < cub->map.sp_nb)
	{
		process_coef(cub, pnt, nb);
		x = cast_common_x(cub->game.coef, pnt, cub, nb);
		if ((cub->game.coef[0] != cub->game.coef[1] && x)
		|| ((cub->game.player.v_angle == 90 ||
		cub->game.player.v_angle == 270 || cub->game.player.v_angle == 360
		|| cub->game.player.v_angle == 180 || cub->game.player.v_angle == 0)
		&& x))
		{
			dist_to_sprite(cub, nb, pnt, cub->game.coef);
			display_ray_sprite(cub, cub->map.sprites[nb], i);
		}
		nb++;
	}
}

void	display_ray_sprite(t_cub *cub, t_sprite sprite, int i)
{
	double		ratio[2];

	sprite.pos_on_sprite = sqrt(((sprite.touch[0] -
	sprite.start[0]) * (sprite.touch[0] -
	sprite.start[0])) + ((sprite.start[1]
	- sprite.touch[1]) * (sprite.start[1]
	- sprite.touch[1])));
	sprite.ht = sprite.dist_to_player *
	cos(degree_to_radian(ft_abs(cub->game.player.o_angle -
	cub->game.player.v_angle)));
	sprite.ht = ((cub->win.block_size / sprite.ht) *
	((cub->win.r_width / 2) / tan(degree_to_radian(30))));
	ratio[0] = (double)cub->map.tex[4].width / cub->win.block_size;
	ratio[1] = (double)cub->map.tex[4].height / sprite.ht;
	sprite.pixel = sprite.ht > cub->win.r_height ?
	(sprite.ht - cub->win.r_height) * 0.5 * ratio[1] : 0;
	fill_ray_sprite(cub, ratio, i, sprite);
}

void	fill_ray_sprite(t_cub *cub, double *ratio, int i, t_sprite sprite)
{
	int	j;
	int	color;
	int start;

	j = 0;
	start = sprite.ht > cub->win.r_height ? 0 : (cub->win.r_height -
	sprite.ht) * 0.5;
	while (j < cub->win.r_height && j < sprite.ht)
	{
		color = (int)sprite.pixel * cub->map.tex[4].width -
		(int)(sprite.pos_on_sprite *
		ratio[0]) - 1 > 0 ? (int)sprite.pixel * cub->map.tex[4].width +
		cub->map.tex[4].width - (int)(sprite.pos_on_sprite * ratio[0]) - 1
		: cub->map.tex[4].width;
		color = cub->map.tex[4].data[color];
		if (color != 0xACE6E2)
			cub->win.base.data[(start + j) *
			cub->win.r_width + i] = color;
		sprite.pixel += ratio[1];
		j++;
	}
}
