/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:46:29 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/28 00:49:50 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_content(t_list *node)
{
	return (*((int *)node->content));
}

int	get_list_max(t_list *stack, int limit)
{
	t_list	*curr;
	int		max;
	int		max_pos;
	int		i;

	max = INT_MIN;
	max_pos = -1;
	i = 0;
	curr = stack;
	while (curr)
	{
		if (get_content(curr) >= max && get_content(curr) <= limit)
		{
			max = get_content(curr);
			max_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_pos);
}

int	get_list_min(t_list *stack, int limit)
{
	t_list	*curr;
	int		min;
	int		pos;
	int		i;

	min = INT_MAX;
	pos = -1;
	curr = stack;
	i = 0;
	while (curr)
	{
		if (get_content(curr) <= min && get_content(curr) >= limit)
		{
			min = get_content(curr);
			pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos);
}

int	get_sorted_position(t_list *stack, int num, int sort_mode)
{
	int	pos;

	if (sort_mode == DESC)
	{
		pos = get_list_max(stack, num);
		if (pos < 0)
			return (get_list_max(stack, INT_MAX));
		return (pos);
	}
	pos = get_list_min(stack, num);
	if (pos < 0)
		return (get_list_min(stack, INT_MIN));
	return (pos);
}

int	push_last_elements(t_list **stack_a, t_list **stack_b, int size)
{
	int	min_pos;

	while (size > 3)
	{
		min_pos = get_list_min(*stack_a, INT_MIN);
		if (min_pos <= size / 2)
			repeat_op(stack_a, stack_b, min_pos, 0);
		else
			repeat_op(stack_a, stack_b, -c_rr(size, min_pos), 0);
		px(stack_a, stack_b, VERBOSE, STACK_B);
		size--;
	}
	return (size);
}
