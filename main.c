/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:59:19 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/06 08:14:31 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_lst_free_next(t_sol *sol)
{
	if (sol->next)
		ft_lst_free_next(sol->next);
	if (sol)
	{
		free(sol);
		sol = NULL;
	}
}

void	ft_free(t_tab *p)
{
	int		y;
	t_sol	*tmp;

	tmp = p->sol;
	ft_lst_free_next(tmp->next);
	y = -1;
	while (++y < p->plateau.max.y)
		ft_strdel(&p->plateau.tab[y]);
	free(p->plateau.tab);
	y = -1;
	while (++y < p->piece.max.y)
		ft_strdel(&p->piece.tab[y]);
	free(p->piece.tab);
}

int		main(void)
{
	t_tab p;

	ft_first_read(&p);
	while (1)
	{
		if (ft_solv(&p) == 0)
			break ;
	}
	return (0);
}
