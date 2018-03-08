/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:01:43 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/08 14:57:45 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H
# include "libft/libft.h"
# define DECAL_X 4
# define DECAL_Y 1
# define LETTER_1 'O'
# define LETTER_2 'X'
# define INIT 100000

# include <stdio.h>

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_star
{
	t_pos			pos;
	struct s_star	*next;
}					t_star;

typedef struct		s_mob
{
	char			**tab;
	t_pos			max;
	t_pos			coord;
}					t_mob;

typedef struct		s_sol
{
	t_pos			pos;
	t_pos			aff;
	struct s_sol	*next;
}					t_sol;

typedef struct		s_tab
{
	char			letter_1;
	char			letter_2;
	int				cond;
	t_sol			*sol;
	t_star			*star;
	t_mob			plateau;
	t_mob			piece;
}					t_tab;

t_pos				find_nbr_sol(t_sol *sol, t_pos coord, int zone);

t_star				*ft_new_star(t_pos pos);

t_star				*ft_return_star(t_mob p, char letter);

void				ft_free(t_tab *p);

void				aff(t_pos pos);

t_sol				*ft_find_sol(t_tab *p);

void				ft_read(t_mob *p, int bol);

void				ft_first_read(t_tab *p);

int					ft_solv(t_tab *p);

double				ft_distance(t_pos a, t_pos b);

double				ft_sqrt(int s, double x);

#endif
