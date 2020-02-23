/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:43:54 by vvaltone          #+#    #+#             */
/*   Updated: 2019/10/26 14:12:32 by vvaltone         ###   ########.fr       */
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

char				*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen_static(s);
	str = (char *)malloc(sizeof(*s) * len + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(s[i]);
		i += 1;
	}
	str[i] = '\0';
	return (str);
}
