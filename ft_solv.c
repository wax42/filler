/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:30:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/02 04:48:59 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int ft_sol_opti(t_tab *p, t_star *header)
{
	t_pos pos;
	t_star *tmp;
	int 	dist;
	int 	tmp_int;
	t_pos 	l_aff;

	dist = INIT;
	if (!header->next)
		ft_putstr_fd("FDP_R", 3);
	if (!p->sol)
		ft_putstr_fd("FDP_R", 3);

	tmp = header->next;
	free(header);
	ft_putstr_fd("PREVIOUS", 3);
	while (tmp)
	{
		pos = tmp->pos;
		ft_putstr_fd("befor", 3);
		ft_putnbr_fd(pos.x - DECAL_X, 3);
		ft_putstr_fd("\t", 3);
		ft_putnbr_fd(pos.y - DECAL_Y, 3);
		tmp->pos = find_nbr_sol(p->sol, pos, 1);
		ft_putstr_fd("after", 3);
		if (tmp->pos.x == -9 + DECAL_X || (pos.x == tmp->pos.x && pos.y == tmp->pos.y))
		{
			ft_putstr_fd("Eror", 3);
			ft_putnbr_fd(pos.x - DECAL_X, 3);
			ft_putstr_fd("\t", 3);
			ft_putnbr_fd(pos.y - DECAL_Y, 3);
			ft_putstr_fd("\n", 3);
			if (p->sol->next)
				tmp->pos = p->sol->next->pos;
			else
			{
				ft_putstr_fd("0 0", 3);
				return (0);
			}
		}
		tmp_int = ft_distance(pos, tmp->pos);
		if (pos.x == tmp->pos.x && pos.y == tmp->pos.y)
			tmp_int += p->plateau.max.x;
		if (tmp_int < dist)
		{
			dist = tmp_int;
			l_aff = tmp->pos;
		}
		header = tmp;
		free(tmp);
		tmp = tmp->next;
	}
	free(tmp);
	ft_putnbr_fd(l_aff.x - DECAL_X, 3);
	ft_putstr_fd("\t", 3);
	ft_putnbr_fd(l_aff.y - DECAL_Y, 3);
	ft_putstr_fd("\n", 3);
	ft_putstr_fd("next", 3);
	aff(l_aff);
	ft_free(p);
	return (1);
}

int ft_solv(t_tab *p)
{
	ft_read(&p->plateau, 0);
	ft_read(&p->piece, 1);
	ft_putstr_fd("debug", 3);
	p->star = ft_return_star(p->plateau, p->letter_2);
	p->sol = ft_find_sol(*p);
	if (MODE == 1)
		return (ft_sol_opti(p, p->star));
	ft_putendl("PAS TROUVER DE SOLUTION");
	return (1);
}
