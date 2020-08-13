/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:10:08 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 12:42:37 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(const char *s, unsigned int i, char c)
{
	unsigned int	start;

	start = i;
	while (s[i] != c && s[i])
		i++;
	return (i - start);
}

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			word++;
		while (s[i] != c && s[i])
			i++;
	}
	return (word);
}

static void		ft_freetab(char **tab, int start)
{
	while (start >= 0)
	{
		free(tab[start]);
		start--;
	}
	free(tab);
}

char			**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	flag;
	size_t			wordnb;

	i = 0;
	flag = 0;
	if (!s || (!(tab = (char**)malloc(sizeof(char*) *
						((ft_wordcount(s, c) + 1))))))
		return (NULL);
	wordnb = ft_wordcount(s, c);
	tab[wordnb] = NULL;
	while (flag < wordnb)
	{
		while (s[i] == c)
			i++;
		if (!(tab[flag] = ft_substr(s, i, ft_wordlen(s, i, c))))
		{
			ft_freetab(tab, (int)i);
			return (NULL);
		}
		i = i + ft_strlen(tab[flag]);
		flag++;
	}
	return (tab);
}
/*
**int	main(void)
**{
**	char	**t;
**	size_t	i;
**
**	i = 0;
**	t = ft_split("    ", ' ');
**	free(t);
**	return (0);
**}
*/
