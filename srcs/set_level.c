/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_level.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:33:41 by marvin            #+#    #+#             */
/*   Updated: 2020/04/25 12:33:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_queue	*new_node(t_room *room)
{
	t_queue *new;

	if (!(new = (t_queue *)malloc(sizeof(t_queue))))
		error(INIT_ERROR);
	new->room = room;
	new->next = NULL;
	return (new);
}

static void		add_node(t_queue **q, t_queue *node)
{
	t_queue	*tmp;

	if (q && *q)
	{
		tmp = (*q);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	else
		(*q) = node;
}

static void		set_util(t_lemin *lemin, t_queue **q, t_room *room)
{
	t_link	*tmp;

	tmp = lemin->links;
	while (tmp)
	{
		if (tmp->start == room)
		{
			if (tmp->end->level == -1)
			{
				tmp->end->level = room->level + 1;
				add_node(q, new_node(tmp->end));
			}
		}
		else if (tmp->end == room)
		{
			if (tmp->start->level == -1)
			{
				tmp->start->level = room->level + 1;
				add_node(q, new_node(tmp->start));
			}
		}
		tmp = tmp->next;
	}
}

void			set_levels(t_lemin *lemin)
{
	t_queue	*cur;
	t_queue	*q;

	lemin->start->level = 0;
	q = NULL;
	add_node(&q, new_node(lemin->start));
	while (q != NULL)
	{
		cur = q;
		q = q->next;
		if (cur->room != lemin->end)
		{
			set_util(lemin, &q, cur->room);
			lemin->total_level = cur->room->level;
		}
		else
			lemin->end->level = INT_MAX;
		free(cur);
	}
}
