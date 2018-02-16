/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_zone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:29:20 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/12 17:49:55 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	what_zone(t_header header, t_pos coord)
{
	if (coord.x >= header.min.x &&\
		coord.x <= header.max.x - header.size.x &&\
		coord.y >= header.min.y &&\
		coord.y <= header.max.y - header.size.y)
		return (1);
	else if (coord.x >= header.min.x + header.size.x &&\
		coord.x <= header.max.x &&\
		coord.y >= header.min.y &&\
		coord.y <= header.max.y - header.size.y)
		return (2);
	else if (coord.x >= header.min.x &&\
		coord.x <= header.max.x - header.size.x &&\
		coord.y >= header.min.y + header.size.y &&\
		coord.y <= header.max.y)
		return (3);
	else if (coord.x >= header.min.x + header.size.x &&\
		coord.x <= header.max.x  &&\
		coord.y >= header.min.y + header.size.y &&\
		coord.y <= header.max.y)
		return (4);
	return (0);
}

t_pos return_false_coord(void)
{
	t_pos pos;

	pos.x = -DECAL_X - 1;
	pos.y = -DECAL_X - 1;
	return (pos);
}