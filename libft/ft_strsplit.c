/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:34:30 by vmiron          #+#    #+#             */
/*   Updated: 2017/12/01 20:38:46 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nr_count(char *s, char c)
{
	int		i;
	int		rn;
	int		stp;

	i = 0;
	rn = 0;
	stp = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && stp == 0)
		{
			rn++;
			stp++;
		}
		else if (s[i] == c)
			stp = 0;
		i++;
	}
	return (rn);
}

static void		ft_colm_malloc(char **ret, char *s, char c)
{
	int	coln;
	int	i;
	int	line;

	coln = 0;
	i = 0;
	line = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			coln++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				ret[line++] = (char *)malloc(sizeof(char) * (coln + 1));
				i++;
			}
		}
		if (s[i] == c)
			coln = 0;
		i++;
	}
}

static void		ft_isprint_set(char **ret, char *s, char c)
{
	int		i;
	int		line;
	int		coln;

	i = 0;
	line = 0;
	coln = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ret[line][coln++] = s[i];
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				ret[line][coln] = '\0';
				coln = 0;
				line++;
			}
		}
		i++;
	}
	ret[line] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;

	if (s == NULL)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (ft_nr_count((char *)s, c) + 1));
	if (ret == NULL)
		return (NULL);
	ft_colm_malloc(ret, (char *)s, c);
	ft_isprint_set(ret, (char *)s, c);
	return (ret);
}
