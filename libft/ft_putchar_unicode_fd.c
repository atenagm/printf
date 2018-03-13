/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_unicode_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 00:25:37 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 15:16:04 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nrbyte(int nb)
{
	int i;

	i = 1;
	while ((nb >>= 1))
		i++;
	return (i);
}

static void	ft_write(int fd, int c)
{
	write(fd, &c, 1);
}

void		ft_putchar_unicode_fd(int c, int fd)
{
	int nrb;

	nrb = ft_nrbyte(c);
	if (nrb > 7)
	{
		if (nrb > 11)
		{
			if (nrb > 16)
			{
				ft_write(fd, (((c >> 18) & 7) | 240));
				ft_write(fd, (((c >> 12) & 63) | 128));
			}
			else
				ft_write(fd, (((c >> 12) & 15) | 224));
			ft_write(fd, (((c >> 6) & 63) | 128));
		}
		else
			ft_write(fd, (((c >> 6) & 31) | 192));
		ft_write(fd, ((c & 63) | 128));
	}
	else
		ft_write(fd, c);
}
