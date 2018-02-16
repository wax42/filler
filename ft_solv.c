/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:30:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/10 15:42:49 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_words_tables(char **tab, int max_y)
{
	int i;

	i = 0;
	while (i < max_y)
	{
		ft_putendl(tab[i]);
		i++;
	}
}

void ft_putplateau(t_tab p)
{
	ft_putstr_fd("Plateau bien lu\n", 1);
	ft_putstr_fd("Plateau max.y \n", 1);
	ft_putnbr_fd(p.plateau.max.y, 1);
	ft_putstr_fd("\nPlateau max.x \n", 1);
	ft_putnbr_fd(p.plateau.max.x, 1);
	ft_putchar_fd('\n', 1);
	ft_print_words_tables(p.plateau.tab, p.plateau.max.y);
}

void 	ft_putpiece(t_tab p)
{
	ft_putstr_fd("Piece bien lu\n", 1);
	ft_putstr_fd("\nPiece max.y \n", 1);
	ft_putnbr_fd(p.piece.max.y, 1);
	ft_putstr_fd("\nPiece max.x \n", 1);
	ft_putnbr_fd(p.piece.max.x, 1);

	ft_putchar_fd('\n', 1);
	ft_print_words_tables(p.piece.tab, p.piece.max.y);
}

void ft_putstruct(t_tab p)
{
	ft_putplateau(p);
	ft_putchar_fd('\n', 3);
	ft_putpiece(p);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("Coord de la piece adverse x", 1);
	ft_putnbr_fd(p.plateau.coord.x, 1);
	ft_putendl_fd("\nCoord de la piece adverse y", 1);
	ft_putnbr_fd(p.plateau.coord.y, 1);
	ft_putchar_fd('\n', 1);
}

void ft_putzone(t_sol *sol)
{
	t_sol *header;

	header = sol;
	while (header)
	{
		printf("\nSOLUTION x %d\tSOLUTION y %d\n", header->pos.x, header->pos.y);
		header = header->next;
	}
}

int ft_solv(t_tab *p)
{
	ft_read(&p->plateau, 0);
	ft_read(&p->piece, 1);
	ft_find_where(p);
	p->sol = ft_find_sol(*p);
	//ft_aff_lst(p->sol);
	if (MODE == 1)
		return (ft_sol_opti(p));
	ft_putendl("PAS TROUVER DE SOLUTION");
	return (1);
}
