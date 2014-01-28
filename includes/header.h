/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 17:36:15 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/28 22:17:46 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"

/*
**	Structures
*/

typedef struct		s_player
{
	int				nb;
	char			*player_name;
	struct s_player *next;
}					t_player;

typedef struct		s_data
{
	struct s_player	*player;
	int				nbr_cycles;
}					t_data;

/*
**	Prototypes
*/

int		ft_error_ac(int ac);
int		ft_occur(char *s1, char *s2);
void	ft_print_list(t_player *list);
t_player	*ft_add_elem(t_data *d, int nb, char *name);
void	ft_read_op(t_data *d, char **av);

#endif
