/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 18:53:18 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 18:53:19 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int			ft_is_link(char *line)
{
	char	**line_split;
	int		i;

	if (line[0] == '#')
		return (0);
	line_split = ft_strsplit(line, '-');
	i = 0;
	while (line_split[i])
	{
		free(line_split[i]);
		i++;
	}
	if (i != 2)
		return (0);
	return (1);
}
