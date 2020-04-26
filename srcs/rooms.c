/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:33:34 by marvin            #+#    #+#             */
/*   Updated: 2020/04/25 15:49:16 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_room(char *str, t_type type)
{
	t_room	*r;
	char	**line;
	int		num;

	line = NULL;
	if (!(r = (t_room *)malloc(sizeof(t_room))) ||
		!(line = ft_strsplit(str, ' ', &num)))
		error(ROOM_ERROR);
	r->name = ft_strdup(line[0]);
	r->x = ft_atoi(line[1]);
	r->y = ft_atoi(line[2]);
	r->level = -1;
	r->type = type;
	r->input = 0;
	r->output = 0;
	r->ant = -1;
	r->next = NULL;
	free_strsplit(&line);
	return (r);
}

void	check_room(t_lemin *lemin, t_room *room)
{
	t_room *tmp;

	tmp = lemin->rooms;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, room->name) ||
		(tmp->x == room->x && tmp->y == room->y))
			error(ROOM_ERROR);
		tmp = tmp->next;
	}
}

void	add_room(t_lemin *lemin, t_room *room)
{
	t_room *tmp;

	if ((tmp = lemin->rooms))
	{
		check_room(lemin, room);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = room;
	}
	else
		lemin->rooms = room;
	if (room->type == START)
		lemin->start = room;
	else if (room->type == END)
		lemin->end = room;
}
