/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isconform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 15:46:17 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 17:23:55 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lem-in.h"

static int		ft_verif_nb(char *line);
static int		ft_isconform2(char *line, int *phase);
static int		ft_is_room(char *line);
static int		ft_check_valid_block(char *line, int *i);

/*
** phase 0 : expecting ant nb
** phase 1 : expecting room
** phase 2 : expecting room or link
** phase 3 : expecting room (previous line was a command)
** phase 4 : expecting link
*/

int				ft_isconform(char *line)
{
	static int	phase = 0;

	if (ft_is_ignored(line))
		return (1);
	if (phase == 0)
	{
		phase = 1;
		return (ft_verif_nb(line));
	}
	else if (phase == 1 || phase == 2)
	{
		phase = 2;
		if (ft_strncmp(line, "##start\0", 8) == 0
			|| ft_strncmp(line, "##end\0", 6) == 0)
		{
			phase = 3;
			return (1);
		}
		if (ft_is_room(line))
			return (1);
	}
	return (ft_isconform2(line, &phase));
}

static int		ft_isconform2(char *line, int *phase)
{
	if (*phase == 3 && ft_is_room(line))
	{
		*phase = 2;
		return (1);
	}
	else if (*phase == 2 || *phase == 4)
	{
		*phase = 4;
		return (ft_is_link(line));
	}
	return (0);
}

static int		ft_verif_nb(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	i = ft_atoi(line);
	if (i <= 0)
		return (0);
	return (1);
}

static int		ft_is_room(char *line)
{
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	if (line[0] == 'L')
		return (0);
	while (line[i] && line[i] != ' ')
	{
		if (line[i] == '-')
			return (0);
		i++;
	}
	if (i != 0)
		ret = ft_check_valid_block(line, &i);
	if (ret == 1)
		ret = ft_check_valid_block(line, &i);
	if (ret == 1 && !line[i])
		return (1);
	return (0);
}

/*
** valid block is one space and a digit only.
*/

static int		ft_check_valid_block(char *line, int *i)
{
	int			nb_exist;

	if (line[*i] == ' ')
	{
		(*i)++;
		while (line[*i] && ft_isdigit(line[*i]))
		{
			(*i)++;
			nb_exist = 1;
		}
		if (nb_exist == 1)
			return (1);
	}
	return (0);
}
