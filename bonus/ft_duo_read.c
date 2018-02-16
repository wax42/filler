/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duo_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 04:13:50 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/08 06:42:19 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static  void ft_read_size(t_pos *p, int fd)
{
	char *line;
	int i;
	int ret;

	i = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		(TERMINAL) ? ft_putendl(line) : NULL;
		if (ft_strstr(line, "Piece"))
		{
			i = 5;
			break ;
		}
		if (ft_strstr(line ,"error") || ft_strstr(line, "got"))
		{
			ft_strdel(&line);
			ft_exit(2);
		}
		if (ft_strstr(line ,"=="))
		{
			ft_strdel(&line);
			get_next_line(fd, &line);
			ft_putendl(line);
			ft_strdel(&line);
			ft_exit(2);
		}
		ft_strdel(&line);
	}
	if (ret != 1)
		ft_exit(4);
	if (i == 0)
		ft_exit(0);
	p->y = ft_atoi(line + i);
	i += ft_nbrlen(p->y) + 1;
	p->x = ft_atoi(line + i);
	ft_strdel(&line);
}

void ft_trace_piece(char *str, t_mlx *p, t_pos pos, int color)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
		{
			ft_trace_carre(p->taille, p, pos, color);
		}
		pos.x += p->taille.x;
		i++;
	}
}

void ft_put_piece(t_mlx *p, t_pos pos, int color, int free_bol)
{
	int y;

	y = 0;
	while (y < p->max.y)
	{
		ft_trace_piece(p->tab[y], p, pos, color);
		pos.y += p->taille.y;
		if (free_bol ==  1)
			ft_strdel(&p->tab[y]);
		y++;
	}
	if (free_bol ==  1)
	{
		ft_strdel(&p->tab[y]);
		free(p->tab);
		p->tab = NULL;
	}
}


void ft_duo_read(t_mlx *p)
{
	int y;
	int i;
	char *line;
	int ret;

	if (p->letter == LETTER_1)
		ft_put_piece(p, p->pos, rgb_to_hexa(COLOR_J1), 1);
	else if (p->letter == LETTER_2)
		ft_put_piece(p, p->pos, rgb_to_hexa(COLOR_J2), 1);
	ft_read_size(&p->max, p->fd);
	y = 0;
	if (!(p->tab = (char**)malloc(sizeof(char*) * p->max.y + 2)))
		ft_exit(1);
	while ((ret = get_next_line(p->fd, &p->tab[y])))
	{
		(PIECE) ? ft_putendl(p->tab[y]) : NULL;
		if (ft_strstr(p->tab[y], "<got"))
			break ;
		if (ft_strstr(p->tab[y], "error"))
		{
			while (--y >= 0)
				ft_strdel(&p->tab[y]);
			(get_next_line(p->fd, &line) == -1) ? ft_exit(1) : 0;
			ft_putstr(line);
			ft_strdel(&line);
			(get_next_line(p->fd, &line) == -1) ? ft_exit(1) : 0;
			ft_putstr(line);
			ft_strdel(&line);
			ft_exit(2);
		}
		y++;
	}
	if (ret != 1)
		ft_exit(4);
	p->letter = p->tab[y][6];
	i = 11;
	p->pos.y = ft_atoi(p->tab[y] + i) * p->taille.y;
	while (p->tab[y][i] != ' ')
		i++;
	p->pos.x = ft_atoi(p->tab[y] + i) * p->taille.x;
	y = 0;
	if (p->letter == LETTER_1 || p->letter == LETTER_2)
			ft_put_piece(p, p->pos, rgb_to_hexa(COLOR_NEW), 0);
}
