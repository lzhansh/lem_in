/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:33:14 by marvin            #+#    #+#             */
/*   Updated: 2020/04/25 12:33:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void print_ans(t_lemin *lemin)
{
	t_pos	*pos;

	pos = lemin->pos;
	while (pos)
	{
		if (pos != lemin->pos)
			ft_printf(" ");
		ft_printf("L%d-%s", pos->ant, pos->room->name);
		pos = pos->next;
	}
	ft_printf("\n");
}
