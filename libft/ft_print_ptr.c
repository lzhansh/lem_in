/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:37:31 by lzhansha          #+#    #+#             */
/*   Updated: 2019/10/22 16:42:25 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_ptr_prec(t_list *env)
{
	char	*str;
	char	*tmp;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(env->out);
	if (env->flag.prec > len)
	{
		tmp = ft_strnew(env->flag.prec - len);
		while (++i < env->flag.prec - len)
			tmp[i] = '0';
		str = ft_strjoin(tmp, env->out);
		free(env->out);
		free(tmp);
		env->out = str;
	}
	tmp = ft_strjoin("0x", env->out);
	free(env->out);
	env->out = tmp;
}

void	ft_print_ptr(t_list *env)
{
	int	len;

	if (env->flag.zero && env->flag.prec == -1)
		env->flag.prec = env->flag.width - 2;
	ft_print_ptr_prec(env);
	ft_strlower(env->out);
	len = ft_strlen(env->out);
	if (env->flag.minus)
	{
		env->ret += write(env->fd, env->out, len);
		while (env->flag.width-- > len)
			env->ret += write(env->fd, " ", 1);
	}
	else
	{
		while (env->flag.width-- > len)
			env->ret += write(env->fd, " ", 1);
		env->ret += write(env->fd, env->out, len);
	}
	env->i++;
	free(env->out);
}
