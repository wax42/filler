/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:34:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/06 08:43:58 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_place(t_tab p, int x, int y, t_pos *pos)
{
	int x1;
	int y1;
	int val;

	pos->x = x;
	pos->y = y;
	val = 0;
	y1 = 0;
	while (y1 < p.piece.max.y)
	{
		x1 = 0;
		while (x1 < p.piece.max.x)
		{
			if ((x + x1 < DECAL_X || y + y1 < DECAL_Y || x + x1 >= p.plateau.max.x || y + y1 >= p.plateau.max.y) && p.piece.tab[y1][x1] == '*')
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
	return (1);
}

t_sol	*ft_find_sol(t_tab p)
{
	t_sol	*header;
	t_sol	*sol;
	t_sol	*tmp;
	t_pos	pos;
	int		x;
	int		y;

	sol = (t_sol*)malloc(sizeof(t_sol));
	sol->pos.x = 0;
	sol->pos.y = 0;
	x = 0;
	header = sol;
	y = -1 * p.piece.max.y;
	while (y < p.plateau.max.y)
	{
		x = -1 * p.piece.max.y;
		while (x < p.plateau.max.x)
		{
			if (ft_place(p, x, y, &pos))
			{
				tmp = (t_sol*)malloc(sizeof(t_sol));
				tmp->pos = pos;
				sol->next = tmp;
				sol = sol->next;
			}
			x++;
		}
		y++;
	}
	sol->next = NULL;
	return (header);
}
