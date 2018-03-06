/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:05:22 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/06 08:30:06 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int			rgb_to_hexa(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void		ft_trace_carre(t_pos taille, t_mlx *p, t_pos pos, int color)
{
	t_pos val;

	val.y = pos.y;
	while (val.y < pos.y + taille.y)
	{
		val.x = pos.x;
		while (val.x < pos.x + taille.x)
		{
			mlx_pixel_put_to_image(*p, val.x, val.y, color);
			val.x++;
		}
		val.y++;
	}
}

void		ft_trace_ligne(char *str, t_pos taille, t_mlx *p, t_pos *pos)
{
	int i;

	i = 0;
	pos->x = 0;
	while (str[i])
	{
		if (str[i] == LETTER_1 + 32)
		{
			ft_trace_carre(taille, p, *pos, rgb_to_hexa(102, 51, 255));
			pos->x += taille.x;
		}
		if (str[i] == LETTER_2 + 32)
		{
			ft_trace_carre(taille, p, *pos, rgb_to_hexa(102, 51, 255));
			pos->x += taille.x;
		}
		else if (str[i] == LETTER_1)
		{
			ft_trace_carre(taille, p, *pos, rgb_to_hexa(255, 51, 51));
			pos->x += taille.x;
		}
		else if (str[i] == LETTER_2)
		{
			ft_trace_carre(taille, p, *pos, rgb_to_hexa(220, 120, 154));
			pos->x += taille.x;
		}
		else if (str[i] == '.')
			pos->x += taille.x;
		i++;
	}
}

static void	ft_read_size(t_pos *p, int fd)
{
	char	*line;
	int		i;
	int		ret;

	i = DECAL_X;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ft_strstr(line, "Plateau"))
		{
			i = 8;
			break ;
		}
		if (ft_strstr(line, "=="))
		{
			ft_putstr(line);
			ft_exit(2);
		}
		ft_strdel(&line);
	}
	if (ret != 1)
		ft_exit(4);
	if (i == 0)
		ft_exit(-1);
	p->y = ft_atoi(line + i);
	i += ft_nbrlen(p->y) + 1;
	p->x = ft_atoi(line + i);
	ft_strdel(&line);
	(get_next_line(fd, &line) == -1) ? ft_exit(1) : 0;
	ft_strdel(&line);
}

void		ft_read(t_mlx *p)
{
	int		y;
	t_pos	pos;
	t_pos	max;
	char	*line;

	ft_read_size(&max, p->fd);
	p->taille.x = WIN_X / max.x;
	p->taille.y = WIN_Y / max.y;
	pos.y = 0;
	y = 0;
	while (y < max.y)
	{
		if (!get_next_line(p->fd, &line))
			ft_exit(4);
		ft_trace_ligne(line, p->taille, p, &pos);
		(TERMINAL) ? ft_putendl(line) : NULL;
		ft_strdel(&line);
		pos.y += p->taille.y;
		y++;
	}
}
