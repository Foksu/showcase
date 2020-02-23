/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:21:36 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/29 13:21:37 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_stack
{
	int				val;
	int				i;
	int				sort;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*max_sort;
	int				swap_mode;
	int				flag_c;
	int				flag_v;
	int				size_a;
	int				size_b;
	int				opt_a;
	int				opt_b;
	int				opt_place;
	int				tmp_a;
	int				tmp_b;
	int				tmp_place;
}					t_stacks;

int					ps_is_integer(int val_i, char *val_c);
int					ps_check_duplicate(t_stack *st, int val);
int					ps_is_sorted(t_stacks *stacks);
int					ps_free_stacks(t_stacks **stacks, int ret_val);
int					ps_stack_size(t_stack *st);
int					ps_moves_to_top(int st_len, int value);
int					ps_get_node_place(t_stack *st, int value);
int					ps_min_max(int a, int b, int place_b);
int					ps_execute_s(t_stack **stack);
int					ps_execute_r(t_stack **stack);
int					ps_execute_rr(t_stack **stack);
int					ps_execute_p(t_stack **from, t_stack **to);
int					ps_tmp_count(t_stacks *stacks, t_stack *tmp_b);
t_stack				*ps_pop_front(t_stack **stack);
t_stack				*ps_pop_back(t_stack **stack);
t_stack				*ps_push_back_valid(t_stack **stack, int val);
t_stack				*ps_get_max_sort(t_stack *st);
t_stack				*ps_create_new_node(int val);
t_stack				*ps_get_last_node(t_stack *st);
t_stacks			*ps_create_stacks(int ac, char **av);
void				ps_setup(t_stacks *stacks);
void				ps_node_b_to_a(t_stacks *stacks);
void				ps_rotate_order(t_stacks *stacks);
void				ps_set_index(t_stack *st);
void				ps_print_stack(t_stacks *stacks);
void				ps_error(t_stacks **stacks, int ret_val);
void				ps_push_a(t_stacks *stacks);
void				ps_push_b(t_stacks *stacks);
void				ps_push_front(t_stack **stack, t_stack *new);
void				ps_push_back(t_stack **stack, t_stack *new);
void				ps_do(char *cmd, int count, t_stacks *stacks);
void				ps_set_optimal(t_stacks *stacks);

#endif
