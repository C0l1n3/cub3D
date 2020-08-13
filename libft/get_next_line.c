/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:49:31 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:43:44 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_safe(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

int		ft_store_line(char **line, char **temp, char **str)
{
	if (!(*temp = ft_strjoin(*line, *str)))
	{
		ft_free_safe(line);
		ft_free_safe(str);
		return (-1);
	}
	free(*line);
	if (!(*line = ft_strdup(*temp)))
		return (-1);
	ft_free_safe(temp);
	ft_free_safe(str);
	return (0);
}

int		ft_process(char **buf, char **line, int read_ret)
{
	int		len;
	char	*temp;
	char	*temp2;

	if (!read_ret)
	{
		ft_free_safe(buf);
		read_ret = 1;
		return (0);
	}
	if ((len = ft_find_endl(*buf)) >= 0)
	{
		if (!(temp2 = ft_cut(buf, len)) || (ft_store_line(line, &temp, &temp2)))
			return (-1);
		return (1);
	}
	if ((read_ret < BUFFER_SIZE && *buf) || (len < 0 && read_ret))
	{
		if (ft_store_line(line, &temp, buf))
			return (-1);
	}
	if (read_ret < BUFFER_SIZE && *buf)
		return (0);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char		*buf = NULL;
	int				ret_value;
	static int		read_ret = 1;

	if (read(fd, 0, 0) < 0)
		return (-1);
	if (!(*line = (char*)malloc(sizeof(char) * 1)))
		return (-1);
	*line[0] = 0;
	while (BUFFER_SIZE > 0 && line)
	{
		if ((ret_value = ft_process(&buf, line, read_ret)) >= 0)
			return (ret_value);
		ft_free_safe(&buf);
		if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1)))
			|| (read_ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		buf[read_ret] = 0;
	}
	return (-1);
}
