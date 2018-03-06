/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:01:43 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/06 00:40:36 by vguerand         ###   ########.fr       */
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
# define MODE 1
# define INIT 100000

# include <stdio.h>


typedef struct		s_pos
{
	int 			x;
	int 			y;
}					t_pos;

typedef struct		s_star
{
	t_pos 			pos;
	struct s_star	*next;
}					t_star;

typedef struct		s_header
{
	int 			val;
	t_pos 			min;
	t_pos 			max;
	t_pos 			size;
}					t_header;

typedef struct		s_mob
{
	char 			**tab;
	t_pos 			max;
	t_pos 			coord;
}					t_mob;

typedef struct		s_sol
{
	t_pos 			pos;
	t_header 		header;
	struct s_sol  	*one;
	struct s_sol  	*two;
	struct s_sol  	*three;
	struct s_sol  	*four;
	struct s_sol  	*next;
}					t_sol;

typedef struct		s_tab
{
	char 			letter_1;
	char 			letter_2;
	int 			cond;
	t_sol 			*sol;
	t_star 			*star;
	t_mob 			plateau;
	t_mob 			piece;
}					t_tab;

t_pos 				find_nbr_sol(t_sol *sol, t_pos coord, int zone);

t_star 				*ft_new_star(t_pos pos);

t_pos 				find_sol(t_sol *sol, t_pos coord, int zone);

t_pos				find_zone(t_sol *sol, t_pos coord, int zone);

int					what_zone(t_header header, t_pos coord, int zone);

t_star 				*ft_return_star(t_mob p, char letter);

void				ft_free(t_tab *p);

void 				aff(t_pos pos);

t_pos				return_false_coord(void);

int					ft_place(t_tab p, int x, int y, t_pos *pos);

t_sol				*ft_find_sol(t_tab p);

int					ft_place_piece(t_tab p, int x, int y, t_pos *pos);

int  				ft_find_place_where(t_tab p, int size_c, int bol);

void 				ft_read(t_mob *p, int bol);

void				ft_first_read(t_tab *p);

void 				ft_aff_lst(t_sol *sol);

int 				ft_solv(t_tab *p);

double					ft_distance(t_pos A, t_pos B);

double				ft_sqrt(int s, double x);

#endif
