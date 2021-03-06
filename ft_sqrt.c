/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:17:27 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/06 08:38:21 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

double	ft_sqrt(int s, double x)
{
	double	x_next;
	char	*tmp;

	if (x == -1)
	{
		tmp = ft_itoa(s);
		x = ft_strlen(tmp) * 100;
		ft_strdel(&tmp);
	}
	x_next = (0.5) * (x + (s / x));
	if (x_next == x)
		return (x);
	else
		return (ft_sqrt(s, x_next));
}

double	ft_distance(t_pos a, t_pos b)
{
	return (ft_sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * \
	(b.y - a.y)), -1));
}
