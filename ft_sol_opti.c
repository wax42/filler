/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sol_opti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:05:53 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/16 00:23:59 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int ft_sol_opti(t_tab *p)
{
	int i;
	t_pos pos;

	pos = p->plateau.coord;
	i = 0;
	if (p->sol->next)
	{
		pos = find_nbr_sol(p->sol, pos);
		if (pos.x == -9 + DECAL_X || (pos.x == p->plateau.coord.x && pos.y == p->plateau.coord.y))
		{
			pos = p->sol->next->pos;
		}
		aff(pos);
		ft_free(p);
	}
	else
	{
		ft_putstr("0 0\n");
		ft_putstr("eheh eror\n");
		return (0);
	}
	return (1);
}
