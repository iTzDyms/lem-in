/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 14:39:14 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 17:16:28 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <stdlib.h>
#include "lem-in.h"

static void	ft_error(t_lst *map);

void		ft_printmap(t_lst *map)
{
	while (map)
	{
		if (!map->line)
			return ;
		ft_putendl(map->line);
		map = map->next;
	}
}

t_lst		*ft_getmap(t_lst *map)
{
	char	*buf;
	int		ret;
	t_lst	*run;

	map = NULL;
	run = NULL;
	while ((ret = get_next_line(0, &buf)) == 1)
	{
		if (!ft_isconform(buf) || !buf)
			break ;
		if (!(run = ft_getnewlst(run, ft_strdup(buf))))
			ft_error(map);
		if (!map && run)
			map = run;
		free(buf);
	}
	if (ret == -1 || map == NULL)
		ft_error(map);
	else
		free(buf);
	return (map);
}

void		ft_free_map(t_lst *map)
{
	if (map)
		ft_free_map(map->next);
	else
		return ;
	if (map->line)
	{
		free(map->line);
		map->line = NULL;
	}
	free(map);
	map = NULL;
}

static void	ft_error(t_lst *map)
{
	ft_free_map(map);
	ft_fatal("ERROR\n");
}
