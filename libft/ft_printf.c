/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:04:38 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/01 19:04:39 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	print_buff(t_format *f)
{
	write(1, f->buff, f->sum);
	return (TRUE);
}

t_bool	handle_buff(int c, t_format *f)
{
	f->buff[f->sum++] = c;
	if (!(f->buff >= 0))
	{
		print_buff(f);
		free(&f->buff);
	}
	return (TRUE);
}

t_bool	handle_flags(const char **str, t_format *f)
{
	return ((**str == '0' && (f->fl.zero = TRUE))
	|| (**str == '+' && (f->fl.plus = TRUE))
	|| (**str == '-' && (f->fl.minus = TRUE))
	|| (**str == ' ' && (f->fl.space = TRUE))
	|| (**str == '#' && (f->fl.hash = TRUE))
	|| (**str == 'j' && (f->fl.j = TRUE))
	|| (**str == 'z' && (f->fl.z = TRUE))
	|| (**str == 'L' && (f->fl.lll = TRUE))
	|| ((**str == 'l') && (*str)[1] == 'l' && (f->fl.ll = TRUE) && ++(*str))
	|| (**str == 'l' && (f->fl.l = TRUE))
	|| (**str == 'h' && (*str)[1] == 'h' && (f->fl.hh = TRUE) && ++(*str))
	|| (**str == 'h' && (f->fl.h = TRUE))
	|| (**str == '*' && handle_char(0, f)));
}

int		handle_field(const char *str, t_format *f)
{
	while (*str)
		if (*str == '%' && *(++str))
		{
			while (*str)
				if (handle_flags(&str, f))
					str++;
				else if (ft_atoi(str))
					str += int_size((f->fl.min_width = ft_atoi(str)));
				else if (*str == '.' && (f->fl.prec_dot = TRUE) && ++str)
				{
					*str == '0' && ++str;
					(((*str == '*') && handle_char(1, f)) && ++str) || (str +=
					int_size((*str == '0') ? 1 : (f->fl.prec = ft_atoi(str))));
				}
				else
				{
					if (check_conv(str++, f))
						return (1);
					ft_bzero(&f->fl, sizeof(t_flags));
					break ;
				}
		}
		else
			*str != '\0' && handle_buff(*str++, f);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	static t_format		f;

	f.sum = 0;
	if (!f.buff)
		if (!(f.buff = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
	va_start(f.ap, format);
	(handle_field(format, &f)) ? (print_buff(&f))
	&& (f.sum = -1) : print_buff(&f);
	va_end(f.ap);
	return (f.sum);
}
