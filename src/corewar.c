/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 18:35:32 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/28 23:20:32 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_read_op(t_data *d, char **av)
{
	int		i;

	i = 1;
	while (av[i] != 0)
	{
		if (ft_occur(av[i], "-dump") == 1)
			d->nbr_cycles = ft_atoi(av[i + 1]);
		else if (ft_occur(av[i], "-n") == 1)
			d->player = ft_add_elem(d, ft_atoi(av[i + 1]), av[i + 2]);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_data	d;

	d.player = NULL;
	if (ft_error_ac(ac) == -1)
		return (0);
	ft_read_op(&d, av);
	ft_print_list(d.player);
	return (0);
}
