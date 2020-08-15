/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:00:52 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/15 17:22:45 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		**lst_to_int(t_cub *cub)
{
	int		**tab;
	int		j;

	j = 0;
	if (!(tab = (int**)malloc(sizeof(int*) * cub->map.m_height)))
		return (NULL);
	while (j < cub->map.m_height)
	{
		if (!(tab[j] = (int*)malloc(sizeof(int) * cub->map.m_width)))
			return (NULL);
		j++;
	}
	fill_tab(tab, cub);
	cub->map.map_tab = tab;
	count_sprites(cub);
	free_lstchar(cub->map.map_lines);
	cub->map.map_lines = NULL;
	return (tab);
}

int		char_to_int(char c)
{
	if (c == ' ')
		return (7);
	else if (c == '0')
		return (0);
	else if (c == '1')
		return (1);
	else if (c == 'N')
		return (3);
	else if (c == 'S')
		return (4);
	else if (c == 'E')
		return (5);
	else if (c == 'W')
		return (6);
	else if (c == '2')
		return (2);
	else
		return (-1);
}

void	fill_tab(int **tab, t_cub *cub)
{
	int		i;
	int		j;
	int		k;
	t_chain	*ptr;

	j = 0;
	ptr = cub->map.map_lines;
	while (ptr && is_space_line(ptr->content))
		ptr = ptr->next;
	while (ptr)
	{
		i = 0;
		k = 0;
		while (ptr->content[k])
		{
			tab[j][i] = char_to_int(ptr->content[k]);
			if ((ischarmap(ptr->content[k])) == 1)
				process_player(cub, i, j, ptr->content[k]);
			i++;
			k++;
		}
		finish_filling(tab, &i, j, cub);
		ptr = ptr->next;
		j++;
	}
}

void	count_sprites(t_cub *cub)
{
	int w;
	int	h;

	h = 0;
	while (h < cub->map.m_height)
	{
		w = 0;
		while (w < cub->map.m_width)
		{
			if (cub->map.map_tab[h][w] == 2)
				cub->map.sp_nb++;
			w++;
		}
		h++;
	}
}

void	finish_filling(int **tab, int *i, int j, t_cub *cub)
{
	while (*i < cub->map.m_width)
	{
		tab[j][*i] = 8;
		*i += 1;
	}
}
