/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:01:03 by coline            #+#    #+#             */
/*   Updated: 2020/08/11 11:27:59 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		looping(t_cub *cub)
{
	mlx_hook(cub->win.game_ptr, 2, 1L, &deal_key, cub);
	mlx_hook(cub->win.game_ptr, 3, 2L, &deal_key_release, cub);
	mlx_hook(cub->win.game_ptr, 33, (1L << 17), &proper_exit, cub);
	mlx_do_sync(cub->win.mlx_ptr);
	mlx_loop_hook(cub->win.mlx_ptr, &process_key, cub);
	mlx_loop(cub->win.mlx_ptr);
	return (0);
}

int		process_key(t_cub *cub)
{
	if (cub->game.key[3] == 1)
		move_right(cub);
	if (cub->game.key[2] == 1)
		move_left(cub);
	if (cub->game.key[0] == 1)
		move_forward(cub);
	if (cub->game.key[1] == 1)
		move_backward(cub);
	if (cub->game.key[4] == 1)
		cub_turn(cub, 'R');
	if (cub->game.key[5] == 1)
		cub_turn(cub, 'L');
	else if (cub->game.key[6] == 1)
	{
		proper_exit(cub);
		return (0);
	}
	process_sprites(cub);
	fill_background(cub);
	fill_walls(cub);
	mlx_put_image_to_window(cub->win.mlx_ptr, cub->win.game_ptr,
	cub->win.base.img_ptr, 0, 0);
	mlx_do_sync(cub->win.mlx_ptr);
	return (0);
}

int		deal_key(int key, t_cub *cub)
{
	if (key)
	{
		if (key == 100)
			cub->game.key[3] = 1;
		if (key == 113)
			cub->game.key[2] = 1;
		if (key == 122)
			cub->game.key[0] = 1;
		if (key == 115)
			cub->game.key[1] = 1;
		if (key == 65361)
			cub->game.key[4] = 1;
		if (key == 65363)
			cub->game.key[5] = 1;
		if (key == 65307 || key == 0xff1b)
			cub->game.key[6] = 1;
	}
	return (0);
}

int		deal_key_release(int key, t_cub *cub)
{
	if (key)
	{
		if (cub->game.key[3] && key == 100)
			cub->game.key[3] = 0;
		if (cub->game.key[2] && key == 113)
			cub->game.key[2] = 0;
		if (cub->game.key[0] && key == 122)
			cub->game.key[0] = 0;
		if (cub->game.key[1] && key == 115)
			cub->game.key[1] = 0;
		if (cub->game.key[4] && key == 65361)
			cub->game.key[4] = 0;
		if (cub->game.key[5] && key == 65363)
			cub->game.key[5] = 0;
	}
	return (0);
}

int		proper_exit(t_cub *param)
{
	mlx_destroy_image(param->win.mlx_ptr, param->win.base.img_ptr);
	mlx_clear_window(param->win.mlx_ptr, param->win.mlx_ptr);
	if (param->win.mlx_ptr)
		mlx_destroy_window(param->win.mlx_ptr, param->win.game_ptr);
	ft_free_cub(param);
	exit(0);
}
