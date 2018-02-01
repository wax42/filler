/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:30:34 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/01 14:42:54 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_words_tables(char **tab, int y_max)
{
	int i;

	i = 0;
	while (i < y_max)
	{
		ft_putendl(tab[i]);
		i++;
	}
}

void ft_putplateau(t_tab p)
{
	ft_putstr_fd("Plateau bien lu\n", 1);
	ft_putstr_fd("Plateau y_max \n", 1);
	ft_putnbr_fd(p.plateau.y_max, 1);
	ft_putstr_fd("\nPlateau x_max \n", 1);
	ft_putnbr_fd(p.plateau.x_max, 1);
	ft_putchar_fd('\n', 1);
	ft_print_words_tables(p.plateau.tab, p.plateau.y_max);
}

void 	ft_putpiece(t_tab p)
{
	ft_putstr_fd("Piece bien lu\n", 1);
	ft_putstr_fd("\nPiece y_max \n", 1);
	ft_putnbr_fd(p.piece.y_max, 1);
	ft_putstr_fd("\nPiece x_max \n", 1);
	ft_putnbr_fd(p.piece.x_max, 1);

	ft_putchar_fd('\n', 1);
	ft_print_words_tables(p.piece.tab, p.piece.y_max);
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
	if (!sol)
	{
		printf("On quitte");
		return ;
	}
	header = sol;

	int i = -1;
	while (++i < N_ZONE)
	{
		header = sol;
		printf("\nON passe a la zone %d header %d  \n\n", i, header->zone.header[i]);

		if (header->zone.header[i])
		{
			while (header->zone.header[i] && header->zone.next[i])
			{
				printf("On rentre en profondeur dans la zone%d\t\n", i);
				printf("Xmin\t%d\tXmax\t%d\tYmin\t%d\t Ymax\t%d\n", header->zone.min[i].x,  header->zone.max[i].x , header->zone.min[i].y, header->zone.max[i].y);
				header = header->zone.next[i];
				ft_putzone(header);
			}
		}
		else
		{
			printf("ZONE %d et un HEADER %d\t\n\n", i, header->zone.header[i]);
			printf("Xmin\t%d\tXmax\t%d\tYmin\t%d\t Ymax\t%d\n", header->zone.min[i].x,  header->zone.max[i].x , header->zone.min[i].y, header->zone.max[i].y);
			//header = header->zone.next[i];
			while (header)
			{
				printf("\nSOLUTION x %d\tSOLUTION y %d\n", header->pos.x, header->pos.y);
				header = header->zone.next[i];
			}
		}
	}
}

int ft_solv(t_tab *p)
{
	ft_read(&p->plateau, 0);
	ft_read(&p->piece, 1);
	ft_putstruct(*p);

	p->sol = ft_find_sol(*p);
	ft_putstr("debug");

	ft_find_where(p);
	ft_putstr("debug");

	ft_putzone(p->sol);


	if (MODE == 1)
		return (ft_sol_opti(p));
	else
		ft_putendl("PAS TROUVER DE SOLUTION");
	return (1);
}
