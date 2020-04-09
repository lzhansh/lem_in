/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:36:19 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:41:24 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert_width(t_list *env)
{
	env->flag.width = va_arg(env->ap, int);
	if (env->flag.width < 0)
	{
		env->flag.width = -env->flag.width;
		env->flag.minus = 1;
	}
}

void	ft_convert_prec(const char *f, t_list *env)
{
	if (f[env->i + 1] == '*')
	{
		env->flag.prec = va_arg(env->ap, int);
		env->i += 2;
	}
	else
	{
		env->i++;
		env->flag.prec = ft_atoi(f + env->i);
		while (ft_isdigit(f[env->i]))
			env->i++;
	}
}

void	ft_convert_flag(const char *f, t_list *env)
{
	while (ft_strchr(FLAGS, f[env->i]))
	{
		f[env->i] == '-' ? env->flag.minus = 1 : 0;
		f[env->i] == '+' ? env->flag.plus = 1 : 0;
		f[env->i] == ' ' ? env->flag.sp = 1 : 0;
		f[env->i] == '#' ? env->flag.hash = 1 : 0;
		f[env->i] == '0' ? env->flag.zero = 1 : 0;
		f[env->i] == '*' ? ft_convert_width(env) : 0;
		(f[env->i] == 'h' || f[env->i] == 'l' || f[env->i] == 'L' ||
		f[env->i] == 'z') ? ft_flag_len_mod(f, env) : 0;
		if (f[env->i] == '.')
			ft_convert_prec(f, env);
		else if (f[env->i] >= '1' && f[env->i] <= '9')
		{
			env->flag.width = ft_atoi(f + env->i);
			while (f[env->i] >= '0' && f[env->i] <= '9')
				++env->i;
		}
		else if (f[env->i] == '\0')
			break ;
		else
			++env->i;
	}
}

void	ft_convert_spec(const char *f, t_list *env)
{
	if (f[env->i] == '%')
		ft_flag_perc(env);
	else if ((f[env->i] == 'd' || f[env->i] == 'i') && env->mod != pf_z)
		ft_check_int(env);
	else if (f[env->i] == 'u' || ((f[env->i] == 'd' || f[env->i] == 'i') &&
	env->mod == pf_z))
		ft_check_unsint(env);
	else if ((f[env->i] == 'c' || f[env->i] == 's') && env->mod != pf_l)
		ft_check_char(env, f[env->i]);
	else if (f[env->i] == 'p')
		ft_check_ptr(env);
	else if (f[env->i] == 'r')
		ft_print_nonprnt(env);
	else if (f[env->i] == 'b' || f[env->i] == 'o' || f[env->i] == 'x' ||
	f[env->i] == 'X')
		ft_check_numb(env, f[env->i]);
	else if (f[env->i] == 'f' || f[env->i] == 'F' || f[env->i] == 'g' ||
	f[env->i] == 'G' || f[env->i] == 'e' || f[env->i] == 'E')
		ft_check_double(env, f[env->i]);
}

/*
** ft_convert is called if there is '%' character in format string. First, it
** initializes flags to 0. If there are digits after '%' , save it in 'num'.
*/

void	ft_convert(const char *f, t_list *env)
{
	int j;
	int num;

	env->i++;
	ft_flag_init(&env->flag);
	env->mod = pf_mod;
	j = 0;
	if (f[env->i] >= '0' && f[env->i] <= '9')
	{
		num = ft_atoi(f + env->i);
		while (f[env->i + j] >= '0' && f[env->i + j] <= '9')
			j++;
		if (f[env->i + j] == '$')
		{
			env->flag.dr = 1;
			env->flag.pos = num;
			env->i += j + 1;
		}
	}
	ft_convert_flag(f, env);
	ft_convert_spec(f, env);
}
