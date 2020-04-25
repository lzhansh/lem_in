/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_g.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:47:56 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:42:10 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_g_del(char *tmp)
{
	int	len;

	len = ft_strlen(tmp);
	while (--len >= 0 && tmp[len] == '0')
		tmp[len] = '\0';
}

void	ft_print_g_e(t_list *env, long double ld, char t, int p)
{
	long	num;
	char	*part1;
	char	*e;
	char	*tmp;

	p = (p == 1 ? 0 : p);
	num = ft_print_e_num(ld, p);
	part1 = ft_ftoa(num);
	ft_print_e_exp(ld, t, &e);
	tmp = ft_print_efg_str(part1, 1 + (ld < 0 ? 1 : 0), p + (ld < 0 ? 1 : 0),
	env->flag.hash);
	if (!env->flag.hash)
		ft_print_g_del(tmp);
	env->out = ft_strjoin(tmp, e);
	free(tmp);
	free(part1);
	free(e);
}

void	ft_print_g_f(t_list *env, long double ld, int end)
{
	char	*tmp;
	char	*part1;
	long	num;
	int		p;

	tmp = ft_ltoa((long)ld, 10);
	end -= ft_strlen(tmp) - 1;
	ld == 0 ? --env->flag.prec : 0;
	ld == 0 ? --end : 0;
	p = ft_strlen(tmp);
	num = ft_print_f_num(env, ld, end);
	part1 = (num == 0 ? ft_strdup("000000") : ft_ftoa(num));
	if ((end <= p || ld == (long)ld) && env->flag.hash == 0)
		env->out = ft_strdup(tmp);
	else
		env->out = ft_print_efg_str(part1, p, end, 0);
	if (!env->flag.hash && ld - (long)ld != 0)
		ft_print_g_del(env->out);
	free(tmp);
	free(part1);
}

void	ft_print_g_check(t_list *env, long double ld, char t)
{
	int		sign;
	char	*num;

	sign = (ld < 0 ? -1 : 1);
	ld *= sign;
	if ((ld + 0.5 > 1000000 || ld < 0.0001) && env->flag.prec < 0 && ld != 0)
		return (ft_print_g_e(env, ld * sign, t - 2, 5));
	else if (env->flag.prec < 0)
		return (ft_print_g_f(env, ld * sign, 6));
	num = ft_ltoa((long)ld, 10);
	if (((int)ft_strlen(num) > env->flag.prec && env->flag.prec != 0) ||
	(env->flag.prec == 0 && ld >= 10))
	{
		free(num);
		return (ft_print_g_e(env, ld * sign, t - 2, env->flag.prec - 1));
	}
	free(num);
	ft_print_g_f(env, ld * sign, env->flag.prec);
}

void	ft_print_g(t_list *env, long double ld, char t)
{
	ft_print_g_check(env, ld, t);
	if (env->flag.minus)
	{
		if (ld > 0 && (env->flag.plus || env->flag.sp))
			env->ret += (env->flag.plus == 1 ? write(env->fd, "+", 1) :
			write(env->fd, " ", 1));
		env->ret += write(env->fd, env->out, ft_strlen(env->out));
		ft_print_feg_width(env);
	}
	else
	{
		ft_print_feg_width(env);
		if (ld > 0 && (env->flag.plus || env->flag.sp))
			env->ret += (env->flag.plus == 1 ? write(env->fd, "+", 1) :
			write(env->fd, " ", 1));
		env->ret += write(env->fd, env->out, ft_strlen(env->out));
	}
	env->i++;
	free(env->out);
}
