/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:39:21 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/06 18:19:29 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void			ft_trace_piece(char *str, t_mlx *p, t_pos pos, int color)
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

void			ft_put_piece(t_mlx *p, t_pos pos, int color, int free_bol)
{
	int y;

	y = 0;
	while (y < p->max.y)
	{
		ft_trace_piece(p->tab[y], p, pos, color);
		pos.y += p->taille.y;
		if (free_bol == 1)
			ft_strdel(&p->tab[y]);
		y++;
	}
	if (free_bol == 1)
	{
		ft_strdel(&p->tab[y]);
		free(p->tab);
		p->tab = NULL;
	}
}

static int		my_key_funct(int keycode, t_mlx *p)
{
	if (keycode == 53)
		ft_exit(-1);
	if (keycode == 126)
	{
		ft_duo_read(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	}
	return (0);
}

int				ft_openfile(char *files)
{
	int	fd;

	fd = open(files, O_RDONLY);
	if (fd == -1)
		ft_exit(0);
	return (fd);
}

int				main(int argc, char **argv)
{
	t_mlx p;

	if (argc == 2)
		p.fd = ft_openfile(argv[1]);
	else if (argc == 1)
		p.fd = 0;
	else
		ft_putstr("Usage : ./graph <filename>  || ./filler_vm -f path \
		[-i | -p1 path | -p2 path] [-s | -q | -t time] | ./graph\n");
	p.mlx = mlx_init();
	p.img = mlx_new_image(p.mlx, WIN_X, WIN_Y);
	p.map = mlx_get_data_addr(p.img, &p.bpp, &p.size_line, &p.endian);
	ft_read(&p);
	p.win = mlx_new_window(p.mlx, WIN_X, WIN_Y, "Filler");
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_hook(p.win, 2, (1L << 0), my_key_funct, &p);
	mlx_loop(p.mlx);
	return (0);
}
