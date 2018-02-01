/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:36:57 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/30 15:28:28 by vguerand         ###   ########.fr       */
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

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>


typedef struct		s_pos
{
	int 			x;
	int 			y;
}					t_pos;

typedef struct		s_sol
{
	t_pos 			pos;
	struct s_sol	*next;
}					t_sol;

typedef struct 		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*map;
	int				bpp;
	int				size_line;
	int				endian;
}					t_mlx;

int					ft_exit(int i);

void	mlx_pixel_put_to_image(t_mlx p, int x, int y, int color);

void ft_read(t_mlx *p);


#endif
