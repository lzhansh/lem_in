#include "lem_in.h"

t_queue	*new_node(t_room *room)
{
	t_queue *new;

	if (!(new = (t_queue *)malloc(sizeof(t_queue))))
		error(ERROR_QUEUE);
	new->room = room;
	new->next = NULL;
	return (room);
}

void	set_levels(t_lemin *lemin)
{
	t_queue	*cur;
	t_queue	*q;

	lemin->start->level = 0;
	add_node(&q, new_node(lemin->start));
	while (q != NULL)
	{
		cur = (queue ? queue->next : NULL);
		if (cur->room != lemin->end)
		{
			
		}
	}
}