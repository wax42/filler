/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:39:21 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/30 15:31:26 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "stdio.h"

static int		my_key_funct(int keycode, t_mlx *p)
{
	printf("\tKeycode\t%d\n", keycode);
	if (keycode == 53)
		ft_exit(-1);
	if (keycode == 126)
	{
		ft_read(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	}
	p->mlx = 0;
//	(keycode == 35) ? (p->graph.var_mouse = abs(p->var_mouse - 1)) : (p->var_mouse);
	return (0);
}

int main(void)
{
	t_mlx p;

	p.mlx = mlx_init();
	p.img = mlx_new_image(p.mlx, WIN_X, WIN_Y);
	p.map = mlx_get_data_addr(p.img, &p.bpp, &p.size_line, &p.endian);
	ft_read(&p);
	p.win = mlx_new_window(p.mlx, WIN_X + 200, WIN_Y + 200, "Filler");
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_hook(p.win, 2, (1L << 0), my_key_funct, &p);
	mlx_loop(p.mlx);
}
