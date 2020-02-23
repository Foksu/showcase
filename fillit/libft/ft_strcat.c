/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:36:54 by vvaltone          #+#    #+#             */
/*   Updated: 2019/10/26 15:23:48 by vvaltone         ###   ########.fr       */
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

char				*ft_strcat(char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen_static(s1);
	while (s2[i])
	{
		s1[len + i] = s2[i];
		i += 1;
	}
	s1[len + i] = '\0';
	return (s1);
}
