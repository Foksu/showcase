/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:51:38 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/05 16:58:25 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define EOC 		"\033[0m"

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"

# define B_BLACK	"\033[1;30m"
# define B_RED		"\033[1;31m"
# define B_GREEN	"\033[1;32m"
# define B_YELLOW	"\033[1;33m"
# define B_BLUE		"\033[1;34m"
# define B_PURLE	"\033[1;35m"
# define B_CYAN		"\033[1;36m"
# define B_WHITE	"\033[1;37m"

# define U_BLACK	"\033[4;30m"
# define U_RED		"\033[4;31m"
# define U_GREEN	"\033[4;32m"
# define U_YELLOW	"\033[4;33m"
# define U_BLUE		"\033[4;34m"
# define U_PURLE	"\033[4;35m"
# define U_CYAN		"\033[4;36m"
# define U_WHITE	"\033[4;37m"

# define ON_BLACK	"\033[40m"
# define ON_RED		"\033[41m"
# define ON_GREEN	"\033[42m"
# define ON_YELLOW	"\033[43m"
# define ON_BLUE	"\033[44m"
# define ON_PURLE	"\033[45m"
# define ON_CYAN	"\033[46m"
# define ON_WHITE	"\033[47m"

# define SMILEY		"\u263A"

# define PF_BUFF_SIZE 1024
# define TRUE 1
# define FALSE 0

typedef int		t_bool;

typedef unsigned	t_uint;

typedef struct	s_flags
{
	t_bool		zero;
	t_bool		hash;
	t_bool		space;
	t_bool		plus;
	t_bool		minus;
	t_bool		l;
	t_bool		h;
	t_bool		j;
	t_bool		z;
	t_bool		lll;
	t_bool		ll;
	t_bool		hh;

	char		conv;
	int			min_width;
	int			prec;
	t_bool		prec_dot;
	t_bool		neg_value;

}				t_flags;

typedef struct	s_format
{
	t_flags		fl;
	va_list		ap;
	int			sum;
	char		*buff;

}				t_format;

double			ft_pf_abs(double n);
int				ft_printf(const char *format, ...);
int				int_size(size_t n);
int				handle_c(t_format *f);
int				handle_s(t_format *f);
int				handle_char(int chr, t_format *f);
void			handle_f(t_format *f);
void			handle_decimal(size_t num, t_format *f);
t_bool			check_conv(const char *str, t_format *f);
t_bool			handle_buff(int c, t_format *f);
t_bool			ft_allnines(char *x);
t_bool			ft_isupper_alpha(int a);
char			*print_base(size_t num, const int base, t_format *f);

#endif
