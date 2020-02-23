/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diouxp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:05:15 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/01 19:05:16 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_base(t_format *f)
{
	if (f->fl.conv == 'd' || f->fl.conv == 'i' || f->fl.conv == 'u')
		return (10);
	if (f->fl.conv == 'o')
		return (8);
	if (ft_tolower(f->fl.conv) == 'x' || f->fl.conv == 'p')
		return (16);
	return (1);
}

static void		print_prefix(size_t number, int base,
const char space, t_format *f)
{
	f->fl.neg_value && f->fl.min_width--;
	f->fl.space && !f->fl.plus && !f->fl.neg_value && f->fl.min_width--;
	f->fl.plus && !f->fl.neg_value && base == 10 && f->fl.min_width--;
	f->fl.hash && number && base == 8 && f->fl.min_width--;
	f->fl.hash && base == 16 && (number || f->fl.conv == 'p')
	&& (f->fl.min_width -= 2);
	if (!(!f->fl.prec_dot && f->fl.zero) && !f->fl.minus)
		while (f->fl.min_width-- > 0)
			handle_buff(space, f);
	f->fl.space && (f->fl.conv == 'd' || f->fl.conv == 'i') &&
	!f->fl.plus && !f->fl.neg_value && handle_buff(' ', f);
	f->fl.neg_value && handle_buff('-', f);
	f->fl.plus && !f->fl.neg_value && (f->fl.conv == 'd'
	|| f->fl.conv == 'i') && handle_buff('+', f);
	f->fl.hash && base == 8 && handle_buff('0', f);
	f->fl.hash && (number || f->fl.conv == 'p')
	&& base == 16 && handle_buff('0', f)
	&& handle_buff(f->fl.conv == 'X' ? 'X' : 'x', f);
	if (!f->fl.prec_dot && f->fl.zero && !f->fl.minus)
		while (f->fl.min_width-- > 0)
			handle_buff(space, f);
}

void			handle_decimal(size_t number, t_format *f)
{
	char		*num;
	int			num_len;
	t_bool		is_print;
	char		space;
	int			base;

	base = check_base(f);
	num = print_base(number, base, f);
	num_len = ft_strlen(num);
	!f->fl.prec && !number && f->fl.prec_dot && f->fl.min_width++;
	f->fl.prec -= num_len + (f->fl.hash && number && base == 8);
	f->fl.min_width -= (f->fl.prec > 0 ? f->fl.prec : 0) + num_len;
	space = (!f->fl.prec_dot && f->fl.zero) ? '0' : ' ';
	print_prefix(number, base, space, f);
	is_print = !(number == 0 &&
	((f->fl.prec_dot && f->fl.prec < 0) || (base == 8 && f->fl.hash)));
	while (f->fl.prec-- > 0)
		handle_buff('0', f);
	if (is_print)
		while (*num)
			handle_buff(*num++, f);
	while (f->fl.min_width-- > 0)
		handle_buff(' ', f);
}
