/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:36:57 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/03 17:21:53 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _BONUS_H
# define _BONUS_H
# define  DECAL_X 4
# define  DECAL_Y 1
# define  WIN_SIZE 1000
# define  WIN_X 800
# define  WIN_Y 800

# define LETTER_1 'O'
# define LETTER_2 'X'

# define COLOR_J1 220, 120, 154
# define COLOR_J2 255, 51, 51
# define COLOR_NEW 102, 51, 255
# define TERMINAL 1
# define PIECE 1





# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>


typedef struct		s_pos
{
	int 			x;
	int 			y;
}					t_pos;

typedef struct 		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*map;
	int				bpp;
	int				size_line;
	int				endian;
	char 			**tab;
	int 			fd;
	char 			letter;
	int 			color;
	t_pos 			taille;
	t_pos			max;
	t_pos 			pos;
}					t_mlx;

int					ft_exit(int i);

void	mlx_pixel_put_to_image(t_mlx p, int x, int y, int color);

void ft_trace_carre(t_pos taille, t_mlx *p, t_pos pos, int color);

int		rgb_to_hexa(int r, int g, int b);

void ft_duo_read(t_mlx *p);

void ft_read(t_mlx *p);


#endif
