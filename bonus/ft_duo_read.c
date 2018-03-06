/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duo_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 04:13:50 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/06 18:19:17 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static char		*ft_read_size2(char *line, int fd, int *i, int *ret)
{
	while ((*ret = get_next_line(fd, &line)))
	{
		(TERMINAL) ? ft_putendl(line) : NULL;
		if (ft_strstr(line, "Piece"))
		{
			*i = 5;
			break ;
		}
		if (ft_strstr(line, "error") || ft_strstr(line, "got"))
		{
			ft_strdel(&line);
			ft_exit(2);
		}
		if (ft_strstr(line, "=="))
		{
			ft_strdel(&line);
			get_next_line(fd, &line);
			ft_putendl(line);
			ft_strdel(&line);
			ft_exit(2);
		}
		ft_strdel(&line);
	}
	return (line);
}

static void		ft_read_size(t_pos *p, int fd)
{
	char	*line;
	int		i;
	int		ret;

	i = 0;
	line = NULL;
	line = ft_read_size2(line, fd, &i, &ret);
	if (ret != 1)
		ft_exit(4);
	if (i == 0)
		ft_exit(0);
	p->y = ft_atoi(line + i);
	i += ft_nbrlen(p->y) + 1;
	p->x = ft_atoi(line + i);
	ft_strdel(&line);
}

int				rgb_to_hexa(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static int		ft_duo_read2(t_mlx *p, int y)
{
	int		ret;
	char	*line;

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
	(ret != 1) ? ft_exit(4) : 0;
	return (y);
}

void			ft_duo_read(t_mlx *p)
{
	int		y;
	int		i;

	if (p->letter == LETTER_1)
		ft_put_piece(p, p->pos, rgb_to_hexa(COLOR_J1), 1);
	else if (p->letter == LETTER_2)
		ft_put_piece(p, p->pos, rgb_to_hexa(COLOR_J2), 1);
	ft_read_size(&p->max, p->fd);
	if (!(p->tab = (char**)malloc(sizeof(char*) * p->max.y + 2)))
		ft_exit(1);
	y = ft_duo_read2(p, 0);
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
