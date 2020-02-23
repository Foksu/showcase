/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:22:39 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/29 13:22:40 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ps_execute_r(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ps_push_back(stack, ps_pop_front(stack));
		return (1);
	}
	return (-1);
}

int	ps_execute_rr(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ps_push_front(stack, ps_pop_back(stack));
		return (1);
	}
	return (-1);
}

int	ps_execute_p(t_stack **from, t_stack **to)
{
	if (*from)
	{
		ps_push_front(to, ps_pop_front(from));
		return (1);
	}
	return (-1);
}

int	ps_execute_s(t_stack **stack)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->val;
		(*stack)->val = (*stack)->next->val;
		(*stack)->next->val = tmp;
		return (1);
	}
	return (-1);
}
