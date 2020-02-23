/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:26:41 by vvaltone          #+#    #+#             */
/*   Updated: 2019/10/26 14:07:25 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_size(size_t n)
{
	int	size;

	size = 1;
	while ((n /= 10) > 0)
		size++;
	return (size);
}

char			*ft_itoa(size_t n)
{
	int		size;
	char	*str;

	size = count_size(n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size-- > 0)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
