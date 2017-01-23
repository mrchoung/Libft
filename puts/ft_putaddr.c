/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:30:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/23 15:47:56 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putaddr(const void *value)
{
	unsigned long		addr;
	char				*str;

	if (!value)
		return ;
	addr = (unsigned long)value;
	str = ft_itoa(addr, 16, BASELW);
	ft_putstr("0x");
	ft_putstr(str);
	ft_strdel(&str);
}