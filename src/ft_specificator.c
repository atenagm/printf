/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specificator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:49:49 by vmiron           #+#    #+#             */
/*   Updated: 2018/01/23 14:51:06 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

int	ft_specificator(char c)
{
	if (ft_strchr("%diDuUxXoOcCsSpfF", c) != NULL)
		return (c);
	return (0);
}
