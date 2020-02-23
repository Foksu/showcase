/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:21:56 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/29 13:21:57 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ps_push_b(t_stacks *stacks)
{
	t_stack *st_a;

	st_a = stacks->a;
	while (st_a && st_a->i != stacks->max_sort->i)
	{
		st_a = st_a->next;
		ps_do("pb", 1, stacks);
	}
	ps_push_a(stacks);
}

void	ps_node_b_to_a(t_stacks *stacks)
{
	stacks->tmp_b = ft_abs(stacks->opt_b);
	stacks->tmp_a = ft_abs(stacks->opt_a);
	while (((stacks->opt_b > 0 && stacks->opt_a > 0) ||
	(stacks->opt_b < 0 && stacks->opt_a < 0)) &&
	stacks->tmp_b && stacks->tmp_a && stacks->opt_place != -1)
	{
		ps_do(stacks->opt_b > 0 ? "rr" : "rrr", 1, stacks);
		stacks->tmp_b--;
		stacks->tmp_a--;
	}
	ps_do(stacks->opt_b > 0 ? "rb" : "rrb", stacks->tmp_b, stacks);
	if (stacks->opt_place != -1)
		ps_do(stacks->opt_a > 0 ? "ra" :
		"rra", stacks->tmp_a, stacks);
	ps_do("pa", 1, stacks);
	if (stacks->opt_place == -1)
		ps_do("ra", 1, stacks);
}

void	ps_push_a(t_stacks *stacks)
{
	t_stack *tmp_b;
	int		min_cmds;
	int		cmds;

	while (stacks->b)
	{
		tmp_b = stacks->b;
		ps_set_index(stacks->a);
		ps_set_index(stacks->b);
		stacks->size_a = ps_stack_size(stacks->a);
		stacks->size_b = ps_stack_size(stacks->b);
		min_cmds = ps_tmp_count(stacks, tmp_b);
		ps_set_optimal(stacks);
		while (tmp_b)
		{
			cmds = ps_tmp_count(stacks, tmp_b);
			if (min_cmds > cmds)
			{
				min_cmds = cmds;
				ps_set_optimal(stacks);
			}
			tmp_b = tmp_b->next;
		}
		ps_node_b_to_a(stacks);
	}
}

void	ps_rotate_order(t_stacks *stacks)
{
	t_stack	*tmp_a;
	t_stack	*min_node;
	int		moves_to_top;

	tmp_a = stacks->a;
	min_node = tmp_a;
	while (tmp_a)
	{
		min_node = tmp_a->val < min_node->val ? tmp_a : min_node;
		tmp_a = tmp_a->next;
	}
	stacks->size_a = ps_stack_size(stacks->a);
	ps_set_index(stacks->a);
	moves_to_top = ps_moves_to_top(stacks->size_a, min_node->i);
	ps_do(moves_to_top > 0 ? "ra" : "rra", moves_to_top, stacks);
}

void	ps_setup(t_stacks *stacks)
{
	int cmd;

	ps_set_index(stacks->a);
	stacks->max_sort = ps_get_max_sort(stacks->a);
	stacks->size_a = ps_stack_size(stacks->a);
	cmd = stacks->size_a - stacks->max_sort->i - stacks->max_sort->sort > 0 ?
		stacks->size_a - (stacks->size_a -
		stacks->max_sort->i - stacks->max_sort->sort) :
		ft_abs(stacks->size_a - stacks->max_sort->i - stacks->max_sort->sort);
	cmd = ps_moves_to_top(stacks->size_a, cmd);
	ps_do(cmd > 0 ? "ra" : "rra", cmd, stacks);
}
