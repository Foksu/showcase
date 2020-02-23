/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:46:52 by vvaltone          #+#    #+#             */
/*   Updated: 2019/10/26 14:13:32 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strlen_static(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

char				*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;

	i = ft_strlen_static(s);
	j = 0;
	while (i >= j)
		if (s[i - j++] == c)
			return ((char *)&s[i - (j - 1)]);
	return (NULL);
}
