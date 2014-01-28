/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembleur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 23:06:51 by mmole             #+#    #+#             */
/*   Updated: 2014/01/28 18:03:08 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../libft/includes/libft.h"
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "../op.h"

typedef struct	s_file
{
	char		**tab;
}				t_file;

typedef struct	s_check // struct use for check norme
{
	int		i;
	int		find;
	int		cmp;
	char	**opcode;
}				t_check;

void	ft_extrac_file(int fd, t_file *file, char **argv) // save argv in struct **tab
{
	int		k;
	int		i;
	char	*line;

	k = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
		k++;
	close(fd);
	file->tab = (char **)malloc(sizeof(char) * (k + 1));
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		file->tab[i] = ft_strdup(line);  // error /t pop for nothing !!!!
		/*file->tab[i] = (char *)malloc(sizeof(char) * ft_strlen(line));
		ft_bzero(file->tab[i], ft_strlen(line));
		file->tab[i] = ft_strcpy(file->tab[i], line);*/
		i++;
	}
	file->tab[i] = NULL;
}

int	ft_check_next(t_file *file, t_check *c)  // ckeck line 1 and 2
{
	if (c->i - c->cmp - 1 != 6)
	{
		ft_putendl_fd("Error at line #1 : Syntax error", 2);
		return (-1);
	}
	if (c->find != 2)
	{
		ft_putendl_fd("Error at line #2 : Syntax error", 2);
		return (-1);
	}
	c->i = 0;
	c->cmp = 0;
	while (file->tab[1][c->i])
	{
		if (file->tab[1][c->i] == 34)
			c->find += 1;
		if (c->find == 3)
			c->cmp++;
		c->i++;
	}
	if (c->i - c->cmp - 1 != 9)
	{
		ft_putendl_fd("Error ligne 2", 2);
		return (-1);
	}
	if (c->find != 4)
	{
		ft_putendl_fd("Error ligne 2", 2);
		return (-1);
	}
	return (0);
}

int	ft_check_begin(t_file *file) // ckeck line 1 and 2
{
	t_check	c;

	c.cmp = 0;
	c.find = 0;
	c.i = -1;
	if (ft_strncmp(file->tab[0], ".name", 5) != 0) // verif ligne 1
	{
		ft_putendl_fd("Error ligne 1", 2);
		return (-1);
	}
	if (ft_strncmp(file->tab[1], ".comment", 8) != 0)// verif ligne 2
	{
		ft_putendl_fd("Error ligne 2", 2);
		return (-1);
	}
	while (file->tab[0][++c.i])
	{
		if (file->tab[0][c.i] == 34)
			c.find += 1;
		if (c.find == 1)
			c.cmp++;
	}
	if (ft_check_next(file, &c) == -1)
		return (-1);
	return (0);
}
/*
int	ft_str_opcode(char *tmp, t_check *c) // look opcode
{
	if ((ft_strcmp(tmp, "live") == 0) || (ft_strcmp(tmp, "ld") == 0) \
		(ft_strcmp(tmp, "st") == 0) || (ft_strcmp(tmp, "add") == 0) \
		(ft_strcmp(tmp, "sub") == 0) || (ft_strcmp(tmp, "and") == 0) \
		(ft_strcmp(tmp, "or") == 0) || (ft_strcmp(tmp, "xor") == 0) \
		(ft_strcmp(tmp, "zjmp") == 0) || (ft_strcmp(tmp, "ldi") == 0) \
		(ft_strcmp(tmp, "sti") == 0) || (ft_strcmp(tmp, "fork") == 0) \
		(ft_strcmp(tmp, "lld") == 0) || (ft_strcmp(tmp, "lldi") == 0) \
		(ft_strcmp(tmp, "lfork") == 0) || (ft_strcmp(tmp, "aff") == 0))
		return (1);
	return (0);
}
*/
int	ft_strlook(char *s1, char *s2) // check same occurence
{
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
			return (1);
		s1++;
	}
	return (0);
}

int	ft_check_oneaction(char *str, t_check *c) // check if we are only one action
{
	int		i;
	char	tmp[7];
	char	tmp2;
	int		j;
	size_t	n;

	j = 0;
	i = 0;
	c->find = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] != ' ')
		{
			i++;
			c->find++;
		}
		ft_strncpy(tmp, str, c->find); // extrac opcode of string
		while (c->opcode[j])
		{
//			if (ft_strlook(tmp, c->tab[j]))
//				if (ft_verif_argument(str, c->tab[j], i) != 1)
//					return (-1);
			j++;
		}
		j = 0;
	}
	if (c->find != 1)
		return (-1);
	return (1);
}

t_check	*ft_give_opcode(void) // give opcode // Not final define
{
	t_check *c;
	int	i;
	i = -1;
	c->opcode = (char **)malloc(sizeof(char *) * 17);
	while (++i < 17)
		c->opcode[i] = (char *)malloc(sizeof(char) * 20);
	c->opcode[0] = "live   1 D\n";/////// forme CMD (number arguments) / type, type
	c->opcode[1] = "ld     2 DI-R\n"; // with space nb arguments is in place 7
	c->opcode[2] = "st     2 R-IR\n";
	c->opcode[3] = "add    3 R-R-R\n"; // ex add REG and REG in REG
	c->opcode[4] = "sub    3 R-R-R\n";
	c->opcode[5] = "and    3 RDI-RID-R\n";// (REG | DIR | IND) and (R | D | I) in REG
	c->opcode[6] = "or     3 RID-RID-R\n";
	c->opcode[7] = "xor    3 RID-RID-R\n";
	c->opcode[8] = "zjmp   1 D\n";
	c->opcode[9] = "ldi    3 RDI-DR-R\n";
	c->opcode[10] = "sti   3 R-RDI-DR\n";
	c->opcode[11] = "fork  1 D\n";
	c->opcode[12] = "lld   2 DI-R\n";
	c->opcode[13] = "lldi  3 RDI-DR-R\n";
	c->opcode[14] = "lfork 1 D\n";
	c->opcode[15] = "aff   1 R\n";
	c->opcode[16] = NULL;
	return (c);
}

int	ft_check_file(t_file *file, t_check *c)// check rest file
{
	int	i;
	int	find;

	find = 0;
	i = 2;
	while (file->tab[i])
	{
		if ((file->tab[i][0]) == 59 || (file->tab[i][0] == 35)) // char # and ; have been use for make comment
			i++;
		else if (ft_check_oneaction(file->tab[i], c))
			find += 1;
	}
	if (find == 1)
		return (0);
	return (-1);
}

int	ft_check(t_file *file, t_check *c) // check all file
{
	if (ft_check_begin(file) == -1) // ligne 1 and 2
		return (-1);
	if (ft_check_file(file, c) == -1) // check rest
		return (-1);
	return (0);
}

int ft_error_file(int argc, char **argv, t_file *file, t_check *c) // check error and norme
{
	int		i;
	int		fd;

	fd = 0;
	if (argc == 1)
	{
		ft_putendl_fd("Error, please give your champion.s", 2);
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl_fd("Error Open, please give correct input file", 2);
		return (-1);
	}
	ft_extrac_file(fd, file, argv); // recup arguments

	if (ft_check(file, c) == -1) // check norme
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_file	file;
	t_check	c;

	if (ft_error_file(argc, argv, &file, &c) == -1) // check argv valide, check norme and creat tab with argv
		return (-1);
/*	while (file->tab[i])  // print test
	{
		ft_putendl_fd(file->tab[i], 2);
		i++;
	}*/
	ft_putendl_fd("fin normale", 2);
	return (0);
}
