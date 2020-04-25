/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:23:34 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:42:06 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_print_f_num(t_list *env, long double ld, int p)
{
	int	sign;
	int i;

	i = -1;
	sign = (ld < 0 ? -1 : 1);
	ld *= sign;
	while (++i < p)
		ld *= 10;
	env->mod != pf_L ? ld += 0.5 : 0;
	ld *= sign;
	return ((long)ld);
}

char	*ft_print_f_zeros(long double ld)
{
	int		i;
	int		j;
	char	*res;

	i = (ld < 0 ? 1 : 0);
	j = (ld < 0 ? 1 : 0);
	ld = (ld < 0 ? -ld : ld);
	while (ld < 1)
	{
		ld *= 10;
		i++;
	}
	res = ft_strnew(i);
	res[0] = '-';
	while (i > j)
		res[j++] = '0';
	res[j] = '\0';
	return (res);
}

void	ft_print_f_prec(t_list *env, long double ld)
{
	char	*tmp;
	char	*part1;
	int		p;
	long	num;
	char	*new;

	tmp = ft_ltoa((long)ld, 10);
	ld == 0 ? env->flag.prec-- : 0;
	p = ((ld < 0 && tmp[0] == '0') ? ft_strlen(tmp) + 1 : ft_strlen(tmp));
	num = ft_print_f_num(env, ld, (env->flag.prec >= 0 ? env->flag.prec : 6));
	part1 = (num == 0 ? ft_strdup("0000000") : ft_ftoa(num));
	if (ft_atoi(tmp) == 0 && ld != 0)
	{
		new = ft_strjoin(ft_print_f_zeros(ld), (ld < 0 ? ft_strsub(part1, 1,
		ft_strlen(part1) - 1) : part1));
		part1 = ft_strdup(new);
		free(new);
	}
	if (env->flag.prec == 0)
		env->out = ft_strdup(tmp);
	else
		env->out = ft_print_efg_str(part1, p, env->flag.prec >= 0 ?
		p + env->flag.prec : p + 6, env->flag.hash);
	free(part1);
	free(tmp);
}

void	ft_print_feg_width(t_list *env)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(env->out) + env->flag.plus + (env->flag.plus ? 0 :
	env->flag.sp);
	if (env->flag.prec >= 0)
	{
		while (env->flag.width - ++i > len)
			env->ret += (env->flag.zero ? write(env->fd, "0", 1) :
			write(env->fd, " ", 1));
		i = ((env->flag.plus || env->flag.sp) ? 0 : -1);
		while ((int)ft_strlen(env->out) < len - ++i)
			env->ret += write(env->fd, "0", 1);
	}
	else
		while (env->flag.width - ++i > len)
			env->ret += (env->flag.zero ? write(env->fd, "0", 1) :
			write(env->fd, " ", 1));
}

void	ft_print_f(t_list *env, long double ld)
{
	ft_print_f_prec(env, ld);
	if (env->flag.minus)
	{
		if (ld >= 0 && (env->flag.plus || env->flag.sp))
			env->ret += (env->flag.plus == 1 ? write(env->fd, "+", 1) :
			write(env->fd, " ", 1));
		env->ret += write(env->fd, env->out, ft_strlen(env->out));
		ft_print_feg_width(env);
	}
	else
	{
		ft_print_feg_width(env);
		if (ld >= 0 && (env->flag.plus || env->flag.sp))
			env->ret += (env->flag.plus == 1 ? write(env->fd, "+", 1) :
			write(env->fd, " ", 1));
		env->ret += write(env->fd, env->out, ft_strlen(env->out));
	}
	env->i++;
	free(env->out);
}
