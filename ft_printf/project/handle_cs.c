/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:04:54 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/01 19:04:55 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				handle_c(t_format *f)
{
	while (--f->fl.min_width > 0 && !f->fl.minus)
		(f->fl.zero) ? handle_buff('0', f) : handle_buff(' ', f);
	handle_buff(va_arg(f->ap, int), f);
	while (f->fl.min_width-- > 0 && f->fl.minus)
		handle_buff(' ', f);
	return (0);
}

static t_bool	is_strascii(unsigned char *tmp)
{
	unsigned int i;

	i = -1;
	while (tmp[++i])
		if (!(tmp[i] >= 0 && tmp[i] <= 127))
			return (FALSE);
	return (TRUE);
}

int				handle_s(t_format *f)
{
	int				prec;
	unsigned char	*tmp;
	int				i;
	const char		*str;

	i = -1;
	str = "(null)";
	if (!(tmp = (unsigned char*)va_arg(f->ap, char *)))
		tmp = (unsigned char*)str;
	prec = (!f->fl.prec_dot || ((int)ft_strlen(tmp) < f->fl.prec))
	? ft_strlen(tmp) : f->fl.prec;
	if (!is_strascii(tmp))
		return (1);
	while (!f->fl.minus && f->fl.min_width-- - prec > 0)
		(f->fl.zero) ? handle_buff('0', f) : handle_buff(' ', f);
	(f->fl.prec == 0) ? f->fl.prec = -1 : 0;
	while (tmp[++i] && (f->fl.prec-- > 0 || !f->fl.prec_dot))
		handle_buff(tmp[i], f);
	while ((f->fl.min_width-- - (i)) > 0 && f->fl.minus)
		handle_buff(' ', f);
	return (0);
}

int				handle_char(int chr, t_format *f)
{
	if (chr == 1)
	{
		f->fl.prec = va_arg(f->ap, long long int);
		(f->fl.prec < 0) && (f->fl.prec_dot = FALSE)
		&& (f->fl.prec = 0);
	}
	else if (chr == 0)
	{
		f->fl.min_width = va_arg(f->ap, long long int);
		(f->fl.min_width < 0) && (f->fl.minus = TRUE)
		&& (f->fl.min_width *= -1);
	}
	else
	{
		while (--f->fl.min_width > 0 && !f->fl.minus)
			(f->fl.zero) ? handle_buff('0', f) : handle_buff(' ', f);
		handle_buff(chr, f);
		while (f->fl.min_width-- > 0 && f->fl.minus)
			handle_buff(' ', f);
	}
	return (1);
}
