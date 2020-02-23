/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:05:22 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/01 19:05:24 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_f(char *floating, long double fl,
t_format *f)
{
	char		*x;
	int			i;
	int			fprec;

	fl < 0 && f->fl.zero && handle_buff('-', f);
	while (!f->fl.minus && f->fl.prec_dot && --f->fl.min_width -
	((fl < 0) ? 1 : 0) > f->fl.prec + int_size(ft_abs((int)fl)))
		(f->fl.zero) ? handle_buff('0', f) : handle_buff(' ', f);
	x = ft_itoa(ft_abs(fl));
	f->fl.space && !f->fl.plus && (fl > 0) && handle_buff(' ', f);
	fl < 0 && !f->fl.zero && handle_buff('-', f);
	f->fl.plus && (fl > 0) && handle_buff('+', f);
	i = 0;
	while (x[i] >= '0' && x[i] <= '9')
	{
		handle_buff(x[i++], f);
	}
	(*floating) && f->fl.prec > 0 && handle_buff('.', f);
	i = 0;
	fprec = f->fl.prec;
	while (floating[i] >= '0' && floating[i] <= '9' && fprec--)
	{
		handle_buff(floating[i++], f);
	}
}

t_bool		ft_allnines(char *x)
{
	while (*x)
		if ((*x++) != '9')
			return (FALSE);
	return (TRUE);
}

void		format_float(long double fl_p, long double fl, char *x, t_format *f)
{
	int	i;

	i = -1;
	while (++i < (f->fl.prec))
	{
		x[i] = fl_p * 10 + '0';
		fl_p = (fl_p * 10) - (x[i] - '0');
	}
	if (fl_p * 10 + '0' >= '5')
	{
		while (x[--i] == '9')
		{
			if (ft_allnines(x))
				fl = (fl < 0 ? fl - 1 : fl + 1);
			x[i] = '0';
		}
		x[i] += 1;
	}
	print_f(x, fl, f);
	while (f->fl.minus && --f->fl.min_width - ((fl < 0) ? 1 : 0)
	> f->fl.prec + int_size(ft_abs((int)fl)))
		(f->fl.zero) ? handle_buff('0', f) : handle_buff(' ', f);
}

double		ft_pf_abs(double n)
{
	return (n < 0 ? -n : n);
}

void		handle_f(t_format *f)
{
	char		*x;
	ssize_t		int_p;
	long double fl;
	long double fl_p;
	char		*str;

	fl = (f->fl.lll) ? va_arg(f->ap, long double) : va_arg(f->ap, double);
	if (fl != fl && (str = "nan"))
		while (*str)
			handle_buff(*str++, f);
	else if (fl * 2 == fl && fl != 0 && (str = "inf"))
		while (*str)
			handle_buff(*str++, f);
	else
	{
		int_p = fl;
		fl_p = ft_abs(fl - int_p);
		!f->fl.prec && !f->fl.prec_dot && (f->fl.prec = 6);
		if (!(x = (char *)malloc(sizeof(char) * f->fl.prec)))
			return ;
		format_float(fl_p, fl, x, f);
	}
}
