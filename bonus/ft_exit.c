/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:59:44 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/01 01:44:06 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bonus.h"

static void	ft_aff_error(int code)
{
	if (code == -1)
		ft_putendl("ESC");
	else if (code == 0)
		ft_putstr("autre erreur");
	else if (code == 1)
		ft_putstr("READ ERROR");
	else if (code == 1)
		ft_putendl("End");	
	else
		ft_putstr("Keycode invalide\n");
}

int			ft_exit(int i)
{
	ft_aff_error(i);
	exit(0);
}
