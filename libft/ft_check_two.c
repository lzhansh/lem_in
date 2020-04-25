/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:03:05 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:41:16 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_check_numb(t_list *env, char t)
{
	long			tmp;
	unsigned long	num;

	num = 0;
	if (env->flag.dr)
		while (--env->flag.pos >= 0)
			tmp = va_arg(env->ap, long);
	else
		tmp = va_arg(env->ap, long);
	if (env->mod == pf_hh)
		num = (unsigned char)tmp;
	else if (env->mod == pf_z || env->mod == pf_l || env->mod == pf_ll)
		num = (unsigned long)tmp;
	else if (env->mod == pf_h)
		num = (unsigned short)tmp;
	else if (env->mod == pf_mod)
		num = (unsigned int)tmp;
	t == 'b' ? env->out = ft_ultoa(num, 2) : 0;
	t == 'o' ? env->out = ft_ultoa(num, 8) : 0;
	(t == 'X' || t == 'x') ? env->out = ft_ultoa(num, 16) : 0;
	if (t == 'x' || t == 'o' || t == 'b')
		ft_strlower(env->out);
	env->flag.minus == 1 ? env->flag.zero = 0 : 0;
	ft_print_numb(env, t, (long)num);
}

static void	ft_check_double_ld(t_list *env, long double *tmp)
{
	if (env->flag.dr)
	{
		while (--env->flag.pos >= 0)
			*tmp = va_arg(env->ap, long double);
		return ;
	}
	*tmp = va_arg(env->ap, long double);
}

static void	ft_check_double_d(t_list *env, double *tmp)
{
	if (env->flag.dr)
	{
		while (--env->flag.pos >= 0)
			*tmp = va_arg(env->ap, double);
		return ;
	}
	*tmp = va_arg(env->ap, double);
}

void		ft_check_double(t_list *env, char t)
{
	double		d;
	long double	ld;

	if (env->mod == pf_L)
		ft_check_double_ld(env, &ld);
	else
	{
		ft_check_double_d(env, &d);
		ld = (long double)d;
	}
	if (t == 'e' || t == 'E')
		return (ft_print_e(env, ld, t));
	if (t == 'g' || t == 'G')
		return (ft_print_g(env, ld, t));
	if (t == 'f')
		return (ft_print_f(env, ld));
}
