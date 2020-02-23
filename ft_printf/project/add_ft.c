/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:04:28 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/01 19:04:29 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		int_size(size_t n)
{
	size_t	size;

	size = (n == 0) ? 0 : 1;
	while ((n /= 10) > 0)
		size++;
	return (size);
}

t_bool	ft_isupper_alpha(int a)
{
	if ((a >= 65 && a <= 90))
		return (TRUE);
	else
		return (FALSE);
}

char	*swap(int j, char source[])
{
	int		i;
	char	*x;
	char	*tmp;

	i = 0;
	if (!(x = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	tmp = x;
	while (j >= 0)
		x[i++] = source[j--];
	x[i] = '\0';
	free(tmp);
	return (x);
}

char	*print_base(size_t num, const int base, t_format *f)
{
	int		i;
	size_t	mod;
	char	x[70];
	int		temp;

	i = 0;
	while (num >= (size_t)base)
	{
		mod = num;
		temp = mod % (size_t)base;
		if (temp <= 9)
			x[i] = temp + '0';
		else
			x[i] = temp + ((base == 16 && f->fl.conv == 'X') ? 55 : 87);
		num /= base;
		i++;
	}
	if (num >= 10)
		x[i] = num + ((base == 16 && f->fl.conv == 'X') ? 55 : 87);
	else
		x[i] = num + '0';
	return (swap(i, x));
}
