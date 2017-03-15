/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_diese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:01:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/15 10:58:28 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_x_diese(char **argcvd, t_datas *datas, t_flags *flags)
{
	char	*tmp;

	if (flags->diese == 0)
		return (0);
	flags->precision -= 2;
	if (!(tmp = ft_strnew(ft_strlen(*argcvd) + 2)))
		return (-1);
	tmp[0] = '0';
	tmp[1] = 'x';
	tmp = ft_strcat(tmp, *argcvd);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
