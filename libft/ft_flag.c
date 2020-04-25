/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:11:05 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:41:35 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flag_init(t_flag *flag)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->neg = 0;
	flag->sp = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->prec = -1;
	flag->width = 0;
	flag->dr = 0;
	flag->pos = 0;
}

void	ft_flag_perc(t_list *env)
{
	if (env->flag.minus)
	{
		env->ret += write(env->fd, "%", 1);
		while (env->flag.width-- > 1)
			env->ret += write(env->fd, " ", 1);
	}
	else
	{
		while (env->flag.width-- > 1)
			env->ret += (env->flag.zero ? write(env->fd, "0", 1) :
			write(env->fd, " ", 1));
		env->ret += write(env->fd, "%", 1);
	}
	env->i++;
}

void	ft_flag_len_mod(const char *f, t_list *env)
{
	if (f[env->i] == 'h' && f[env->i + 1] != 'h')
		env->mod = pf_h;
	else if (f[env->i] == 'h' && f[env->i + 1] == 'h')
	{
		env->mod = pf_hh;
		env->i++;
	}
	else if (f[env->i] == 'l' && f[env->i + 1] != 'l')
		env->mod = pf_l;
	else if (f[env->i] == 'l' && f[env->i + 1] == 'l')
	{
		env->mod = pf_ll;
		env->i++;
	}
	else if (f[env->i] == 'z')
		env->mod = pf_z;
	else if (f[env->i] == 'L')
		env->mod = pf_L;
}
