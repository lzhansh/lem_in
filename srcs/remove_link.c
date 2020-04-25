/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:33:20 by marvin            #+#    #+#             */
/*   Updated: 2020/04/25 12:33:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	remove_it(t_lemin *lemin, t_link *link)
{
	t_link *prev;
	t_link *cur;

	prev = NULL;
	cur = lemin->links;
	while (cur && cur != link)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!prev && cur)
		lemin->links = cur->next;
	else if (cur)
		prev->next = cur->next;
	link->start->output > 0 ? link->start->output-- : 0;
	link->end->input > 0 ? link->end->input-- : 0;
	free(link);
}

void	remove_link(t_lemin *lemin)
{
	t_link *cur;
	t_link *tmp;

	cur = lemin->links;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		if (tmp->start->level == -1 ||
			tmp->end->level == -1 ||
			tmp->start->level == tmp->end->level)
			remove_it(lemin, tmp);
	}
}

void	remove_ends(t_lemin *lemin)
{
	t_link	*tmp;
	t_link	*cur;
	int		flag;

	flag = 1;
	while (flag)
	{
		flag = 0;
		cur = lemin->links;
		while (cur)
		{
			tmp = cur;
			cur = cur->next;
			if ((tmp->start != lemin->start &&
				tmp->start->input == 0 &&
				tmp->start->output > 0) ||
				(tmp->end != lemin->end &&
				tmp->end->input > 0 &&
				tmp->end->output == 0))
			{
				remove_it(lemin, tmp);
				flag = 1;
			}
		}
	}
}

void	remove_input(t_lemin *lemin)
{
	int		lvl;
	t_room	*cur;

	lvl = 0;
	while (++lvl <= lemin->total_level)
	{
		cur = lemin->rooms;
		while (cur)
		{
			if (cur->level == lvl && cur->input > 1)
				remove_i_link(lemin, cur);
			cur = cur->next;
		}
	}
}

void	remove_output(t_lemin *lemin)
{
	int		lvl;
	t_room	*cur;

	lvl = lemin->total_level + 1;
	while (--lvl > 0)
	{
		cur = lemin->rooms;
		while (cur)
		{
			if (cur->level == lvl && cur->output > 1)
				remove_o_link(lemin, cur);
			cur = cur->next;
		}
	}
}
