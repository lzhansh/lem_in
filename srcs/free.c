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

void	free_strsplit(char ***strsplit)
{
	char	**current;

	if (strsplit && *strsplit)
	{
		current = ((*strsplit));
		while ((*current))
			free((*(current++)));
		free((*strsplit));
		(*strsplit) = NULL;
	}
}
