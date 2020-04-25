/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:32:54 by marvin            #+#    #+#             */
/*   Updated: 2020/04/25 12:32:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	move_next(t_lemin *lemin, t_route *route)
{
	t_link	*link;

	link = route->head;
	while (link->next)
		link = link->next;
	while (link)
	{
		if (link->start->ant != -1 && link->end == lemin->end)
		{
			add_position(lemin, new_position(link->start->ant, link->end));
			link->start->ant = -1;
			lemin->ants_end++;
		}
		else if(link->start->ant != -1)
		{
			add_position(lemin, new_position(link->start->ant, link->end));
			link->end->ant = link->start->ant;
			link->start->ant = -1;
		}
		link = link->prev;
	}
}

static int	lemin_calc(t_lemin *lemin, t_route *route)
{
	int		ret;
	t_route	*cur;

	ret = 0;
	cur = lemin->routes;
	while (cur != route)
	{
		ret += route->len - cur->len;
		cur = cur->next;
	}
	return (ret);
}

static void	move_start(t_lemin *lemin, t_route *route)
{
	if (route->head->end == lemin->end)
	{
		lemin->ants_start--;
		lemin->ants_end++;
		lemin->ant_idx++;
		add_position(lemin, new_position(lemin->ant_idx, route->head->end));
	}
	else
	{
		lemin->ants_start--;
		lemin->ant_idx++;
		route->head->end->ant = lemin->ant_idx;
		add_position(lemin, new_position(route->head->end->ant, route->head->end));
	}
}

void		move_ants(t_lemin *lemin)
{
	t_route *route;

	while (lemin->ants_start || lemin->ant_idx != lemin->ants_end)
	{
		route = lemin->routes;
		while (route)
		{
			move_next(lemin, route);
			route = route->next;
		}
		route = lemin->routes;
		while (route && lemin->ants_start)
		{
			if (lemin->ants_start > lemin_calc(lemin, route))
				move_start(lemin, route);
			route = route->next;
		}
		print_ans(lemin);
		free_positions(&(lemin->pos));
		lemin->pos = NULL;
	}
}