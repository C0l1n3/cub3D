/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:46:23 by coline            #+#    #+#             */
/*   Updated: 2020/08/13 17:28:00 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_bits(uint8_t *header, long int data)
{
	header[0] = (uint8_t)(data);
	header[1] = (uint8_t)(data >> 8);
	header[2] = (uint8_t)(data >> 16);
	header[3] = (uint8_t)(data >> 24);
}

void	create_header(t_cub *cub, int fd)
{
	uint8_t			header[54];
	int				i;
	unsigned long	size;

	size = (cub->win.r_height * cub->win.r_width * 3) + 54;
	i = -1;
	while (++i < 54)
		header[i] = 0;
	header[0] = (uint8_t)'B';
	header[1] = (uint8_t)'M';
	convert_bits(header + 2, size);
	header[10] = (uint8_t)54;
	header[14] = (uint8_t)40;
	convert_bits(header + 18, cub->win.r_width);
	convert_bits(header + 22, cub->win.r_height);
	header[26] = (uint8_t)1;
	header[28] = (uint8_t)32;
	write(fd, &header, 54);
}

void	fill_bits(t_cub *cub, int fd)
{
	int				x;
	int				y;

	x = 0;
	y = cub->win.r_height;
	while (y >= 0)
	{
		x = 0;
		while (x < cub->win.r_width)
		{
			write(fd, &cub->win.base.data[y * cub->win.r_width + x], 4);
			x++;
		}
		y--;
	}
}

int		create_bmp(t_cub *cub)
{
	int				fd;

	cub->win.mlx_ptr = mlx_init();
	check_screen_size(cub);
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
	if (!(fd = open("./image.bmp", O_WRONLY | O_CREAT |
	O_TRUNC | O_APPEND, 0644)))
		return (1);
	create_header(cub, fd);
	fill_bits(cub, fd);
	destroy_images(cub);
	ft_free_cub(cub);
	free_safe((void**)&(cub->win.mlx_ptr));
	close(fd);
	return (0);
}

void	destroy_images(t_cub *cub)
{
	int		i;

	mlx_destroy_image(cub->win.mlx_ptr, cub->win.base.img_ptr);
	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(cub->win.mlx_ptr, cub->map.tex[i].img_ptr);
		i++;
	}
}
