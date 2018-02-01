/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:01:43 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/31 14:57:25 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H
# include "libft/libft.h"
# define DECAL_X 4
# define DECAL_Y 1
# define LETTER_1 'O'
# define LETTER_2 'X'
# define N_ZONE  5 // 2^n + 1
# define ZONE_SIZE 5
# define GRAPH 0
# define WIN_SIZE 1000
# define MODE 1


# include "mlx.h"
# include <stdio.h>

typedef struct		s_pos
{
	int 			x;
	int 			y;
}					t_pos;

typedef struct		s_mob
{
	char 			**tab;
	int				y_max;
	int				x_max;
	t_pos 			coord;
}					t_mob;


typedef struct		s_zone
{
	int		 		header[N_ZONE + 1];
	t_pos 			min[N_ZONE + 1];
	t_pos 			max[N_ZONE + 1];
	struct s_sol  	*next[N_ZONE + 1];
}					t_zone;


typedef struct		s_sol
{
	t_pos 			pos;
	t_zone			zone;
}					t_sol;

typedef struct		s_tab
{
	char 			letter_1;
	char 			letter_2;
	t_sol 			*sol;
	t_mob 			plateau;
	t_mob 			piece;
}					t_tab;



void 				aff(t_pos pos);

int					ft_place(t_tab p, int x, int y, t_pos *pos);

t_sol				*ft_find_sol(t_tab p);

int					ft_place_piece(t_tab p, int x, int y, t_pos *pos);

int  				ft_find_place_where(t_tab p, int size_c, int bol);

void 				ft_read(t_mob *p, int bol);

void				ft_first_read(t_tab *p);

int 				ft_solv(t_tab *p);

int 				ft_sol_opti(t_tab *p);

int					find_nbr_sol(t_tab *p, t_pos pos, int zone);

void 				ft_find_where(t_tab *p);

#endif
