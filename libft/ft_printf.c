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

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	t_list	env;

	ft_bzero(&env, sizeof(env));
	env.fd = 1;
	va_start(env.ap, format);
	while (format[env.i])
	{
		if (format[env.i] == '%' && format[env.i + 1] == '%')
		{
			env.ret += write(env.fd, "%", 1);
			env.i += 2;
		}
		else if (format[env.i] == '%' && format[env.i + 1] != '%')
			ft_convert(format, &env);
		else if (format[env.i] == '{' && format[env.i + 1] != '%')
			ft_extra(format, &env);
		else
			env.ret += write(env.fd, &format[env.i++], 1);
	}
	va_end(env.ap);
	return (env.ret);
}
