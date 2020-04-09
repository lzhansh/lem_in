#include "lem_in.h"

t_link	*create_link(t_lemin *lemin, char *str)
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

void	add_link(t_lemin *lemin, t_link *link)
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