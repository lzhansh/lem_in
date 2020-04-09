/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:09:03 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/11 01:06:54 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*temp1;
	const unsigned char	*temp2;
	unsigned int		i;

	i = 0;
	temp1 = (unsigned char *)s1;
	temp2 = (const unsigned char *)s2;
	while (i < n)
	{
		temp1[i] = temp2[i];
		if (temp2[i] == (unsigned char)c)
			return (&temp1[i + 1]);
		i++;
	}
	return (NULL);
}
