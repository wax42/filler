/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sol_opti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:05:53 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/29 16:25:55 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	find_nbr_sol(t_tab *p, t_pos pos, int zone)
{
	t_sol *tmp;

	tmp = p->sol;
	tmp = tmp->zone.next[zone];
	while (tmp)
	{
		if (pos.x == tmp->pos.x && pos.y == tmp->pos.y)
		{
			aff(tmp->pos);
			return (1);
		}
		tmp = tmp->zone.next[zone];
	}
	return (0);
}

int ft_sol_opti(t_tab *p)
{
	int i;
	t_pos pos;

	pos = p->plateau.coord;
	i = 0;
	while (++i < N_ZONE)
	{
		if (p->sol->zone.min[i].x <= pos.x && p->sol->zone.max[i].x >= \
			pos.x && p->sol->zone.min[i].y <= pos.y && p->sol->zone.max[i].y >= \
			pos.y)
		{
			if (find_nbr_sol(p, pos, i))
				return (1);
		}
	}
	ft_putstr("aucun resultat trouvé à Sol opti");
	return (0);
}
