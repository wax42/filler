/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recherche_zone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:55:42 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/02 04:48:28 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

double	ft_distance(t_pos A, t_pos B)
{
	return (ft_sqrt(((B.x - A.x) * (B.x - A.x)) + ((B.y - A.y) * \
	(B.y - A.y)), -1));
}


t_pos 	find_nbr_sol(t_sol *sol, t_pos coord, int zone)
{
	if (what_zone(sol->header, coord, zone) == 1)
	{
		if (sol->one)
		{
			if (sol->one->header.val == 0)
				return(coord);
			else
				return(find_nbr_sol(sol->one, coord, zone));
		}
		else
			return(find_sol(sol, coord, zone));
	}
	else if (what_zone(sol->header, coord, zone) == 2)
	{
			if (sol->two)
			{
				if (sol->two->header.val == 0)
					return(coord);
				else
					return(find_nbr_sol(sol->two, coord, zone));
			}
			else
				return(find_sol(sol, coord, zone));
	}
	else if (what_zone(sol->header, coord, zone) == 3)
	{
			if (sol->three)
			{
				if (sol->three->header.val == 0)
					return(coord);
				else
					return(find_nbr_sol(sol->three, coord, zone));
			}
			else
				return(find_sol(sol, coord, zone));
	}
	else if (what_zone(sol->header, coord, zone) == 4)
	{
			if (sol->four)
			{
				if (sol->four->header.val == 0)
					return(coord);
				else
					return(find_nbr_sol(sol->four, coord, zone));
			}
			else
				return(find_sol(sol, coord, zone));
	}
	return (coord);
}


int ft_find_min(double *dist, int max)
{
	int i;
	int ret;
	int tmp;

	i = -1;
	tmp = dist[0];
	ret = 0;
	while (++i < max)
	{
		if ((tmp == 0) || (dist[i] != 0 && dist[i] < tmp))
		{
			ret = i;
			tmp = dist[i];
		}
	}
	return (ret);
}

t_pos find_sol(t_sol *sol, t_pos coord, int zone)
{
	if (sol)
	{
		if (sol->header.val == 0)
			return(sol->pos);
		else if (sol->header.val == 1)
			return (find_zone(sol, coord, zone));
	}
	ft_putstr_fd("grave chelou", 3);
	return(coord);
}

t_pos find_zone(t_sol *sol, t_pos coord, int zone)
{
	t_pos	pos[4];
	double		dist[4];
	int		i;

	if (sol->one != NULL)
		pos[0] = find_sol(sol->one, coord, zone);
	else
		pos[0] = return_false_coord(); //NULL
	if (sol->two != NULL)
		pos[1] = find_sol(sol->two, coord, zone);
	else
		pos[1] = return_false_coord();
	if (sol->three != NULL)
		pos[2] = find_sol(sol->three, coord, zone);
	else
		pos[2] = return_false_coord();;
	if (sol->four != NULL)
		pos[3] = find_sol(sol->four, coord, zone);
	else
		pos[3] = return_false_coord();;

	i = -1;
	while (++i < 4)
	{
		if (pos[i].x == -DECAL_X - 1 || (coord.x == pos[i].x && coord.y == pos[i].y))
			dist[i] = 0;
		else
			dist[i] = ft_distance(pos[i], coord);
	}
	i = ft_find_min(dist, 4);
	return (pos[i]);
}
