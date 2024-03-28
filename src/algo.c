/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:44:45 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/28 01:17:19 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_to_top(t_list **stack_a, t_list **stack_b, t_num *num)
{
	int				size_a;
	int				size_b;
	int				pos_a;
	int				pos_b;
	int				ops[3];

	pos_a = num->pos;
	pos_b = num->nb_pos;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	ops[0] = ft_max(pos_a, pos_b);
	ops[1] = ft_max(c_rr(size_a, pos_a), c_rr(size_b, pos_b));
	ops[2] = ft_min(pos_a + c_rr(size_b, pos_b), pos_b + c_rr(size_a, pos_a));
	if (ops[1] <= ops[0])
	{
		if (ops[1] <= ops[2])
			return (repeat_op(stack_a, stack_b, \
					-c_rr(size_a, pos_a), -c_rr(size_b, pos_b)), 0);
	}
	else if (ops[0] < ops[2])
		return (repeat_op(stack_a, stack_b, pos_a, pos_b), 0);
	if (pos_a + c_rr(size_b, pos_b) < pos_b + c_rr(size_a, pos_a))
		return (repeat_op(stack_a, stack_b, pos_a, -c_rr(size_b, pos_b)), 0);
	return (repeat_op(stack_a, stack_b, -c_rr(size_a, pos_a), pos_b), 0);
}

int	push_back(t_list **stack_a, t_list **stack_b, int size_a)
{
	t_list	*curr;
	int		sorted_pos;

	curr = *stack_b;
	while (curr)
	{
		sorted_pos = get_sorted_position(*stack_a, get_content(curr), ASC);
		if (sorted_pos <= size_a / 2)
			repeat_op(stack_a, stack_b, sorted_pos, 0);
		else
			repeat_op(stack_a, stack_b, -c_rr(size_a, sorted_pos), 0);
		curr = curr->next;
		px(stack_a, stack_b, VERBOSE, STACK_A);
		size_a++;
	}
	sorted_pos = get_list_min(*stack_a, INT_MIN);
	if (sorted_pos <= size_a / 2)
		repeat_op(stack_a, stack_b, sorted_pos, 0);
	else
		repeat_op(stack_a, stack_b, -c_rr(size_a, sorted_pos), 0);
	return (0);
}

int	push_best(t_list **stack_a, t_list **stack_b, int size_a, int size_b)
{
	t_list	*curr;
	t_num	optnum;
	int		i;
	int		curr_ops;
	int		nb_pos;

	i = 0;
	curr = *stack_a;
	optnum.min_ops = INT_MAX;
	while (curr)
	{
		nb_pos = get_sorted_position(*stack_b, get_content(curr), DESC);
		curr_ops = get_min_ops(size_a, size_b, i, nb_pos);
		if (curr_ops < optnum.min_ops)
		{
			optnum.pos = i;
			optnum.min_ops = curr_ops;
			optnum.nb_pos = nb_pos;
		}
		curr = curr->next;
		i++;
	}
	rotate_to_top(stack_a, stack_b, &optnum);
	return (px(stack_a, stack_b, VERBOSE, STACK_B), 0);
}

/*
 * cases:
 * 	1 2 3 (sorted) -- 0 ops
 * 	1 3 2 -- RR & S
 * 	2 3 1 -- RR
 * 	2 1 3 -- S
 * 	3 1 2 -- R
 * 	3 2 1 -- S && RR
*/

int	sort_three(t_list **stack, t_stackname sn)
{
	int		size;
	int		first;
	int		second;
	int		third;

	if (!stack || !*stack)
		return (1);
	size = ft_lstsize(*stack);
	if (size == 2 && !is_sorted(*stack, -1, ASC))
		return (sx(stack, VERBOSE, sn), 0);
	if (size != 3 || is_sorted(*stack, -1, ASC))
		return (1);
	first = get_content((*stack));
	second = get_content((*stack)->next);
	third = get_content((*stack)->next->next);
	if (third > first && third > second)
		return (sx(stack, VERBOSE, sn), 0);
	if (is_sorted(*stack, -1, DESC))
		return (sx(stack, VERBOSE, sn), rrx(stack, VERBOSE, sn), 0);
	if (first > second && first > third)
		return (rx(stack, VERBOSE, sn), 0);
	rrx(stack, VERBOSE, sn);
	if (first < third)
		sx(stack, VERBOSE, sn);
	return (0);
}

int	turk_sort(t_list **stack_a, t_list **stack_b)
{
	int		size_a;
	int		size_b;
	int		min_size;

	size_a = ft_lstsize(*stack_a);
	min_size = 3;
	if (size_a > 200)
		min_size = 50;
	if (size_a <= 3)
		return (sort_three(stack_a, STACK_A));
	px(stack_a, stack_b, VERBOSE, STACK_B);
	px(stack_a, stack_b, VERBOSE, STACK_B);
	size_a -= 2;
	size_b = 2;
	while (size_a > min_size)
	{
		push_best(stack_a, stack_b, size_a, size_b);
		size_a--;
		size_b++;
	}
	if (size_a > 3)
		size_a = push_last_elements(stack_a, stack_b, size_a);
	sort_three(stack_a, STACK_A);
	push_back(stack_a, stack_b, size_a);
	return (0);
}
