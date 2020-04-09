#include "lem_in.h"

t_lemin	init_lemin(void)
{
	t_lemin lem;

	// if (!(lem = (t_lemin *)malloc(sizeof(t_lemin))))
	// 	error(INIT_ERROR);
	lem.ants_start = 0;
	lem.rooms = NULL;
	lem.start = NULL;
	lem.end = NULL;
	lem.links = NULL;

	return (lem);
}


