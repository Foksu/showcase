/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:04:46 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/01 19:04:47 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	get_signed(t_format *f)
{
	ssize_t	res;

	(f->fl.j && (res = va_arg(f->ap, intmax_t)) | 1)
	|| (f->fl.z && (res = va_arg(f->ap, ssize_t)) | 1)
	|| (f->fl.ll && (res = va_arg(f->ap, long long)) | 1)
	|| (f->fl.l && (res = va_arg(f->ap, long)) | 1)
	|| (f->fl.hh && (res = (char)va_arg(f->ap, int)) | 1)
	|| (f->fl.h && (res = (short)va_arg(f->ap, int)) | 1)
	|| (res = va_arg(f->ap, int));
	(res < 0) && (f->fl.neg_value = TRUE);
	return ((res < 0) ? -res : res);
}

static size_t	get_unsigned(t_format *f)
{
	size_t	res;

	(f->fl.j && (res = va_arg(f->ap, uintmax_t)) | 1)
	|| (f->fl.z && (res = va_arg(f->ap, size_t)) | 1)
	|| (f->fl.ll && (res = va_arg(f->ap, unsigned long long)) | 1)
	|| (f->fl.l && (res = va_arg(f->ap, unsigned long)) | 1)
	|| (f->fl.hh && (res = (unsigned char)va_arg(f->ap, t_uint)) | 1)
	|| (f->fl.h && (res = (unsigned short)va_arg(f->ap, t_uint)) | 1)
	|| (res = va_arg(f->ap, t_uint));
	return (res);
}

t_bool			check_conv(const char *str, t_format *f)
{
	int st;

	st = 0;
	(*str == 'X') ? f->fl.conv = 'X' :
	(f->fl.conv = ft_tolower(*str)) &&
	ft_isupper_alpha(*str) && (f->fl.l = TRUE);
	(f->fl.conv == 'p') && (f->fl.hash = TRUE)
	&& (f->fl.z = TRUE);
	if (f->fl.conv == 'd' || f->fl.conv == 'i')
		handle_decimal(get_signed(f), f);
	else if (f->fl.conv == 'o' || f->fl.conv == 'u'
	|| ft_tolower(f->fl.conv) == 'x' || f->fl.conv == 'p')
		handle_decimal(get_unsigned(f), f);
	else if (f->fl.conv == 'c')
		handle_c(f) && (st = 1);
	else if (f->fl.conv == 's')
		handle_s(f) && (st = 1);
	else if (f->fl.conv == 'f')
		handle_f(f);
	else
		handle_char(*str, f);
	return (st);
}
