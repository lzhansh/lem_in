#include "lem_in.h"

static t_route	*new_route(void)
{
	t_route	*n;

	if (!(n = (t_route *)malloc(sizeof(t_route))))
		error(INIT_ERROR);
	n->head = NULL;
	n->len = 0;
	n->next = NULL;
	return (n);
}

static t_link	*delete_link(t_lemin *lemin, t_link *link)
{
	t_link	*prev;
	t_link	*cur;

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
	link->next = NULL;
	return (link);
}

static void		add_route_node(t_route *route, t_link *link)
{
	t_link	*prev;
	t_link	*cur;

	prev = NULL;
	cur = route->head;
	if (cur)
	{
		while (cur)
		{
			prev = cur;
			cur = cur->next;
		}
		link->prev = prev;
		prev->next = link;
	}
	else
		route->head = link;
	route->len++;
}

static void		add_route(t_lemin *lemin, t_route *route)
{
	t_route	*prev;
	t_route	*cur;

	prev = NULL;
	cur = lemin->routes;
	if (cur)
	{
		while (cur && route->len > cur->len)
		{
			prev = cur;
			cur = cur->next;
		}
		if (!prev)
			lemin->routes = route;
		else
			prev->next = route;
		route->next = cur;
	}
	else
		lemin->routes = route;
}

void				create_routes(t_lemin *lemin)
{
	t_route	*route;
	t_link	*link;

	while (lemin->links)
	{
		route = new_route();
		link = find_link(lemin, lemin->start, NULL);
		add_route_node(route, delete_link(lemin, link));
		while (link->end != lemin->end)
		{
			link = find_link(lemin, link->end, NULL);
			add_route_node(route, delete_link(lemin, link));
		}
		add_route(lemin, route);
	}
}