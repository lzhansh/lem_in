/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:50:50 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/13 16:14:41 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;
	int		tmp;

	size = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	flag = ((value < 0 && base == 10) ? 1 : 0);
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	str[0] = (flag == 1 ? '-' : '\0');
	while (size > flag)
	{
		str[(size--) - 1] = tab[ft_abs(value % base)];
		value /= base;
	}
	return (str);
}
