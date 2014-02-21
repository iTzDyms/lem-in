/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 15:41:10 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 18:48:39 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "lem-in.h"

static t_graph		*ft_getnode(char *line, int cmd);
static t_graph		*ft_search_node(char *line, t_graph *graph);

t_graph				*ft_getnewnode(t_graph *graph, char *line, int cmd)
{
	t_graph	*new;
	t_graph	*tmp;

	tmp = graph;
	if (!graph)
		return (ft_getnode(line, cmd));
	if (!(new = ft_search_node(line, graph)))
	{
		new = ft_getnode(line, cmd);
		new->next = graph;
		return (new);
	}
	graph->begin = (cmd == 1 ? '1' : 0);
	graph->end = (cmd == 2 ? '1' : 0);
	return (tmp);
}

static t_graph		*ft_getnode(char *line, int cmd)
{
	t_graph	*graph;
	char	**line_split;

	if (!(graph = (t_graph *) malloc(sizeof(t_graph))))
		return (NULL);
	line_split = ft_strsplit(line, ' ');
	graph->id = line_split[0];
	graph->x = ft_atoi(line_split[1]);
	graph->y = ft_atoi(line_split[2]);
	graph->weight = 2147483647;
	graph->ran = 0;
	free(line_split[1]);
	free(line_split[2]);
	graph->links = NULL;
	graph->begin = (cmd == 1 ? '1' : 0);
	graph->end = (cmd == 2 ? '1' : 0);
	graph->next = NULL;
	return (graph);
}

static t_graph		*ft_search_node(char *line, t_graph *graph)
{
	line = ft_strchr(line, ' ');
	*line = '\0';
	while (graph)
	{
		if (ft_strcmp(line, graph->id) == 0)
		{
			*line = ' ';
			return (graph);
		}
		graph = graph->next;
	}
	*line = ' ';
	return (NULL);
}

