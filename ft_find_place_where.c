/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place_where.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:58:20 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/25 11:58:28 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int  ft_find_place_where(t_tab p, int size_c, int bol)
{
	int x;
	int y;
	int size_r;

	x = p.plateau.coord.x;
	y = p.plateau.coord.y;
	size_r = 0;
	while (size_r < size_c)
	{
		if (ft_place_piece(p, x + size_r * bol, y + size_c * bol))
			return (1);
		if (ft_place_piece(p, x + size_c * bol, y + size_r * bol))
			return (1);
		size_r++;
	}
	return (0);
}
