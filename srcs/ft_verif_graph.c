/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 14:11:59 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 18:55:54 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "lem-in.h"

static void		ft_put_weight(t_graph *run, int weight, int *begin);

int				ft_check_graph(t_graph *graph)
{
	t_graph	*end;
	t_graph	*run;
	int		begin;

	begin = 0;
	end = NULL;
	run = graph;
	while (run)
	{
		if (run->begin)
			begin = 1;
		if (run->end)
			end = run;
		run = run->next;
	}
	if (begin == 1 && end)
	{
		begin = 0;
		ft_put_weight(end, 0, &begin);
		if (begin == 1)
			return (1);
	}
	return (0);
}

static void		ft_put_weight(t_graph *run, int weight, int *begin)
{
	t_links	*links;

	links = NULL;
	if (*begin == 0 && run->begin)
		*begin = 1;
	if (run->weight > weight)
		run->weight = weight;
	if (run->links)
		links = run->links;
	while (links)
	{
		if (weight < links->link->weight)
			ft_put_weight(links->link, weight + 1, begin);
		links = links->next;
	}
}

