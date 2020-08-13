/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_process_description.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 20:15:07 by coline            #+#    #+#             */
/*   Updated: 2020/08/13 16:05:47 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_map(t_cub *cub)
{
	char	*line;
	t_chain	*new;
	int		ret;
	int		**tab;

	while ((ret = get_next_line(cub->map.fd, &line)) >= 0)
	{
		new = lstcharnew(line);
		lstcharadd_back(&cub->map.map_lines, new);
		ft_free_safe(&line);
		if (!ret)
			break ;
	}
	get_dimension(cub);
	tab = lst_to_int(cub);
	if (check_map(tab, cub->map.m_height, cub->map.m_width, cub))
		return (-1);
	close(cub->map.fd);
	cub->map.map_tab = tab;
	return (0);
}

void	get_dimension(t_cub *cub)
{
	int		j;
	int		k;
	char	*line;
	t_chain	*list;

	list = cub->map.map_lines;
	j = 0;
	k = 0;
	while (list)
	{
		line = list->content;
		while (*line)
		{
			if (ischarmap(*line) >= 0)
				k++;
			line++;
		}
		if (cub->map.m_width < k)
			cub->map.m_width = k;
		k = 0;
		list = list->next;
		j++;
	}
	cub->map.m_height = j;
}
