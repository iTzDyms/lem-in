/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnewlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 12:20:37 by cheron            #+#    #+#             */
/*   Updated: 2014/02/05 14:05:02 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "lem-in.h"

t_lst	*ft_getnewlst(t_lst *tail, char	*str)
{
	t_lst	*new;

	if (!tail)
	{
		if (!(tail = (t_lst *) malloc(sizeof(t_lst))))
			return (NULL);
		tail->line = str;
		tail->next = NULL;
		return (tail);
	}
	if (!(new = (t_lst *) malloc(sizeof(t_lst))))
		return (NULL);
	new->line = str;
	if (tail)
		tail->next = new;
	new->next = NULL;
	return (new);
}
