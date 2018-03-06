/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:30:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/06 00:59:32 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "math.h"


void ft_aff_lst(t_sol *sol)
{
	if (sol->next)
		ft_aff_lst(sol->next);
	if (sol)
	{
		ft_putnbr_fd(sol->pos.x - DECAL_X, 3);
		ft_putstr_fd("\t", 3);
		ft_putnbr_fd(sol->pos.y - DECAL_Y, 3);
	}
}

t_pos 		ft_find_next(t_sol *sol, t_pos pos)
{
	t_sol *tmp;
	double 	dist;
	double tmp_int;
	t_pos 	l_aff;

	tmp = sol;
	l_aff = pos;
	dist = (double)INIT;
	while (tmp)
	{
		if (pos.x == tmp->pos.x && pos.y == tmp->pos.y)
			tmp_int = 0;
		else
			tmp_int = fabs(ft_distance(pos, tmp->pos));
		if (tmp_int < dist)
		{
			dist = tmp_int;
			l_aff = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (l_aff);
}

int ft_sol_opti(t_tab *p, t_star *header)
{
	t_pos pos;
	t_star *tmp;
	double 	dist;
	double tmp_int;
	t_pos 	l_aff;

	dist = (double)INIT;
	if (!header->next)
	{
		if (p->sol->next)
			l_aff = p->sol->next->pos;
		else
		{
			ft_putstr("0 0\n");
			ft_putstr_fd("0 0\n", 3);
			ft_putstr_fd("FDP_HEADER\t", 3);
			return (0);
		}
	}
	if (!p->sol)
		ft_putstr_fd("FDP_SOL\t", 3);
	ft_putstr_fd("AFFICHE LA LISTE\n", 3);
	ft_aff_lst(p->sol);
	ft_putstr_fd("FIN de  LA LISTE\n", 3);
	tmp = header->next;
	if (p->sol->next)
		l_aff = p->sol->next->pos;
	free(header);
	while (tmp)
	{
		pos = tmp->pos;
		if (p->sol->next)
			tmp->pos = ft_find_next(p->sol->next, pos);
		else
		{
			ft_putstr_fd("0 0\n", 3);
			ft_putstr("0 0\n");
			return (0);
		}
		if (pos.x == tmp->pos.x && pos.y == tmp->pos.y)
			tmp_int = 0;
		else
			tmp_int = ft_distance(pos, tmp->pos);
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
	ft_putstr_fd("next", 3);
	ft_putnbr_fd(l_aff.x - DECAL_X, 3);
	ft_putstr_fd("\t", 3);
	ft_putnbr_fd(l_aff.y - DECAL_Y, 3);
	ft_putstr_fd("\n", 3);
	aff(l_aff);
	ft_free(p);
	return (1);
}

int ft_solv(t_tab *p)
{
	t_pos pos;

	ft_read(&p->plateau, 0);
	ft_read(&p->piece, 1);
	pos.x = 0;
	pos.y = p->plateau.max.y;
	if (p->cond > p->plateau.max.x / 4 || p->plateau.max.x <= 50)
		p->star = ft_return_star(p->plateau, p->letter_2);
	else
	{
		p->star = ft_new_star(pos);
		p->star->next = ft_new_star(pos);
	}
	p->cond++;
	p->sol = ft_find_sol(*p);
	if (MODE == 1)
		return (ft_sol_opti(p, p->star));
	ft_putendl("PAS TROUVER DE SOLUTION");
	return (1);
}
