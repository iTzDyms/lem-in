/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 14:29:26 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 18:55:00 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lem-in.h"

static t_graph	*ft_parsegraph(t_lst *map);
static int		ft_check_cmd(t_lst **map, t_graph **graph);
static int		ft_is_cmd(char *line);

void			ft_parsedat(t_dat *dat, t_lst *map)
{
	int		i;
	int		error;

	i = 0;
	error = 0;
	while (map && map->line && map->line[i])
	{
		if (!ft_isdigit(map->line[i]))
			error = 1;
		i++;
	}
	if (map->line)
		dat->nb = ft_atoi(map->line);
	dat->graph = NULL;
	if (dat->nb <= 0 || error == 1)
		return ;
	dat->graph = ft_parsegraph(map->next);
}

/*
**bol : 0 = line is correct, 1 = test is incorect, -1 = fatal
*/

static t_graph	*ft_parsegraph(t_lst *map)
{
	t_graph	*graph;
	int		bol;

	bol = 1;
	graph = NULL;
	while (map && map->line && bol == 1)
	{
		bol = 0;
		bol = ft_is_ignored(map->line);
		if (bol == 0 && ft_is_link(map->line))
			bol = ft_getlinks(&map, &graph);
		else if (bol == 0 && (bol = ft_isvalid_id(map->line, graph)) == 1)
			graph = ft_getnewnode(graph, map->line, 0);
		bol = (bol == 0 ? ft_check_cmd(&map, &graph) : bol);
		if (bol != -1)
			map = map->next;
	}
	if (map)
		map->line = NULL;
	return (graph);
}

/*
** 1 = start, 2 = end, 0 = no command associated
*/

static int		ft_is_cmd(char *line)
{
	static int	start = 0;
	static int	end = 0;

	if (ft_strncmp(line, "##start\0", 8) == 0)
	{
		if (start == 1)
			return (-1);
		start = 1;
		return (1);
	}
	else if (ft_strncmp(line, "##end\0", 6) == 0)
	{
		if (end == 1)
			return (-1);
		end = 1;
		return (2);
	}
	return (0);
}

int				ft_is_ignored(char *line)
{
	if (ft_strncmp(line, "#", 1) == 0 && ft_strncmp(line, "##start\0", 8) != 0
		&& ft_strncmp(line, "##end\0", 6) != 0)
		return (1);
	return (0);
}

static int		ft_check_cmd(t_lst **map, t_graph **graph)
{
	int		cmd;

	if ((cmd = ft_is_cmd((*map)->line)) == -1 || cmd == 0)
		return (cmd);
	if ((*map)->next && (*map)->next->line)
		*map = (*map)->next;
	while (ft_is_ignored((*map)->line) && (*map)->next && (*map)->next->line)
		(*map) = (*map)->next;
	if (!ft_isvalid_id((*map)->line, *graph))
		return (-1);
	*graph = ft_getnewnode(*graph, (*map)->line, cmd);
	return (1);
}
