/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:22:32 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/29 13:22:33 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ps_free_stack(t_stack **st)
{
	t_stack	*next;

	while (*st)
	{
		next = (*st)->next;
		free(*st);
		*st = next;
	}
}

int			ps_free_stacks(t_stacks **stacks, int ret_val)
{
	if (*stacks && (*stacks)->a)
		ps_free_stack(&(*stacks)->a);
	if (*stacks && (*stacks)->b)
		ps_free_stack(&(*stacks)->b);
	if (*stacks)
		free(*stacks);
	return (ret_val);
}

int			ps_tmp_count(t_stacks *stacks, t_stack *tmp_b)
{
	stacks->tmp_place = ps_get_node_place(stacks->a, tmp_b->val);
	stacks->tmp_b = ps_moves_to_top(stacks->size_b, tmp_b->i);
	stacks->tmp_a = ps_moves_to_top(stacks->size_a, stacks->tmp_place);
	return (ps_min_max(stacks->tmp_a,
	stacks->tmp_b, stacks->tmp_place));
}

void		ps_set_optimal(t_stacks *stacks)
{
	stacks->opt_place = stacks->tmp_place;
	stacks->opt_b = stacks->tmp_b;
	stacks->opt_a = stacks->tmp_a;
}
