/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:53:03 by lzhansha          #+#    #+#             */
/*   Updated: 2020/04/25 13:28:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function checks precision of the input. But first, we need to see if
** number is negative or not. If yes, set the neg flag to 1. Then, if the prec
** flag is 0 and value is 0, printf prints null [EDGE CASE]. Then, if the prec
** flag value is more than the length of the input, fill the difference with 0s.
*/

void	ft_print_digits_neg(t_list *env)
{
	char *tmp;

	if (env->out[0] == '-')
	{
		tmp = ft_strdup(env->out + 1);
		free(env->out);
		env->out = tmp;
		env->flag.neg = 1;
		env->flag.sp = 0;
		env->flag.plus = 0;
	}
}

void	ft_print_digits_prec(t_list *env)
{
	int		len;
	int		i;
	char	*tmp;
	char	*new;

	ft_print_digits_neg(env);
	len = (int)ft_strlen(env->out);
	if (env->flag.prec == 0 && env->out[0] == '0')
		env->out[0] = '\0';
	else if (env->flag.prec > len)
	{
		i = env->flag.prec - len;
		tmp = ft_strnew(i);
		while (i-- > 0)
			tmp[i] = '0';
		new = ft_strjoin(tmp, env->out);
		free(tmp);
		free(env->out);
		env->out = new;
	}
}

void	ft_print_digits_sign(t_list *env)
{
	if (env->flag.plus || env->flag.sp)
		env->ret += (env->flag.plus == 1 ? write(env->fd, "+", 1) :
		write(env->fd, " ", 1));
	else if (env->flag.neg)
		env->ret += write(env->fd, "-", 1);
}

/*
** If the value to be printed is shorter than number, the result is padded
** with blank spaces. The value is not truncated even if the result is larger.
** If there is a precision value, it's already added in ft_print_digits_prec
** and env->out includes it.
*/

void	ft_print_digits_width(t_list *env)
{
	int	len;
	int	i;

	i = -1;
	len = ((int)ft_strlen(env->out) > env->flag.prec ?
		(int)ft_strlen(env->out) : env->flag.prec);
	(env->flag.neg || env->flag.plus || env->flag.sp) ?
		(int)env->flag.width-- : 0;
	if (env->flag.prec >= 0)
	{
		while (env->flag.width - ++i > len)
			env->ret += write(env->fd, " ", 1);
		i = -1;
		while ((int)ft_strlen(env->out) < len - ++i)
			env->ret += write(env->fd, "0", 1);
	}
	else
		while (env->flag.width - ++i > len)
			env->ret += (env->flag.zero == 1 ? write(env->fd, "0", 1) :
			write(env->fd, " ", 1));
}

/*
** First, check the precision flag. Then, check if there is activated zero flag.
** In this case, print sign, then the width. On contrary, if there is a minus
** flag, number is left justified within the given field width (right
** justification is by default).
*/

void	ft_print_digits(t_list *env)
{
	ft_print_digits_prec(env);
	if (env->flag.zero)
	{
		ft_print_digits_sign(env);
		ft_print_digits_width(env);
		env->ret += write(env->fd, env->out, ft_strlen(env->out));
	}
	else if (env->flag.minus)
	{
		ft_print_digits_sign(env);
		env->ret += write(env->fd, env->out, ft_strlen(env->out));
		ft_print_digits_width(env);
	}
	else
	{
		ft_print_digits_width(env);
		ft_print_digits_sign(env);
		env->ret += write(env->fd, env->out, ft_strlen(env->out));
	}
	(env->i)++;
	free(env->out);
}
