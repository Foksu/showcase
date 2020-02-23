/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:48:24 by vvaltone          #+#    #+#             */
/*   Updated: 2019/10/26 14:14:24 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strncpy_static(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i += 1;
	}
	return (dst);
}

static char			*ft_strnew_static(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

static size_t		ft_strlen_static(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

static int			ft_iswhitespace_static(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
	|| c == '\r');
}

char				*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && ft_iswhitespace_static(s[i]))
		i += 1;
	j = ft_strlen_static(&s[i]) - 1;
	while (s[i] && ft_iswhitespace_static(s[j + i]))
		j -= 1;
	if (!(str = ft_strnew_static(j + 1)))
		return (NULL);
	ft_strncpy_static(str, (s + i), (j + 1));
	return (str);
}
