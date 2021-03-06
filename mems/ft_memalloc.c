/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:18:07 by mfranc            #+#    #+#             */
/*   Updated: 2017/11/28 17:41:57 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t n)
{
	void	*area;

	if (n < 1)
		return (NULL);
	if (!(area = malloc(n)))
		return (NULL);
	ft_bzero(area, n);
	return (area);
}
