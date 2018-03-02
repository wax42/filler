/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:59:19 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/27 21:18:14 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void  ft_aff_lst(t_sol *sol)
{
	if (sol->header.val == 0)
	{
		aff(sol->pos);
		return ;
	}
	if (sol->one)
		ft_aff_lst(sol->one);
	if (sol->two)
		ft_aff_lst(sol->two);
	if (sol->three)
		ft_aff_lst(sol->three);
	if (sol->four)
		ft_aff_lst(sol->four);
}


void ft_lst_free_quadree(t_sol *sol)
{
	if (sol->one && sol->one->header.val == 1)
		ft_lst_free_quadree(sol->one);
	if (sol->two && sol->two->header.val == 1)
		ft_lst_free_quadree(sol->two);
	if (sol->three && sol->three->header.val == 1)
		ft_lst_free_quadree(sol->three);
	if (sol->four && sol->four->header.val == 1)
		ft_lst_free_quadree(sol->four);
	if (sol->header.val)
	{
		if (sol)
			free(sol);
	}
}

void ft_lst_free_next(t_sol *sol)
{
	if (sol->next && !sol->header.val)
		ft_lst_free_next(sol->next);
	if (sol)
	{
		free(sol);
		sol = NULL;
	}
}

void 	ft_free(t_tab *p)
{
	int y;
	t_sol *tmp;

	tmp = p->sol;
	//ft_aff_lst(p->sol);
	ft_lst_free_next(tmp->next);
	ft_lst_free_quadree(p->sol);
	y = -1;
	while (++y < p->plateau.max.y)
		ft_strdel(&p->plateau.tab[y]);
	free(p->plateau.tab);
	y = -1;
	while (++y < p->piece.max.y)
		ft_strdel(&p->piece.tab[y]);
	free(p->piece.tab);
}

int main(void)
{
	t_tab p;
	int fd;

	fd  = open("./test",O_CREAT|O_WRONLY, 0777);
	ft_first_read(&p);
	while (1)
	{
	//	ft_putstr("New Plateau\n");
		if (ft_solv(&p) == 0)
			break ;
	}
	return (0);
}
