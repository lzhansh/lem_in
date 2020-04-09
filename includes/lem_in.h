#ifndef LEM_IN_H
#define LEM_IN_H

#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
// #include ""

#define	ANT_ERROR	"Error: Number of ants should be positive int"
#define	GNL_ERROR	"Error: Cannot read the file"
#define	INIT_ERROR	"Error: Initialization problem"
#define	ROOM_ERROR	"Error: Invalid room"
#define	LINK_ERROR	"Error: Invalid link"

typedef enum
{
	START,
	MIDDLE,
	END
}	t_type;

typedef struct		s_room {
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

typedef struct		s_link {
	t_room			*start;
	t_room			*end;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_ant {
	int				idx;
	t_room			*start;
	t_room			*end;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_path {
	t_link			*head;
	int				len;
	struct s_path	*next;
}					t_path;

typedef struct		s_lemin {
	int				ants_start;
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	t_link			*links;

}					t_lemin;

int		parse_ants(void);
void	parse_rooms(t_lemin *lemin, char *str);

t_lemin	init_lemin(void);

t_room	*create_room(char *str, t_type type);
void	add_room(t_lemin *lemin, t_room *room);

t_link	*create_link(t_lemin *lemin, char *str);
void	add_link(t_lemin *lemin, t_link *link);

void	free_strsplit(char ***strsplit);
void	error(char *s);
bool	is_comment(char *str);
bool	is_valid_comment(char *str);
bool	is_room(char *str);
bool	is_link(t_lemin *lemin, char *str);
t_room	*room_name(t_lemin *lemin, char *str);

#endif

//Parse the input
//Create paths using queue
//
