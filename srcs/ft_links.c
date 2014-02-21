/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 18:08:18 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 18:54:13 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "lem-in.h"

static void	ft_link_graph(char *line, t_graph **graph);
static void	ft_link(t_graph *tmp1, t_graph *tmp2);
static int	ft_is_newlink(t_graph *first, t_graph *sec);

int			ft_isvalid_link(char *line, t_graph *graph)
{
	char	**link_split;
	int		i;
	t_graph	*tmp1;
	t_graph	*tmp2;

	i = 0;
	tmp1 = NULL;
	tmp2 = NULL;
	link_split = ft_strsplit(line, '-');
	while (link_split[i])
		i++;
	if (i != 2 || ft_strcmp(link_split[0], link_split[1]) == 0)
		return (0);
	while (graph)
	{
		if (ft_strcmp(link_split[0], graph->id) == 0)
			tmp1 = graph;
		if (ft_strcmp(link_split[1], graph->id) == 0)
			tmp2 = graph;
		graph = graph->next;
	}
	if (tmp1 && tmp2)
		return (ft_is_newlink(tmp1, tmp2));
	return (-1);
}

int			ft_getlinks(t_lst **map, t_graph **graph)
{
	int		add;

	while (*map)
	{
		while (ft_is_ignored((*map)->line))
		{
			*map = (*map)->next;
			if (!*map)
				return (-1);
		}
		if ((add = ft_isvalid_link((*map)->line, *graph)) == -1)
			return (-1);
		else if (add == 1)
			ft_link_graph((*map)->line, graph);
		*map = (*map)->next;
	}
	return (-1);
}

static int	ft_is_newlink(t_graph *first, t_graph *sec)
{
	t_links	*tmp;

	tmp = first->links;
	while (tmp)
	{
		if (ft_strcmp(tmp->link->id, sec->id) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_link_graph(char *line, t_graph **graph)
{
	char	*id1;
	char	*id2;
	t_graph	*tmp1;
	t_graph	*tmp2;
	t_graph	*run;

	run = *graph;
	id1 = line;
	id2 = ft_strchr(line, '-');
	*id2 = '\0';
	id2++;
	while (run)
	{
		if (ft_strcmp(run->id, id1) == 0)
			tmp1 = run;
		if (ft_strcmp(run->id, id2) == 0)
			tmp2 = run;
		run = run->next;
	}
	ft_link(tmp1, tmp2);
	ft_link(tmp2, tmp1);
	id2--;
	*id2 = '-';
}

static void	ft_link(t_graph *tmp1, t_graph *tmp2)
{
	t_links	*new;
	t_links	*run;

	if (!(new = (t_links *) malloc(sizeof(t_links))))
		return ;
	new->next = NULL;
	new->link = tmp2;
	if (!tmp1->links)
	{
		tmp1->links = new;
		return ;
	}
	run = tmp1->links;
	while (run->next)
		run = run->next;
	run->next = new;
}
