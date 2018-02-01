/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:05:22 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/29 09:18:23 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void ft_first_read(t_tab *p)
{
	char *line;

	get_next_line(0, &line);
	if (line[10] == '1')
	{
		p->letter_1 = 'O';
		p->letter_2 = 'X';
	}
	else if (line[10] == '2')
	{
		p->letter_1 = 'X';
		p->letter_2 = 'O';
	}
	else
		ft_putstr("ERROR\n");
	ft_strdel(&line);
}

static  void ft_read_size(t_mob *p, int decal_x, int decal_y)
{
	char *line;
	int i;

	i = 0;
	if ((get_next_line(0, &line), 3) == -1)
		ft_putendl_fd("ERROR GNL", 3);
	if (ft_strstr(line, "Plateau"))
		i = 8;
	else if (ft_strstr(line, "Piece"))
		i = 5;
	p->y_max = ft_atoi(line + i) + decal_y;
	i += ft_nbrlen(p->y_max, 10) + 1;
	p->x_max = ft_atoi(line + i) + decal_x;
	ft_strdel(&line);
}

void ft_read(t_mob *p, int bol)
{
	int y;
	int decal_x;
	int decal_y;

	(bol == 0) ? (decal_x = DECAL_X) : (decal_x = 0);
	(bol == 0) ? (decal_y = DECAL_Y) : (decal_y = 0);
	ft_read_size(p, decal_x, decal_y);
	if (!(p->tab = (char**)malloc(sizeof(char*) * p->y_max)))
		ft_putendl_fd("ERROR MALLOC", 3);
	y = 0;
	while (y < p->y_max)
	{
		get_next_line(0, &p->tab[y]);
		y++;
	}
}
