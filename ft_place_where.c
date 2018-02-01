/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_where.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:55:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/29 16:28:13 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


int ft_place(t_tab p, int x, int y, t_pos *pos)
{
	int x1;
	int y1;
	int val;


	val = 0;
	if (y + p.piece.y_max > p.plateau.y_max)
		return (0);
	if (x + p.piece.x_max > p.plateau.x_max)
		return (0);
	y1 = 0;
	while (y1 < p.piece.y_max)
	{
		x1 = 0;
		while (x1 < p.piece.x_max)
		{
			if ((x + x1 < DECAL_X || y + y1 < DECAL_Y) && p.piece.tab[y1][x1] == '*')
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
	ft_putstr("\nON A TROUVE\n");
	aff(*pos);
	pos->x = x;
	pos->y = y;
	return (1);
}

int ft_place_piece(t_tab p, int x, int y, t_pos *pos)
{
	int x1;
	int y1;

	y1 = 0;
	if (y <= 0 || x <= 0)
		return (0);
	if (y > p.plateau.y_max || x > p.plateau.x_max)
		return (0);
//	printf("Y:%d\tX :%d\n", y - DECAL_Y, x - DECAL_X);
	while (y1 < p.piece.y_max)
	{
		x1 = 0;
		while (x1 < p.piece.x_max)
		{
			if (ft_place(p, x + x1, y + y1, pos))
				return (1);
			x1++;
		}
		y1++;
	}
	return (0);
}
