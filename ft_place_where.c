/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_where.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:55:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/16 00:24:46 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int ft_place(t_tab p, int x, int y, t_pos *pos)
{
	int x1;
	int y1;
	int val;


	pos->x = x;
	pos->y = y;
	val = 0;
	//ft_putstr("pece max");
	//aff(p.piece.max);
//	if (y + p.piece.max.y > p.plateau.max.y)
//		return (0);
//	if (x + p.piece.max.x > p.plateau.max.x)
//		return (0);
	y1 = 0;
	while (y1 < p.piece.max.y)
	{
		x1 = 0;
		while (x1 < p.piece.max.x)
		{
			if ((x + x1 < DECAL_X || y + y1 < DECAL_Y  || x + x1 >= p.plateau.max.x || y + y1 >= p.plateau.max.y) && p.piece.tab[y1][x1] == '*')
				return (0);
			else if (p.piece.tab[y1][x1] == '*' && p.plateau.tab[y + y1][x + x1] == p.letter_1)
			{
				val++;
				if (val > 1)
					return (0);
			}
			else if (p.piece.tab[y1][x1] == '*' && p.plateau.tab[y + y1][x1 + x] != '.')
				return (0);
			x1++;
		}
		y1++;
	}
	if (val != 1)
		return (0);
	pos->x = x;
	pos->y = y;
	//aff(*pos);
	return (1);
}
