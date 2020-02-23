/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:22:51 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/29 13:22:52 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ps_is_integer(int val_i, char *val_c)
{
	char	*value;
	int		res;

	res = 0;
	value = ft_itoa(val_i);
	if (ft_strcmp(value, val_c) == 0)
		res = 1;
	if (value)
		free(value);
	return (res);
}

int		ps_check_duplicate(t_stack *st, int val)
{
	while (st)
	{
		if (st->val == val)
			return (0);
		st = st->next;
	}
	return (1);
}

int		ps_is_sorted(t_stacks *stacks)
{
	t_stack	*st_a;
	int		last_val;

	if (stacks->b != NULL)
		return (0);
	st_a = stacks->a;
	last_val = st_a->val;
	while (st_a)
	{
		if (last_val > st_a->val)
			return (0);
		last_val = st_a->val;
		st_a = st_a->next;
	}
	return (1);
}

t_stack	*ps_push_back_valid(t_stack **stack, int val)
{
	t_stack *new;

	if ((new = ps_create_new_node(val)) == NULL)
		return (NULL);
	ps_push_back(stack, new);
	return (*stack);
}

void	ps_error(t_stacks **stacks, int ret_val)
{
	write(2, "Error\n", 6);
	ps_free_stacks(stacks, ret_val);
	exit(ret_val);
}
