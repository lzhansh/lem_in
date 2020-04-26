/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:44:39 by lzhansha          #+#    #+#             */
/*   Updated: 2020/04/25 17:12:26 by lzhansha         ###   ########.fr       */
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

void			free_lemin(t_lemin **lemin)
{
	if (*lemin)
	{
		free_ants(&((*lemin)->ants));
		free_positions(&((*lemin)->pos));
		free_routes(&((*lemin)->routes));
		free_links(&((*lemin)->links));
		free_rooms(&((*lemin)->rooms));
		free((*lemin));
		*lemin = NULL;
	}
}

int				main(void)
{
	t_lemin	*lemin;
	char	*farm;

	farm = NULL;
	lemin = init_lemin();
	lemin->ants_start = parse_ants(&farm);
	parse_rooms(lemin, &farm);
	set_levels(lemin);
	if (lemin->end->level == -1)
		error(PATH_ERROR);
	check_links(lemin);
	create_routes(lemin);
	ft_printf("%s\n", farm);
	ft_strdel(&farm);
	move_ants(lemin);
	free_lemin(&lemin);
	while (1) ;
	return (0);
}
