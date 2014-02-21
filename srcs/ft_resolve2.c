/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 15:18:49 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 15:29:51 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "lem-in.h"

static t_path		*ft_jump(t_path *move);
static t_path		*ft_print_move(t_path *move);
static void			ft_print_move2(t_path *run, int *i);
static void			ft_jump2(char **new, t_path **run);

t_path				*ft_move_ant(t_dat *dat, t_path *paths, t_path *move)
{
	t_path		*run;
	t_path		*move_begin;
	int			i;

	i = 0;
	run = paths;
	move_begin = move;
	move = ft_jump(move);
	while (run && (dat->nb >= run->size || i == 0) && dat->nb > 0)
	{
		i = 1;
		move = ft_get_move(dat, run->path, move);
		run = run->next;
		if (!move_begin)
			move_begin = move;
	}
	move_begin = ft_print_move(move_begin);
	return (move_begin);
}


static t_path		*ft_jump(t_path *move)
{
	t_path		*run;
	char		*new;
	t_path		*prev;

	run = move;
	prev = NULL;
	while (run)
	{
		if (run->path)
			ft_jump2(&new, &run);
		prev = run;
		run = run->next;
	}
	return (prev);
}

static void			ft_jump2(char **new, t_path **run)
{
	char		*tmp;

	tmp = ft_strchr((*run)->path + 1, '-');
	if (tmp)
	{
		*new = ft_strdup(tmp);
		free((*run)->path);
		(*run)->path = *new;
	}
	else
	{
		free((*run)->path);
		(*run)->path = NULL;
	}
}

static t_path		*ft_print_move(t_path *move)
{
	int			i;
	t_path		*run;

	i = 0;
	run = move;
	while (run)
	{
		if (run->path)
			ft_print_move2(run, &i);
		run = run->next;
	}
	if (i == 0)
		return (NULL);
	ft_putendl("");
	return (move);
}

static void			ft_print_move2(t_path *run, int *i)
{
	char		*tmp;

	if (*i != 0)
		ft_putchar(' ');
	*i = 1;
	ft_putstr("L");
	ft_putnbr(run->size);
	if ((tmp = ft_strchr(run->path + 1, '-')))
		*tmp = '\0';
	ft_putstr(run->path);
	if (tmp)
		*tmp = '-';
}
