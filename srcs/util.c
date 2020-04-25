/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:33:48 by marvin            #+#    #+#             */
/*   Updated: 2020/04/25 12:33:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	is_comment(char *str)
{
	if (str && str[0] == '#')
		return (true);
	return (false);
}

bool	is_valid_comment(char *str)
{
	if (str && !ft_strncmp(str, "##", 2))
		return (true);
	return (false);
}

bool	is_room(char *str)
{
	char **line;
	bool res;
	int num;

	res = false;
	if (!(line = ft_strsplit(str, ' ', &num)))
		error(ROOM_ERROR);
	if (num == 3)
		if (line[0][0] != 'L' && line[0][0] != '#'
			&& ft_isdigit(line[1][0]) && ft_isdigit(line[2][0]))
			res = true;
	free_strsplit(&line);
	return (res);
}

t_room	*room_name(t_lemin *lemin, char *str)
{
	t_room *tmp;

	tmp = lemin->rooms;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, str))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

bool	is_link(t_lemin *lemin, char *str)
{
	char **line;
	int num;

	if (!(line = ft_strsplit(str, '-', &num)))
		error(LINK_ERROR);
	if (num == 2 && room_name(lemin, line[0])
		&& room_name(lemin, line[1]))
		return (true);
	return (false);
}
