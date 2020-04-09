/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:02:36 by lzhansha          #+#    #+#             */
/*   Updated: 2019/11/06 12:47:09 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*i;
	size_t			b;

	b = 0;
	i = (unsigned char *)s;
	while (b < n)
	{
		i[b] = '\0';
		b++;
	}
	return (s);
}
