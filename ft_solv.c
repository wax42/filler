/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:30:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/08 15:14:23 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "math.h"

t_pos		ft_find_next(t_sol *sol, t_pos pos)
{
	t_sol	*tmp;
	double	dist;
	double	tmp_int;
	t_pos	l_aff;

	tmp = sol;
	l_aff = pos;
	dist = (double)INIT;
	while (tmp)
	{
		if (pos.x == tmp->aff.x && pos.y == tmp->aff.y)
			tmp_int = 0;
		else
			tmp_int = ft_distance(pos, tmp->aff);
		if (tmp_int < dist)
		{
			dist = tmp_int;
			l_aff = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (l_aff);
}

int			ft_sol_opti_norm(t_tab *p, t_star *header, t_star *tmp, \
	t_pos *l_aff)
{
	t_pos	pos;
	double	dist;
	double	tmp_int;

	dist = (double)INIT;
	while (tmp)
	{
		pos = tmp->pos;
		if (p->sol)
			tmp->pos = ft_find_next(p->sol, pos);
		else
			return (0);
		(pos.x == tmp->pos.x && pos.y == tmp->pos.y) ? tmp_int = 0 : 0;
		(tmp_int != 0) ? tmp_int = ft_distance(pos, tmp->pos) : 0;
		if (tmp_int < dist)
		{
			dist = tmp_int;
			*l_aff = tmp->pos;
		}
		header = tmp;
		free(tmp);
		tmp = tmp->next;
	}
	free(tmp);
	return (1);
}

int			ft_sol_opti(t_tab *p, t_star *header)
{
	t_star	*tmp;
	t_pos	l_aff;

	if (p->sol)
		l_aff = p->sol->pos;
	else
	{
		ft_putstr("0 0\n");
		return (0);
	}
	tmp = header->next;
	free(header);
	if (ft_sol_opti_norm(p, header, tmp, &l_aff) == 0)
	{
		ft_putstr("0 0\n");
		return (0);
	}
	aff(l_aff);
	ft_free(p);
	return (1);
}

int			ft_solv(t_tab *p)
{
	t_pos pos;

	ft_read(&p->plateau, 0);
	ft_read(&p->piece, 1);
	p->sol = ft_find_sol(p);
	pos.y = p->plateau.max.y - (p->cond * 3);
	if (p->plateau.coord.x > p->plateau.max.x / 2)
		pos.x = p->plateau.max.x;
	else
		pos.x = 0;
	if (p->cond > p->plateau.max.x / 2 || p->plateau.max.x <= 40)
		p->star = ft_return_star(p->plateau, p->letter_2);
	else
	{
		p->star = ft_new_star(pos);
		p->star->next = ft_new_star(pos);
	}
	p->cond++;
	return (ft_sol_opti(p, p->star));
}
