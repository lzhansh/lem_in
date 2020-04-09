/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:48:13 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:42:02 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_print_e_num(long double ld, int p)
{
	int sign;
	int i;

	sign = (ld < 0 ? -1 : 1);
	ld = ld * sign;
	while (ld < 1)
		ld *= 10;
	while (ld >= 10)
		ld /= 10;
	i = 0;
	while (i++ < p)
		ld *= 10;
	ld += 0.5;
	ld *= sign;
	return ((long)ld);
}

void	ft_print_e_exp(long double ld, char t, char **let)
{
	int		e;
	char	*part1;
	char	*part2;

	ld < 0 ? ld *= -1 : 0;
	e = 0;
	while (ld >= 10)
	{
		ld /= 10;
		e++;
	}
	while (ld < 1)
	{
		ld *= 10;
		e--;
	}
	if (e > 9 || e < -9)
		part1 = ft_strjoin(t == 'e' ? "e" : "E", e < 0 ? "-" : "+");
	else
		part1 = ft_strjoin(t == 'e' ? "e" : "E", e < 0 ? "-0" : "+0");
	part2 = ft_itoa(e < 0 ? e * -1 : e);
	*let = ft_strjoin(part1, part2);
	free(part1);
	free(part2);
}

/*
** '#' flag forces the written output to contain a decimal point even
** if no more digits follow.
*/

char	*ft_print_efg_str(char *str1, int pnt, int end, int hash)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = 0;
	tmp = ft_strnew(ft_strlen(str1) + 1);
	while (str1[++i])
	{
		tmp[j++] = str1[i];
		if ((i == pnt - 1 && end > 0) || hash == 1)
		{
			tmp[j++] = '.';
			hash = 0;
		}
		if (i >= end)
		{
			tmp[j] = '\0';
			break ;
		}
	}
	return (tmp);
}

/*
** Precision: number of digits to be printed after the decimal point
** (by default, this is 6). If the number is not 0, convert it to 0<num<9
** int ft_print_e_num.
*/

void	ft_print_e_prec(t_list *env, long double ld, char t)
{
	int		p;
	long	num;
	char	*ltr;
	char	*part1;
	char	*tmp;

	p = (env->flag.prec >= 0 ? env->flag.prec : 6);
	num = (ld == 0 ? 0 : ft_print_e_num(ld, p));
	part1 = (ld == 0 ? ft_strdup("000000") : ft_ftoa(num));
	ld == 0 ? ltr = ft_strjoin(&t, "+00") : ft_print_e_exp(ld, t, &ltr);
	tmp = (ld < 0 ? ft_print_efg_str(part1, 2, p + 1, env->flag.hash) :
	ft_print_efg_str(part1, 1, p, env->flag.hash));
	env->out = ft_strjoin(tmp, ltr);
	free(part1);
	free(tmp);
	free(ltr);
}

void	ft_print_e(t_list *env, long double ld, char t)
{
	ft_print_e_prec(env, ld, t);
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
