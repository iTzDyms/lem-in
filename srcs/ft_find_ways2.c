/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ways2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 18:51:53 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 18:51:54 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem-in.h"
#include <libft.h>

static char		*ft_join_way(char *way, char *add);
static t_path	*ft_send_way(t_graph *graph, char *way, t_path *lst);

t_path			*ft_get_way(t_graph *graph)
{
	t_path	*new;
	t_links	*links;
	char	*way;

	way = NULL;
	new = malloc(sizeof(t_path));
	links = graph->links;
	while (links && !graph->end)
	{
		if (links->link->weight == graph->weight - 1 && !links->link->ran)
		{
			way = ft_join_way(way, graph->id);
			graph = links->link;
			if (!graph->end)
				graph->ran = 1;
			links = graph->links;
		}
		else
			links = links->next;
	}
	return (ft_send_way(graph, way, new));
}

static t_path	*ft_send_way(t_graph *graph, char *way, t_path *new)
{
	if (!graph->end)
	{
		free(way);
		free(new);
		return (NULL);
	}
	way = ft_join_way(way, graph->id);
	if (ft_count_char(way, '-') == 1)
		graph->weight--;
	new->next = NULL;
	new->path = way;
	return (new);
}

static char		*ft_join_way(char *way, char *add)
{
	if (!way)
	{
		way = ft_strdup(add);
		return (way);
	}
	way = ft_strfjoin(way, "-");
	way = ft_strfjoin(way, add);
	return (way);
}
