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

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# define ANT_ERROR "Error: Number of ants should be positive int"
# define GNL_ERROR "Error: Cannot read the file"
# define INIT_ERROR	"Error: Initialization problem"
# define ROOM_ERROR "Error: Invalid room"
# define ROOM2_ERROR "Error: No mandatory comments"
# define LINK_ERROR "Error: Invalid link"
# define PATH_ERROR "Error: There is no valid solution"
# define MOVE_ERROR "Error: Cannot move the ants"

typedef enum
{
	START,
	MIDDLE,
	END
}	t_type;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				level;
	t_type			type;
	int				input;
	int				output;
	int				ant;
	struct s_room	*next;
}					t_room;

typedef struct		s_queue
{
	t_room			*room;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_link
{
	t_room			*start;
	t_room			*end;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_ant
{
	int				idx;
	t_room			*start;
	t_room			*end;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_route
{
	t_link			*head;
	int				len;
	struct s_route	*next;
}					t_route;

typedef struct		s_pos
{
	int				ant;
	t_room			*room;
	struct s_pos	*next;
}					t_pos;

typedef struct		s_lemin
{
	int				ants_start;
	int				ants_end;
	int				ant_idx;
	int				total_level;
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	t_link			*links;
	t_route			*routes;
	t_ant			*ants;
	t_pos			*pos;

}					t_lemin;

int					parse_ants(char **f);
void				parse_rooms(t_lemin *lemin, char *str, char **f);
void				parse_link(t_lemin *lemin, char *str, char **f);

t_room				*create_room(char *str, t_type type);
void				add_room(t_lemin *lemin, t_room *room);
void				check_room(t_lemin *lemin, t_room *room);

t_link				*create_link(t_lemin *lemin, char *str);
void				add_link(t_lemin *lemin, t_link *link);

void				free_strsplit(char ***strsplit);
void				error(char *s);
bool				is_comment(char *str);
bool				is_valid_comment(char *str);
bool				is_room(char *str);
bool				is_link(t_lemin *lemin, char *str);
t_room				*room_name(t_lemin *lemin, char *str);

void				create_routes(t_lemin *lemin);

t_link				*create_link(t_lemin *lemin, char *str);
void				add_link(t_lemin *lemin, t_link *link);
void				check_links(t_lemin *lemin);

void				move_ants(t_lemin *lemin);

void				free_positions(t_pos **pos);
t_pos				*new_position(int ant, t_room *room);
void				add_position(t_lemin *lemin, t_pos *pos);

void				print_ans(t_lemin *lem);

void				remove_it(t_lemin *lemin, t_link *link);
void				remove_link(t_lemin *lemin);
void				remove_ends(t_lemin *lemin);
void				remove_input(t_lemin *lemin);
void				remove_output(t_lemin *lemin);

void				remove_o_link(t_lemin *lemin, t_room *room);
void				remove_i_link(t_lemin *lemin, t_room *room);
t_link				*find_link(t_lemin *lemin, t_room *s, t_room *e);

void				set_levels(t_lemin *lemin);

#endif
