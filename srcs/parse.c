#include "lem_in.h"

static t_type	parse_comment(char *str)
{
	if (!ft_strcmp(str, "##start"))
		return (START);
	else if (!ft_strcmp(str, "##end"))
		return (END);
	return (MIDDLE);
}

void	parse_link(t_lemin *lemin, char *str)
{
	t_link *link;

	add_link(lemin, (link = create_link(lemin, str)));
	ft_strdel(&str);
	while (get_next_line(0, &str) > 0)
	{
		if (!is_link(lemin, str))
		{
			if (!is_comment(str))
				error(LINK_ERROR);
		}
		else
		{
			add_link(lemin, (link = create_link(lemin, str)));
			ft_strdel(&str);
		}
	}
	if (!lemin->links)
		error(LINK_ERROR);
}

void	parse_rooms(t_lemin *lemin, char *str)
{
	t_room	*room;
	t_type	type;

	type = MIDDLE;
	while (get_next_line(0, &str) > 0)
	{
		if (is_comment(str))
		{
			if (is_valid_comment(str))
				type = parse_comment(str);
		}
		else if (is_room(str))
		{
			add_room(lemin, (room = create_room(str, type)));
			type = MIDDLE;
		}
		else if (is_link(lemin, str))
		{
			parse_link(lemin, str);
			break ;
		}
		else
			error("Invalid data");
		if ((lemin->start && type == START) ||
			(lemin->end && type == END))
			error(ROOM_ERROR);
		ft_strdel(&str);
	}
	free(room);
	if (!lemin->start || !lemin->end)
		error(ROOM_ERROR);
}

int		parse_ants(void)
{
	char *str;
	int ants;
	 
	if (get_next_line(0, &str) > 0)
	{
		// ft_putendl_fd(str, 1);
		if (str[0] == '-' || str[0] == '0' || !ft_isdigit(str[0]))
			error(ANT_ERROR);
		ants = ft_atoi(str);
		ft_strdel(&str);
	}
	else
		error(GNL_ERROR);
	return (ants);
}	