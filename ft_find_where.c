/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_where.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:20:54 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/08 00:14:08 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void ft_find_where(t_tab *p)
{
	int y;
	int x;

	y = DECAL_Y;
	while (y < p->plateau.max.y)
	{
		x = DECAL_X;
		while (x < p->plateau.max.x)
		{
			if (p->plateau.tab[y][x] == p->letter_2 + 32)
			{
				p->plateau.coord.x = x;
				p->plateau.coord.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	y = DECAL_Y;
	while (y < p->plateau.max.y)
	{
		x = DECAL_X;
		while (x < p->plateau.max.x)
		{
			if (p->plateau.tab[y][x] == p->letter_2)
			{
				p->plateau.coord.x = x;
				p->plateau.coord.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void aff(t_pos pos)
{
	ft_putnbr(pos.y - DECAL_Y);
	ft_putchar(' ');
	ft_putnbr(pos.x - DECAL_X);
	ft_putchar('\n');
}
