/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_fill_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:40:15 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/11 12:07:37 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_background(t_cub *cub)
{
	int	x;

	x = 0;
	while (cub->win.base.data && x < cub->win.r_width * (cub->win.r_height / 2))
	{
		cub->win.base.data[x] = cub->map.c_color;
		x++;
	}
	while (cub->win.base.data && x < cub->win.r_width * cub->win.r_height)
	{
		cub->win.base.data[x] = cub->map.f_color;
		x++;
	}
}
