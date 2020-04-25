/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:33:01 by marvin            #+#    #+#             */
/*   Updated: 2020/04/25 12:33:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_positions(t_pos **pos)
{
	t_pos	*tmp;

	if (pos)
	{
		while (*pos)
		{
			tmp = (*pos);
			(*pos) = (*pos)->next;
			free(tmp);
		}
	}
}

t_pos	*new_position(int ant, t_room *room)
{
	t_pos	*pos;

	if (!(pos = (t_pos *)malloc(sizeof(t_pos))))
		error(MOVE_ERROR);
	pos->ant = ant;
	pos->room = room;
	pos->next = NULL;
	return (pos);
}

void	add_position(t_lemin *lemin, t_pos *pos)
{
	t_pos *prev;
	t_pos *cur;

	prev = NULL;
	cur = lemin->pos;
	if (cur)
	{
		while (cur && pos->ant > cur->ant)
		{
			prev = cur;
			cur = cur->next;
		}
		if (!prev)
			lemin->pos = pos;
		else
			prev->next = pos;
		pos->next = cur;
	}
	else
		lemin->pos = pos;
}
