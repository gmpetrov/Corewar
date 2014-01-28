/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:15:54 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/28 22:19:52 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_list(t_player *list)
{
	t_player	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_putnbr(tmp->nb);
		ft_putstr(" ");
		ft_putstr(tmp->player_name);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

t_player	*ft_add_elem(t_data *d, int nb, char *name)
{
	t_player	*tmp;
	t_player	*new;

	new = (t_player*)malloc(sizeof(t_player));
	new->nb = nb;
	new->player_name = ft_strdup(name);
	new->next = NULL;
	if (d->player == NULL)
		return (new);
	tmp = d->player;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (d->player);
}
