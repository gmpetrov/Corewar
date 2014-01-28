/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:20:06 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/28 22:21:42 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_error_ac(int ac)
{
	if (ac <= 1)
	{
		ft_putstr("[USAGE] =  ./corewar [-dump nbr_cycles]\
		[[-n number] champion1.cor] ...\n");
		return (-1);
	}
	return (0);
}

int		ft_occur(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (-1);
	}
	return (1);
}
