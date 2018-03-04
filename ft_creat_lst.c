/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:34:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/02 16:28:19 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_sol	*ft_init_header(int min_x, int min_y, int max_x, int max_y)
{
	t_sol *sol;

	sol = (t_sol*)malloc(sizeof(t_sol));
	sol->header.size.x = (max_x - min_x) / 2;
	sol->header.size.y = (max_y - min_y) / 2;
	sol->header.val = 1;
	sol->header.min.x = min_x;
	sol->header.min.y = min_y;
	sol->header.max.x = max_x;
	sol->header.max.y = max_y;
	sol->one = NULL;
	sol->two = NULL;
	sol->three = NULL;
	sol->four = NULL;
	return (sol);
}

void 	ft_place_zone(t_sol *sol, t_sol *tmp)
{
	t_sol *tmp2;

	if (sol->header.min.x > tmp->pos.x)
		return ;
	else if (sol->header.min.y > tmp->pos.y)
		return ;
	else if (sol->header.max.x < tmp->pos.x)
		return ;
	else if (sol->header.max.y < tmp->pos.y)
		return ;
	if (tmp->pos.x >= sol->header.min.x &&\
		tmp->pos.x <= sol->header.max.x - sol->header.size.x &&\
		tmp->pos.y >= sol->header.min.y &&\
		tmp->pos.y <= sol->header.max.y - sol->header.size.y)      ///zone 1
	{
		if (sol->one && sol->one->header.val == 1)
			ft_place_zone(sol->one, tmp);
		else if (!sol->one)
		{
			sol->one = tmp;
			return ;
		}
		else if (sol->one)
		{
			tmp2 = sol->one;
			sol->one = ft_init_header(sol->header.min.x, sol->header.min.y, sol->header.max.x - sol->header.size.x, sol->header.max.y - sol->header.size.y);
			ft_place_zone(sol->one, tmp2);
			ft_place_zone(sol->one, tmp);
		}
	}
	else if (tmp->pos.x >= sol->header.min.x + sol->header.size.x &&\
		tmp->pos.x <= sol->header.max.x &&\
		tmp->pos.y >= sol->header.min.y &&\
		tmp->pos.y <= sol->header.max.y - sol->header.size.y)      ///zone 2
	{
		if (sol->two && sol->two->header.val == 1)
			ft_place_zone(sol->two, tmp);
		else if (!sol->two)
		{
			sol->two = tmp;
			return ;
		}
		else if (sol->two)
		{
			tmp2 = sol->two;
			sol->two = ft_init_header(sol->header.min.x + sol->header.size.x, sol->header.min.y, sol->header.max.x, sol->header.max.y - sol->header.size.y);
			ft_place_zone(sol->two, tmp2);
			ft_place_zone(sol->two, tmp);
		}
	}
	else if (tmp->pos.x >= sol->header.min.x &&\
		tmp->pos.x <= sol->header.max.x - sol->header.size.x &&\
		tmp->pos.y >= sol->header.min.y + sol->header.size.y &&\
		tmp->pos.y <= sol->header.max.y)
	{
		if (sol->three && sol->three->header.val == 1)
			ft_place_zone(sol->three, tmp);
		else if (!sol->three)
		{
			sol->three = tmp;
			return ;
		}
		else if (sol->three)
		{
			tmp2 = sol->three;
			sol->three = ft_init_header(sol->header.min.x, sol->header.min.y + sol->header.size.y, sol->header.max.x - sol->header.size.x, sol->header.max.y);
			ft_place_zone(sol->three, tmp2);
			ft_place_zone(sol->three, tmp);
		}
	}
	else if (tmp->pos.x >= sol->header.min.x + sol->header.size.x &&\
		tmp->pos.x <= sol->header.max.x  &&\
		tmp->pos.y >= sol->header.min.y + sol->header.size.y &&\
		tmp->pos.y <= sol->header.max.y)
	{
		if (sol->four && sol->four->header.val == 1)
			ft_place_zone(sol->four, tmp);
		else if (!sol->four)
		{
			sol->four = tmp;
			return ;
		}
		else if (sol->four)
		{
			tmp2 = sol->four;
			sol->four = ft_init_header(sol->header.min.x + sol->header.size.x, sol->header.min.y + sol->header.size.y, sol->header.max.x, sol->header.max.y);
			ft_place_zone(sol->four, tmp2);
			ft_place_zone(sol->four, tmp);
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

	sol = ft_init_header(-p.piece.max.x, -p.piece.max.y, p.plateau.max.x - p.piece.max.x, p.plateau.max.y - p.piece.max.y);
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
				tmp->header.val = 0;
				//ft_place_zone(header, tmp);
			}
			x++;
		}
		y++;
	}
	sol->next = NULL;
	return (header);
}
