/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_simple_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:46:03 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/13 17:03:47 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		mini_atoi(char *line, int *i)
{
	int x;
	int nb;

	nb = 0;
	while (ft_isdigit(line[*i + nb]))
		nb++;
	x = 0;
	if (nb > 5)
	{
		*i = *i + nb;
		return (10000);
	}
	while (ft_isdigit(line[*i]))
	{
		x = x * 10 + line[*i] - 48;
		*i += 1;
	}
	return (x);
}

int		ft_rgb_to_int(int a, int b, int c)
{
	int color;

	if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255)
		return (-1);
	color = (a * 65536) + (b * 256) + c;
	return (color);
}

double	degree_to_radian(double degree)
{
	return (degree * (M_PI / 180));
}

double	ft_abs(double x)
{
	if (x < 0)
		x = -1 * x;
	return (x);
}

double	dist_two_pts(double a_x, double a_y, double b_x, double b_y)
{
	double	side_one;
	double	side_two;

	side_one = a_x - b_x;
	side_two = a_y - b_y;
	return (sqrt((side_one * side_one) + (side_two * side_two)));
}
