/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:35:40 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:41:18 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_int(t_list *env)
{
	long	tmp;
	long	i;

	if (env->flag.dr)
		while (--env->flag.pos >= 0)
			tmp = va_arg(env->ap, long);
	else
		tmp = va_arg(env->ap, long);
	i = (long long)tmp;
	env->flag.minus == 1 ? env->flag.zero = 0 : 0;
	env->flag.prec >= 0 ? env->flag.zero = 0 : 0;
	if (tmp == LONG_MIN || tmp == LLONG_MIN)
		env->out = ft_strdup("-9223372036854775808");
	else if (env->mod == pf_hh)
		env->out = ft_itoa((char)tmp);
	else if (env->mod == pf_h)
		env->out = ft_itoa((short)tmp);
	else if (env->mod == pf_l || env->mod == pf_ll)
		env->out = ft_ltoa(i, 10);
	else if (env->mod == pf_mod)
		env->out = ft_itoa((int)tmp);
	ft_print_digits(env);
}

void	ft_check_unsint(t_list *env)
{
	long	tmp;

	env->flag.sp = 0;
	env->flag.plus = 0;
	if (env->flag.dr)
		while (--env->flag.pos >= 0)
			tmp = va_arg(env->ap, long);
	else
		tmp = va_arg(env->ap, long);
	if (tmp == LONG_MIN || tmp == LLONG_MIN)
		env->out = ft_strdup("-9223372036854775808");
	else if (env->mod == pf_z || env->mod == pf_l || env->mod == pf_ll)
		env->out = ft_ultoa((unsigned long)tmp, 10);
	else if (env->mod == pf_h)
		env->out = ft_ultoa((unsigned short)tmp, 10);
	else if (env->mod == pf_hh)
		env->out = ft_ultoa((unsigned char)tmp, 10);
	else if (env->mod == pf_mod)
		env->out = ft_ultoa((unsigned int)tmp, 10);
	ft_print_digits(env);
}

void	ft_check_char(t_list *env, char t)
{
	char	*str;
	int		c;

	env->flag.minus ? env->flag.zero = 0 : 0;
	if (t == 's')
	{
		if (env->flag.dr)
			while (--env->flag.pos >= 0)
				str = va_arg(env->ap, char *);
		else
			str = va_arg(env->ap, char *);
		if (str == NULL)
			return (ft_print_null_s(env));
		env->out = ft_strdup((char *)str);
		ft_print_s(env);
	}
	else if (t == 'c')
	{
		if (env->flag.dr)
			while (--env->flag.pos >= 0)
				c = va_arg(env->ap, int);
		else
			c = va_arg(env->ap, int);
		ft_print_c(env, c);
	}
}

void	ft_check_ptr(t_list *env)
{
	long			tmp;
	unsigned long	ad;

	if (env->flag.dr)
		while (--env->flag.pos >= 0)
			tmp = va_arg(env->ap, long);
	else
		tmp = va_arg(env->ap, long);
	ad = (unsigned long)tmp;
	if (env->flag.prec == 0)
		env->out = ft_strdup("\0");
	else
		env->out = ft_ltoa(ad, 16);
	ft_print_ptr(env);
}
