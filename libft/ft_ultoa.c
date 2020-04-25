/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:22:56 by lzhansha          #+#    #+#             */
/*   Updated: 2019/06/14 13:08:34 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(unsigned long n, int base)
{
	char			*res;
	unsigned long	temp;
	int				len;

	len = 1;
	temp = n;
	while (temp >= (unsigned)base)
	{
		temp /= base;
		++len;
	}
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (n >= (unsigned)base)
	{
		res[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
		n /= base;
	}
	res[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
	return (res);
}
