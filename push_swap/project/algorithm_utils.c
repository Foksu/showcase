/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:22:22 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/29 13:22:23 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			ps_moves_to_top(int st_len, int value)
{
	if (st_len / 2 >= value)
		return (value);
	else
		return ((st_len - value) * -1);
}

int			ps_get_node_place(t_stack *st, int value)
{
	t_stack *optim;
	int		last_min;

	optim = NULL;
	last_min = 0;
	while (st)
	{
		if ((last_min == 0) || (last_min < 0 && st->val - value < 0 &&
			st->val - value > last_min) ||
			(last_min > 0 && st->val - value < last_min))
		{
			last_min = st->val - value;
			optim = st;
		}
		if (st->next == NULL)
			break ;
		st = st->next;
	}
	if (optim == st && last_min < 0)
		return (-1);
	return (last_min < 0 ? optim->i + 1 : optim->i);
}

int			ps_min_max(int a, int b, int place_b)
{
	if (a > 0 && b > 0 && place_b != -1)
		return (a > b ? a : b);
	if (a < 0 && b < 0 && place_b != -1)
		return (ft_abs(a) > ft_abs(b) ? ft_abs(a) : ft_abs(b));
	else
		return (ft_abs(a) + ft_abs(b));
}

int			ps_stack_size(t_stack *st)
{
	int count;

	count = 0;
	while (st)
	{
		st = st->next;
		count++;
	}
	return (count);
}

t_stack		*ps_get_max_sort(t_stack *st)
{
	t_stack	*tmp;
	t_stack *first;
	t_stack *max;
	int		size;
	int		i;

	first = st;
	max = st;
	size = ps_stack_size(st);
	while (st)
	{
		tmp = st;
		i = 0;
		while (i < size)
		{
			if ((tmp->next == NULL ? first : tmp->next)->val < tmp->val)
				break ;
			st->sort++;
			i++;
			tmp = tmp->next == NULL ? first : tmp->next;
		}
		max = st->sort >= max->sort ? st : max;
		st = st->next;
	}
	return (max);
}
