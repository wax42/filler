/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:34:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/08 14:57:07 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_place_cond(t_tab p, t_pos it, t_pos it1, int *val)
{
	if ((it.x + it1.x < DECAL_X || it.y + it1.y < DECAL_Y || it.x + it1.x >= \
		p.plateau.max.x || it.y + it1.y >= p.plateau.max.y) && \
		p.piece.tab[it1.y][it1.x] == '*')
		return (0);
	else if (p.piece.tab[it1.y][it1.x] == '*' && p.plateau.tab[it.y + it1.y]\
	[it.x + it1.x] == p.letter_1)
	{
		(*val)++;
		if (*val > 1)
			return (0);
	}
	else if (p.piece.tab[it1.y][it1.x] == '*' && p.plateau.tab[it.y + it1.y]\
	[it1.x + it.x] != '.')
		return (0);
	return (1);
}

int		ft_place(t_tab p, t_pos it, t_pos *pos, t_pos *aff)
{
	t_pos	it1;
	int		val;

	aff->x = p.piece.max.x + it.x;
	aff->y = p.piece.max.y + it.y;
	*pos = it;
	val = 0;
	it1.y = -1;
	while (++it1.y < p.piece.max.y)
	{
		it1.x = -1;
		while (++it1.x < p.piece.max.x)
		{
			if (p.piece.tab[it1.y][it1.x] == '*')
			{
				(it.y + it1.y < aff->y) ? aff->y = it.y + it1.y : 0;
				(it.x + it1.x < aff->x) ? aff->x = it.x + it1.x : 0;
			}
			if (ft_place_cond(p, it, it1, &val) == 0)
				return (0);
		}
	}
	if (val != 1)
		return (0);
	return (1);
}

t_sol	*ft_init_sol(t_tab p, int x, int y, t_sol *sol)
{
	t_pos	pos;
	t_sol	*tmp;
	t_pos	it;
	t_pos	aff;

	it.x = x;
	it.y = y;
	if (ft_place(p, it, &pos, &aff))
	{
		tmp = (t_sol*)malloc(sizeof(t_sol));
		tmp->pos = pos;
		tmp->aff = aff;
		tmp->next = sol;
		return (tmp);
	}
	return (sol);
}

t_sol	*ft_find_sol(t_tab *p)
{
	t_sol	*sol;
	int		x;
	int		y;

	sol = NULL;
	x = 0;
	p->plateau.coord = p->plateau.max;
	y = -1 * p->piece.max.y;
	while (y < p->plateau.max.y)
	{
		x = -1 * p->piece.max.y;
		while (x < p->plateau.max.x)
		{
			if (x >= DECAL_X && y >= DECAL_Y && p->plateau.tab[y][x] == \
				p->letter_2)
			{
				(y < p->plateau.coord.y) ? p->plateau.coord.y = y : 0;
				(x < p->plateau.coord.x) ? p->plateau.coord.x = x : 0;
			}
			sol = ft_init_sol(*p, x, y, sol);
			x++;
		}
		y++;
	}
	return (sol);
}
