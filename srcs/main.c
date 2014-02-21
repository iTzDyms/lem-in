/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 11:59:27 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 19:02:07 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <string.h>
#include <libft.h>

int		main(void)
{
	t_lst	*map;
	t_dat	dat;

	map = NULL;
	map = ft_getmap(map);
	ft_parsedat(&dat, map);
	if (ft_check_graph(dat.graph))
	{
		ft_printmap(map);
		ft_putendl("\n");
		ft_resolve(&dat);
	}
	else
		ft_putendl("ERROR");
	ft_free_map(map);
	return (0);
}
