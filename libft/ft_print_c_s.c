/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 09:53:31 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:41:54 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_c(t_list *env, char c)
{
	if (env->flag.minus)
	{
		env->ret += write(env->fd, &c, 1);
		while (env->flag.width-- > 1)
			env->ret += (env->flag.zero == 1 ?
			write(env->fd, "0", 1) : write(env->fd, " ", 1));
	}
	else
	{
		while (env->flag.width-- > 1)
			env->ret += (env->flag.zero == 1 ?
			write(env->fd, "0", 1) : write(env->fd, " ", 1));
		env->ret += write(env->fd, &c, 1);
	}
	env->i++;
}

void	ft_print_null_c(t_list *env)
{
	while (env->flag.width-- > 1)
		env->ret += (env->flag.zero == 1 ?
		write(env->fd, "0", 1) : write(env->fd, " ", 1));
	env->ret += write(env->fd, "\0", 1);
	env->i++;
}

void	ft_print_s(t_list *env)
{
	char	*tmp;

	if (env->flag.prec >= 0 && env->flag.prec < (int)ft_strlen(env->out))
	{
		tmp = ft_strsub(env->out, 0, env->flag.prec);
		free(env->out);
		env->out = tmp;
	}
	if (env->flag.minus)
	{
		env->ret += write(env->fd, env->out, (int)ft_strlen(env->out));
		while (env->flag.width-- > (int)ft_strlen(env->out))
			env->ret += (env->flag.zero == 1 ?
			write(env->fd, "0", 1) : write(env->fd, " ", 1));
	}
	else
	{
		while (env->flag.width-- > (int)ft_strlen(env->out))
			env->ret += (env->flag.zero == 1 ?
			write(env->fd, "0", 1) : write(env->fd, " ", 1));
		env->ret += write(env->fd, env->out, ft_strlen(env->out));
	}
	env->i++;
	free(env->out);
}

void	ft_print_null_s(t_list *env)
{
	int	len;

	len = (env->flag.prec < 0 ? 6 : env->flag.prec);
	while (env->flag.width-- > len)
		env->ret += (env->flag.zero == 1 ?
		write(env->fd, "0", 1) : write(env->fd, " ", 1));
	env->ret += write(env->fd, "(null)", len);
	env->i++;
}
