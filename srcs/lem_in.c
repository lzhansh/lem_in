/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:44:39 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:42:31 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_lemin	*init_lemin(void)
{
	t_lemin *lem;

	if (!(lem = (t_lemin *)malloc(sizeof(t_lemin))))
		error(INIT_ERROR);
	lem->total_level = 0;
	lem->ants_start = 0;
	lem->ants_end = 0;
	lem->ant_idx = 0;
	lem->rooms = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->links = NULL;
	lem->routes = NULL;
	lem->ants = NULL;
	lem->pos = NULL;
	return (lem);
}

void			error(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int				main(void)
{
	char	*str;
	t_lemin	*lemin;
	char	*farm;

	str = NULL;
	farm = NULL;
	lemin = init_lemin();
	lemin->ants_start = parse_ants(&farm);
	parse_rooms(lemin, str, &farm);
	set_levels(lemin);
	if (lemin->end->level == -1)
		error(PATH_ERROR);
	check_links(lemin);
	create_routes(lemin);
	ft_printf("%s\n", farm);
	move_ants(lemin);
	// free_lemin(&lemin);
	return (0);
}
