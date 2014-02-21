/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 12:43:30 by cheron            #+#    #+#             */
/*   Updated: 2014/02/21 13:58:59 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "lem-in.h"

static t_path		*ft_set_path_len(t_path *paths);
static void			ft_start_end(t_path *path, int ant);

void				ft_resolve(t_dat *dat)
{
	t_path		*ways;
	t_path		*move;

	move = NULL;
	ways = ft_find_ways(dat->graph);
	ways = ft_set_path_len(ways);
	if (ways->size == 1)
		return (ft_start_end(ways, dat->nb));
	while (dat->nb > 0 || move)
		move = ft_move_ant(dat, ways, move);
}

t_path				*ft_get_move(t_dat *dat, char *path, t_path *move)
{
	static int	i = 1;
	char		*str;
	char		*tmp1;
	t_path		*new;

	new = malloc(sizeof(t_path));
	new->next = NULL;
	new->size = i;
	tmp1 = ft_strchr(path, '-');
	str = ft_strdup(tmp1);
	new->path = str;
	dat->nb--;
	i++;
	if (!move)
		return (new);
	move->next = new;
	return (new);
}

static void			ft_start_end(t_path *path, int ant)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = ft_strchr(path->path, '-');
	while (i < ant)
	{
		if (i != 0)
			ft_putchar(' ');
		i++;
		ft_putstr("L");
		ft_putnbr(i);
		ft_putstr(tmp);
	}
	ft_putendl("");
}

static t_path		*ft_set_path_len(t_path *paths)
{
	t_path		*run;

	run = paths;
	while (run)
	{
		run->size = ft_count_char(run->path, '-');
		run = run->next;
	}
	return (paths);
}

