/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 08:48:15 by lzhansha          #+#    #+#             */
/*   Updated: 2019/06/27 12:31:14 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(long double ld)
{
	int		sign;
	int		len;
	long	tmp;
	char	*str;

	sign = (ld < 0 ? -1 : 1);
	len = (ld < 0 ? 1 : 0);
	ld *= sign;
	tmp = (long)ld;
	while (tmp && len++ >= 0)
		tmp /= 10;
	while (ld - (long)ld != 0 && len++ >= 0)
		ld *= 10;
	str = ft_strnew(len);
	while (len >= 0)
	{
		str[--len] = (long)ld % 10 + '0';
		ld /= 10;
		if (sign == -1 && len == 1)
		{
			str[0] = '-';
			break ;
		}
	}
	return (str);
}
