/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:55:31 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:41:30 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_extra_color(const char *fmt, t_list *e)
{
	if (!ft_strncmp(fmt + e->i, "{black}", 7))
		e->ret += write(e->fd, "\x1B[30m", 5);
	else if (!ft_strncmp(fmt + e->i, "{red}", 5))
		e->ret += write(e->fd, "\x1B[31m", 5);
	else if (!ft_strncmp(fmt + e->i, "{green}", 7))
		e->ret += write(e->fd, "\x1B[32m", 5);
	else if (!ft_strncmp(fmt + e->i, "{yellow}", 8))
		e->ret += write(e->fd, "\x1B[33m", 5);
	else if (!ft_strncmp(fmt + e->i, "{blue}", 6))
		e->ret += write(e->fd, "\x1B[34m", 5);
	else if (!ft_strncmp(fmt + e->i, "{magenta}", 9))
		e->ret += write(e->fd, "\x1B[35m", 5);
	else if (!ft_strncmp(fmt + e->i, "{cyan}", 6))
		e->ret += write(e->fd, "\x1B[36m", 5);
	else if (!ft_strncmp(fmt + e->i, "{white}", 7))
		e->ret += write(e->fd, "\x1B[37m", 5);
	else
		return ;
	e->i += 5;
}

void	ft_extra(const char *format, t_list *env)
{
	int	tmp;

	tmp = env->i;
	if (!ft_strncmp(format + env->i, "{eoc}", 5))
	{
		env->ret += write(env->fd, "\x1B[0m", 4);
		env->i += 5;
		return ;
	}
	else
		ft_extra_color(format, env);
	if (tmp == env->i)
		env->ret += write(env->fd, &format[env->i++], 1);
}
