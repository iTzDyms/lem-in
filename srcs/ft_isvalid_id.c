/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 16:51:22 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 18:49:14 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lem-in.h"

static int		ft_check_valid_block(char *line, int *i);
static int		ft_is_new(char *line, t_graph *graph);

/*
** cmd : 1 = start, 0 = end, -1 = no command
*/

int				ft_isvalid_id(char *line, t_graph *graph)
{
	int		i;
	int		ret;

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
		return (ft_is_new(line, graph));
	return (0);
}

/*
** valid block is one space and a digit only.
*/

static int		ft_check_valid_block(char *line, int *i)
{
	int		nb_exist;

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

static int		ft_is_new(char *line, t_graph *graph)
{
	char	*tmp;

	tmp = ft_strchr(line, ' ');
	*tmp = '\0';
	while (graph)
	{
		if (ft_strcmp(line, graph->id) == 0)
		{
			*tmp = ' ';
			return (-1);
		}
		graph = graph->next;
	}
	*tmp = ' ';
	return (1);
}

