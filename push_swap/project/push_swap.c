/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:22:57 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/29 13:22:58 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int			main(int argc, char **av)
{
	t_stacks *stacks;

	stacks = ps_create_stacks(argc, av);
	if (stacks->a == NULL)
		exit(ps_free_stacks(&stacks, 0));
	stacks->swap_mode = 1;
	stacks->size_a = ps_stack_size(stacks->a);
	ps_setup(stacks);
	if (stacks->size_a == 3)
	{
		if (stacks->a->val > stacks->a->next->val &&
		stacks->a->val < stacks->a->next->next->val)
			ps_do("sa", 1, stacks);
		else if (stacks->a->val > stacks->a->next->next->val)
			ps_do("ra", 1, stacks);
	}
	else
	{
		ps_push_b(stacks);
		ps_rotate_order(stacks);
	}
	return (ps_free_stacks(&stacks, 0));
}
