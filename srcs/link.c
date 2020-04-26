/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:32:48 by marvin            #+#    #+#             */
/*   Updated: 2020/04/25 12:32:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link		*create_link(t_lemin *lemin, char *str)
{
	t_link	*link;
	char	**line;
	int		num;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		error(LINK_ERROR);
	if (!(line = ft_strsplit(str, '-', &num)))
		error(LINK_ERROR);
	if (!(link->start = room_name(lemin, line[0]))
		|| !(link->end = room_name(lemin, line[1])))
		error(LINK_ERROR);
	link->next = NULL;
	link->prev = NULL;
	free_strsplit(&line);
	return (link);
}

void		add_link(t_lemin *lemin, t_link *link)
{
	t_link *tmp;

	tmp = lemin->links;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = link;
	}
	else
		lemin->links = link;
}

static void	swap_rooms(t_room **s, t_room **e)
{
	t_room *tmp;

	tmp = *s;
	*s = *e;
	*e = tmp;
}

static void	count_links(t_lemin *lemin)
{
	t_link *l;

	l = lemin->links;
	while (l)
	{
		l->start->output++;
		l->end->input++;
		l = l->next;
	}
}

void		check_links(t_lemin *lemin)
{
	t_link	*l;

	remove_link(lemin);
	l = lemin->links;
	while (l)
	{
		if (l->start->level > l->end->level)
			swap_rooms(&l->start, &l->end);
		l = l->next;
	}
	count_links(lemin);
	remove_ends(lemin);
	remove_input(lemin);
	remove_output(lemin);
}
