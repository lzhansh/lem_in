/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:44:39 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:42:31 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_strsplit(char ***strsplit)
{
	char	**current;

	if (strsplit && *strsplit)
	{
		current = ((*strsplit));
		while ((*current))
			free((*(current++)));
		free((*strsplit));
		(*strsplit) = NULL;
	}
}

void	free_ants(t_ant **a)
{
	t_ant	*tmp;

	while ((*a))
	{
		tmp = (*a);
		(*a) = (*a)->next;
		free(tmp);
	}
}

void	free_routes(t_route **r)
{
	t_route	*tmp;

	while ((*r))
	{
		tmp = (*r);
		(*r) = (*r)->next;
		free_links(&(tmp->head));
		free(tmp);
	}
}

void	free_links(t_link **p)
{
	t_link *tmp;

	while ((*p))
	{
		tmp = (*p);
		(*p) = (*p)->next;
		free(tmp);
	}
}

void	free_rooms(t_room **p)
{
	t_room *tmp;

	while ((*p))
	{
		tmp = (*p);
		(*p) = (*p)->next;
		free(tmp->name);
		free(tmp);
	}
}
