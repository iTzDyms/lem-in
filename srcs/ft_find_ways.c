/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 18:02:02 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 18:53:02 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lem-in.h"

static void		ft_no_way(t_graph *graph, int *bol);
static void		ft_assignment(t_path **start, t_path **prev, t_path **new);

t_path			*ft_find_ways(t_graph *graph)
{
	t_path	*prev;
	t_path	*start;
	t_path	*new;
	int		bol;

	bol = 1;
	start = NULL;
	while (!graph->begin)
		graph = graph->next;
	while (bol == 1 && graph->weight != -1)
	{
		if ((new = ft_get_way(graph)))
			ft_assignment(&start, &prev, &new);
		else
			ft_no_way(graph, &bol);
	}
	return (start);
}

static void		ft_assignment(t_path **start, t_path **prev, t_path **new)
{
	if (!*start)
	{
		*prev = *new;
		*start = *prev;
	}
	else
	{
		(*prev)->next = *new;
		(*prev) = (*prev)->next;
	}
}

static void		ft_no_way(t_graph *graph, int *bol)
{
	int		i;
	t_links	*start_links;

	start_links = graph->links;
	i = 0;
	*bol = 0;
	while (graph->links)
	{
		if (!graph->links->link->ran && !graph->links->link->end)
			*bol = 1;
		if (graph->links->link->weight == graph->weight - 1
			&& graph->links->link->ran == 0)
			i = 1;
		graph->links = graph->links->next;
	}
	if (i == 0)
		graph->weight++;
	graph->links = start_links;
}

