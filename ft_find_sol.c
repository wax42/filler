/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:34:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/01 05:02:00 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_zone init_zone(int xmin, int ymin, int xmax, int ymax)
{
	t_zone zone;
	int i;
	t_pos dist;

	dist.x = (xmax + abs(xmin)) / 2;
	dist.y = (ymax + abs(ymin)) / 2;
	printf("RECHERCHE\t%d\t%d\n", dist.x, dist.y);
	zone.min[0].x = xmin;
	zone.min[0].y = ymin;
	zone.max[0].x = xmax;
	zone.max[0].y = ymax;
	i = 1;
	while (i < N_ZONE)
	{
		if ((i - 1) < 2)
			zone.min[i].y = ymin;
		else
			zone.min[i].y = dist.y + ymin;
		if ((i - 1) % 2 == 0)
			zone.min[i].x = xmin;
		else
			zone.min[i].x = dist.x;
		zone.max[i].x = zone.min[i].x + dist.x;
		zone.max[i].y = zone.min[i].y + dist.y;
		if (dist.x >= ZONE_SIZE && dist.y >= ZONE_SIZE)
			zone.header[i] = 1;
		else
			zone.header[i] = 0;
		i++;
	}
	return (zone);
}

void ft_place_zone(t_sol **header, t_sol *tmp)
{
	int i;
	t_sol *t;
	t_sol *tmp1;

	t = *(header);
	i = 0;
	while (++i < N_ZONE)
	{
		if (t->zone.min[i].x <= tmp->pos.x && t->zone.max[i].x >= \
tmp->pos.x && t->zone.min[i].y <= tmp->pos.y && t->zone.max[i].y >= \
tmp->pos.y)
		{
			if (t->zone.header[i] == 1)
			{
				tmp1 = (t_sol*)malloc(sizeof(t_sol));
				tmp1->zone = init_zone(t->zone.min[i].x, t->zone.min[i].y, t->zone.max[i].x, t->zone.max[i].y);
				ft_place_zone(&tmp1, tmp);
			}
			while (t->zone.next[i] != NULL)
				t = t->zone.next[i];
			t->zone.next[i] = tmp;
			t->zone.next[i]->zone.next[i] = NULL;
			break ;
		}
	}
}

t_sol *ft_find_sol(t_tab p)
{
	t_sol *header;
	t_sol *sol;
	t_sol *tmp;
	t_pos pos;
	int x;
	int y;

	sol = (t_sol*)malloc(sizeof(t_sol));
	sol->zone = init_zone(-p.piece.x_max + DECAL_X, -p.piece.y_max + DECAL_Y, p.plateau.x_max - p.piece.x_max + DECAL_X, p.plateau.y_max - p.piece.y_max + DECAL_Y);
	ft_putstr("pute\n");
	sol->pos.x = 0;
	sol->pos.y = 0;
	x = 0;
	while (++x < N_ZONE)
		sol->zone.next[x] = NULL;
	header = sol;
	y = -1 * p.piece.y_max;
	while (y < p.plateau.y_max)
	{
		x = -1 * p.piece.y_max;
		while (x < p.plateau.x_max)
		{
			if (ft_place(p, x, y, &pos))
			{
				tmp = (t_sol*)malloc(sizeof(t_sol));
				tmp->pos = pos;
				ft_place_zone(&header, tmp);
				sol->zone.next[0] = tmp;
				sol = sol->zone.next[0];
			}
			x++;
		}
		y++;
	}
	sol->zone.next[0] = NULL;
	return (header);
}
