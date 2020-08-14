/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:30:30 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/13 13:02:09 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_safe(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	init_map(t_cub *cub)
{
	cub->map.map_file = "real_map.cub";
	cub->map.m_width = 0;
	cub->map.m_height = 1;
	cub->map.fd = -1;
	cub->map.perso = -1;
	cub->map.text = (char**)malloc(sizeof(char*) * 5);
	cub->map.text[0] = NULL;
	cub->map.text[1] = NULL;
	cub->map.text[2] = NULL;
	cub->map.text[3] = NULL;
	cub->map.text[4] = NULL;
	cub->map.sp_nb = 0;
	cub->map.c_color = -1;
	cub->map.f_color = -1;
	cub->map.map_lines = NULL;
	cub->map.x = 0;
	cub->map.y = 0;
}

void	init_window(t_cub *cub)
{
	cub->win.mlx_ptr = NULL;
	cub->win.game_ptr = NULL;
	cub->win.map_ptr = NULL;
	cub->win.r_width = -1;
	cub->win.r_height = -1;
	cub->win.color = 0;
	cub->win.block_size = 0;
}

void	init_game(t_cub *cub)
{
	t_player	player;

	cub->game.bpp = 0;
	cub->game.size_line = 0;
	cub->game.endian = 0;
	cub->game.dist_to_plane = 0;
	cub->game.sub_angle = 0;
	player.init_dir = 0;
	player.o_vector[0] = 0;
	player.o_vector[1] = 0;
	player.grid_co[0] = 0;
	player.grid_co[1] = 0;
	player.unit_co[0] = 0;
	player.unit_co[1] = 0;
	player.new_grid_h_co[0] = 0;
	player.new_grid_h_co[1] = 0;
	player.new_unit_h_co[0] = 0;
	player.new_unit_h_co[1] = 0;
	player.v_angle = 0;
	ft_bzero(cub->game.key, 7);
	cub->game.player = player;
}

void	init_struct(t_cub *cub)
{
	init_map(cub);
	init_window(cub);
	init_game(cub);
}
