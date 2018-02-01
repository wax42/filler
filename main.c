/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:59:19 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/29 09:10:57 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*

static int		my_key_funct(int keycode, t_mlx *p)
{
	printf("\tKeycode\t%d\n", keycode);
	if (keycode == 53)
		ft_exit(-1);
	p->mlx = 0;
//	(keycode == 35) ? (p->graph.var_mouse = abs(p->var_mouse - 1)) : (p->var_mouse);
	return (0);
}


void 	mlx_bonus(t_mlx *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIN_SIZE, WIN_SIZE, "Filler");
	p->img = mlx_new_image(p->mlx, WIN_SIZE, WIN_SIZE);
	p->map = mlx_get_data_addr(p->img, &p->bpp, &p->size_line, &p->endian);
	mlx_hook(p->win, 2, (1L << 0), my_key_funct, &p);
	mlx_loop(p->mlx);
}

*/


int main(void)
{
	t_tab p;

//	fd  = open("./test",O_CREAT|O_WRONLY, 0777);
	ft_first_read(&p);
	while (1)
	{
		if (ft_solv(&p) == 0)
			break ;
		pause();
	}
	return (0);
}
