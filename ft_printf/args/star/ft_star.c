/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:12:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 16:50:51 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


t_list	*ft_get_star_arg(t_datas *datas, size_t conv_index, char *buff)
{
	t_list	*star;
	int		arg;
	size_t	i;

	i = -1;
	while (buff[++i] && i < conv_index)
	{
		if (buff[i] == '*')
		{
			if (!(arg = va_arg(datas->ap, int)))
				return (NULL);
			if (!(star = ft_lstnew(&arg, sizeof(arg))))
				return (NULL);
		}
	}
	return (star);
}
