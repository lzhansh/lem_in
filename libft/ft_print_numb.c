/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:12:49 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:42:20 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_numb_prec(t_list *env, char t)
{
	int		len;
	int		i;
	char	*tmp;
	char	*new;

	len = ft_strlen(env->out);
	if (env->flag.prec == 0 && env->out[0] == '0')
		env->out[0] = '\0';
	else if (env->flag.prec > len)
	{
		if (t == 'o' && env->flag.hash)
			env->flag.prec--;
		i = env->flag.prec - len;
		tmp = ft_strnew(i);
		while (--i >= 0)
			tmp[i] = '0';
		new = ft_strjoin(tmp, env->out);
		free(tmp);
		free(env->out);
		env->out = new;
	}
}

static void	ft_print_numb_prefix(t_list *env, char t, long int num)
{
	if (env->flag.hash && env->out[0] != '\0' && num != 0)
	{
		env->ret += (t == 'o') ? write(env->fd, "0", 1) : 0;
		env->ret += (t == 'x') ? write(env->fd, "0x", 2) : 0;
		env->ret += (t == 'X') ? write(env->fd, "0X", 2) : 0;
	}
	else if (t == 'o' && env->flag.hash && env->flag.prec >= 0)
		env->ret += write(env->fd, "0", 1);
}

static void	ft_print_numb_width(t_list *env, char t)
{
	int	len;
	int	i;

	i = -1;
	len = ft_strlen(env->out);
	if (env->flag.hash && (env->out[0] != '\0' && env->out[0] != '0'))
	{
		env->flag.width -= (t == 'o' ? 1 : 0);
		env->flag.width -= ((t == 'x' || t == 'X') ? 2 : 0);
	}
	if (env->flag.prec >= 0)
	{
		while (env->flag.width > env->flag.prec + ++i &&
		env->flag.width > len + i)
			env->ret += write(env->fd, " ", 1);
		while (env->flag.width > len + i++)
			env->ret += write(env->fd, "0", 1);
	}
	else
	{
		while (env->flag.width > len + ++i)
			env->ret += (env->flag.zero ? write(env->fd, "0", 1) :
			write(env->fd, " ", 1));
	}
}

void		ft_print_numb(t_list *env, char t, long int num)
{
	ft_print_numb_prec(env, t);
	if (env->flag.zero)
	{
		ft_print_numb_prefix(env, t, num);
		ft_print_numb_width(env, t);
		env->ret += write(env->fd, env->out, ft_strlen(env->out));
	}
	else if (env->flag.minus)
	{
		ft_print_numb_prefix(env, t, num);
		env->ret += write(env->fd, env->out, ft_strlen(env->out));
		ft_print_numb_width(env, t);
	}
	else
	{
		ft_print_numb_width(env, t);
		ft_print_numb_prefix(env, t, num);
		env->ret += write(env->fd, env->out, ft_strlen(env->out));
	}
	env->i++;
	free(env->out);
}
