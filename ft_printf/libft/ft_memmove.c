/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:32:59 by vvaltone          #+#    #+#             */
/*   Updated: 2019/10/26 14:09:28 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_static(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*udst;
	unsigned char	*usrc;

	i = 0;
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		udst[i] = usrc[i];
		i += 1;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*udst;
	unsigned char	*usrc;

	i = -1;
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (usrc < udst)
		while (len-- > 0)
			udst[len] = usrc[len];
	else
		ft_memcpy_static(udst, usrc, len);
	return (udst);
}
