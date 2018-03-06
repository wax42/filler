/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:34:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/06 01:35:01 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_sol	*ft_find_sol(t_tab p)
{
	t_sol	*header;
	t_sol	*sol;
	t_sol	*tmp;
	t_pos	pos;
	int		x;
	int		y;

	sol = (t_sol*)malloc(sizeof(t_sol));
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
			}
			x++;
		}
		y++;
	}
	sol->next = NULL;
	return (header);
}
