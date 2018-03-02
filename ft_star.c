/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:20:54 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/02 04:13:29 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void ft_put_star(t_mob *p, int x, int y, char letter)
{
	if (p->tab[y][x] == letter)
	{
		if (y != DECAL_Y)
		{
			if (p->tab[y - 1][x] != letter)
				p->tab[y - 1][x] = '*';
		}
		if (y >= p->max.y)
		{
			if (p->tab[y + 1][x] != letter)
				p->tab[y + 1][x] = '*';
		}
		if (x >= p->max.x)
		{
			if (p->tab[y][x + 1] != letter)
				p->tab[y][x + 1] = '*';
		}
		if (x != DECAL_X)
		{
			if (p->tab[y][x - 1] != letter)
				p->tab[y][x - 1] = '*';
		}
	}
}


void ft_creat_star(t_mob *p, char letter)
{
	int y;
	int x;

	y = DECAL_Y;
	while (y < p->max.y)
	{
		x = DECAL_X;
		while (x < p->max.x)
		{
			ft_put_star(p, x, y, letter);
			x++;
		}
		y++;
	}
}

t_star 		*ft_new_star(t_pos pos)
{
	t_star *star;

	star = (t_star*)malloc(sizeof(t_star));
	star->pos = pos;
	star->next = NULL;
	return (star);
}

t_star 		*ft_return_star(t_mob p, char letter)
{
	t_pos pos;
	t_star *tmp;
	t_star *header;

	pos.y = -p.max.y;
	pos.x = -p.max.x;
	header = ft_new_star(pos);
	ft_creat_star(&p, letter);
	tmp = header;
	pos.y = DECAL_Y;
	while (pos.y < p.max.y)
	{
		pos.x = DECAL_X;
		while (pos.x < p.max.x)
		{
			if (p.tab[pos.y][pos.x] == '*')
				tmp->next = ft_new_star(pos);
			pos.x++;
		}
		pos.y++;
	}
	return (header);
}

void aff(t_pos pos)
{
	ft_putnbr(pos.y - DECAL_Y);
	ft_putchar(' ');
	ft_putnbr(pos.x - DECAL_X);
	ft_putchar('\n');
}
