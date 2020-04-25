/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:22:56 by lzhansha          #+#    #+#             */
/*   Updated: 2019/06/14 13:08:47 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long n, int base)
{
	char	*res;
	long	temp;
	int		len;

	len = 1;
	n < 0 ? ++len : 0;
	temp = n < 0 ? -n : n;
	while (temp >= base)
	{
		temp /= base;
		++len;
	}
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	n < 0 ? *res = '-' : 0;
	n < 0 ? n = -n : 0;
	while (n >= base)
	{
		res[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
		n /= base;
	}
	res[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
	return (res);
}
