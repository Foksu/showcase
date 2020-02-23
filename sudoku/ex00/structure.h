/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:15:55 by tbergkul          #+#    #+#             */
/*   Updated: 2019/07/21 22:58:31 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <unistd.h>

# ifndef T_GRID
#  define T_GRID

typedef struct	s_grid
{
	int x;
	int y;
}				t_grid;

# endif

void			ft_putchar(char c);

void			set_point(t_grid *coord, int i, int j);

int				where_is_zero(t_grid *coord, int (*grid)[9]);

int				check_number(int(*grid)[9], int row, int col, int n);

int				solve_sudoku(int (*grid)[9]);

void			ft_print_grid(int (*grid)[9]);

int				solve_sudoku_reverse(int (*grid)[9]);

int				check_row(int (*grid)[9], int row, int n);

int				check_col(int (*grid)[9], int col, int n);

int				check_box(int (*grid)[9], int row_start, int col_start, int n);

void			ft_array_compare(int (*grid)[9], int (*reverse_grid)[9]);

int				where_is_zero(t_grid *coord, int (*grid)[9]);

#endif
