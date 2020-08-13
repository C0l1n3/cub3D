/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:14:49 by coline            #+#    #+#             */
/*   Updated: 2020/08/13 17:07:15 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cub(t_cub *cub)
{
	char	*title_game;

	title_game = "CUBE3D";
	cub->win.mlx_ptr = mlx_init();
	check_screen_size(cub);
	cub->win.game_ptr = mlx_new_window(cub->win.mlx_ptr,
	cub->win.r_width, cub->win.r_height, title_game);
	create_img(cub);
	fill_background(cub);
	if (get_textures(cub))
		return (-1);
	if (!(cub->map.sprites = (t_sprite*)malloc(sizeof(t_sprite)
	* cub->map.sp_nb)))
		return (-1);
	if (process_sprites(cub))
		return (-1);
	fill_walls(cub);
	mlx_put_image_to_window(cub->win.mlx_ptr, cub->win.game_ptr,
	cub->win.base.img_ptr, 0, 0);
	return (0);
}

int		get_textures(t_cub *cub)
{
	if (load_img(cub, cub->map.text[0], &cub->map.tex[0]))
		return (-1);
	if (load_img(cub, cub->map.text[1], &cub->map.tex[1]))
		return (-1);
	if (load_img(cub, cub->map.text[2], &cub->map.tex[2]))
		return (-1);
	if (load_img(cub, cub->map.text[3], &cub->map.tex[3]))
		return (-1);
	if (load_img(cub, cub->map.text[4], &cub->map.tex[4]))
		return (-1);
	return (0);
}

int		load_img(t_cub *cub, char *path, t_img *img)
{
	if (!(img->img_ptr = mlx_xpm_file_to_image(cub->win.mlx_ptr, path,
		&img->width, &img->height)))
		return (-1);
	if (!(img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
	&img->size_line, &img->endian)))
		return (-1);
	return (0);
}

int		create_img(t_cub *cub)
{
	if (!(cub->win.base.img_ptr = mlx_new_image(cub->win.mlx_ptr,
	cub->win.r_width, cub->win.r_height)))
		return (-1);
	if (!(cub->win.base.data =
	(int*)mlx_get_data_addr(cub->win.base.img_ptr,
	&cub->win.base.bpp, &cub->win.base.size_line,
	&cub->win.base.endian)))
		return (-1);
	return (0);
}
