#include "lem_in.h"

int		main(void)
{
	char	*str;
	t_lemin	lemin;

	str = NULL;
	lemin = init_lemin();
	lemin.ants_start = parse_ants();
	parse_rooms(&lemin, str);
	set_levels(lemin);
	// printf("great success\n");
	return (0);
}