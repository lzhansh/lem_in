/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:33:27 by marvin            #+#    #+#             */
/*   Updated: 2020/04/25 12:33:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link		*find_link(t_lemin *lemin, t_room *s, t_room *e)
{
	t_link	*cur;

	cur = lemin->links;
	while (cur)
	{
		if ((s && s == cur->start) || (e && e == cur->end))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

static int	has_output(t_lemin *lemin, t_link *link)
{
	if (link->start == lemin->start)
		return (0);
	if (link->start->output > 1)
		return (1);
	return (has_output(lemin, find_link(lemin, NULL, link->start)));
}

void		remove_i_link(t_lemin *lemin, t_room *room)
{
	t_link	*cur;
	t_link	*tmp;

	cur = lemin->links;
	while (cur && room->input > 1)
	{
		tmp = cur;
		cur = cur->next;
		if (tmp->end == room && has_output(lemin, tmp))
		{
			remove_it(lemin, tmp);
			remove_ends(lemin);
		}
	}
}

static int	len_route(t_lemin *lemin, t_link *link, int len)
{
	if (link->end == lemin->end)
		return (len + 1);
	if (link->end->input > 1)
		return (len + 1);
	return (len_route(lemin, find_link(lemin, link->end, NULL), len + 1));
}

void		remove_o_link(t_lemin *lemin, t_room *room)
{
	t_link	*cur;
	// t_link	*tmp;
	int		min;
	int		len;

	cur = lemin->links;
	min = INT_MAX;
	// tmp = NULL;
	while (cur && room->output > 1)
	{
		if (cur->start == room)
		{
			len = len_route(lemin, cur, 0);
			if (min > len)
			{
				min = len;
				// tmp = cur;
			}
		}
		cur = cur->next;
	}
	remove_ends(lemin);
}