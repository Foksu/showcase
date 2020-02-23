/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:30:20 by vvaltone          #+#    #+#             */
/*   Updated: 2019/10/26 17:57:57 by vvaltone         ###   ########.fr       */
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

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(new->content = (void*)malloc(content_size)))
			return (NULL);
		new->content = ft_memcpy_static(new->content, content, content_size);
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}
