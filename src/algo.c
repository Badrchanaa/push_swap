/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:44:45 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/24 00:45:38 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Turk Algorithm:
 * 1: push 2 elements from stackA to stackB
 * 2: for each number, calculate number of operations it would take to push it from A to B.
 * 3: push the number with lowest number of ops * 4: repeat until only 3 elements are left in stack A, then sort them using sort_three()
 * 5: push back to stackA, rotate A as necessary to push num in B in its correct position.
 * done!
*/

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

int	get_sorted_position(t_list *stack, int num)
{
	int	pos;

	pos = get_list_max(stack, num);
	if (pos < 0)
		pos = get_list_max(stack, INT_MAX);
	return (pos);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

unsigned int	get_min_ops(int size_a, int size_b, int pos_a, int pos_b)
{
	int	rra;
	int	rrb;
	int	min;

	rra = size_a - pos_a + 1;
	rrb = size_b - pos_b + 1;
	min = ft_max(rra, rrb);
	min = ft_min(min, ft_max(pos_a, pos_b)); // max(ra, rb)
	return (ft_min(min, ft_max(rra + pos_b, rrb + pos_a)));
}

unsigned int	which_ops(int size_a, int size_b, int pos_a, int pos_b)
{
	int				rxrrx;
	int				r;
	int				rr;

	rr = ft_max(size_a - pos_a + 1, size_b - pos_b + 1);
	r = ft_max(pos_a, pos_b);
	rxrrx = ft_min(pos_a + size_b - pos_b + 1, pos_b + size_a - pos_a + 1);
	if (rr < r)
		if (rxrrx < rr)
			return (RXRRX);
		else
			return (RR);
	else
		if (rxrrx < r)
			return (RXRRX);
		else
			return (R);
}

void	repeat_op(t_list **stack_a, t_list **stack_b, int count_a, int count_b)
{
	int	common_ops;
	int	tmp;

	if (count_a * count_b > 0)// check if they have the same sign
		common_ops = ft_min(ft_abs(count_a), ft_abs(count_b));
	else
		common_ops = 0;
	ft_printf("count_a %d, count_b: %d common_ops: %d\n", count_a, count_b, common_ops);
	tmp = common_ops;
	while (common_ops > 0)
	{
		if (count_a > 0 || count_b > 0)
			r_all(stack_a, stack_b, VERBOSE);
		else if (count_a < 0 || count_b < 0)
			rr_all(stack_a, stack_b, VERBOSE);
		common_ops--;
	}
	count_a -= tmp;
	count_b -= tmp;
	while (count_a != 0)
	{
		if (count_a > 0)
			(count_a--, rx(stack_a, VERBOSE, STACK_A));
		else
			(count_a++, rrx(stack_a, VERBOSE, STACK_A));
	}
	while (count_b != 0)
	{
		if (count_b > 0)
			(count_b--, rx(stack_b, VERBOSE, STACK_B));
		else
			(count_b++, rrx(stack_b, VERBOSE, STACK_B));
	}
}

// TODO: Do not calculate size_a & size_b each time (Expensive)
int	push_number(t_list **stack_a, t_list **stack_b, t_num *num)
{
	unsigned int	ops_type;
	int				size_a;
	int				size_b;
	int				pos_a;
	int				pos_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	ops_type = which_ops(size_a, size_b, num->pos, num->b_neighbor);
	pos_a = num->pos;
	pos_b = num->b_neighbor;
	ft_printf("	(pos_a: %d, pos_b: %d) ", pos_a, pos_b);
	if (ops_type == R)
		(ft_printf("using R "), repeat_op(stack_a, stack_b, pos_a, pos_b));
	else if (ops_type == RR)
		(ft_printf("using RR "), repeat_op(stack_a, stack_b, pos_a - size_a - 1, pos_b - size_b - 1));
	if (ops_type == RXRRX)
	{
		if (pos_a + size_b - pos_b + 1 < pos_b + size_a - pos_a + 1) // RARRB
			(ft_printf("using RARRB "), repeat_op(stack_a, stack_b, pos_a, -pos_b));
		else
			(ft_printf("using RBRRA "), repeat_op(stack_a, stack_b, pos_a, -pos_b));
	}
	px(stack_a, stack_b, VERBOSE, STACK_B);
	ft_printf("------ STACK_B -----\n");
	print_list(*stack_b);
	return (0);
}

void	set_num(t_num *num, int value, int pos, int min_ops)
{
	num->value = value;
	num->pos = pos;
	num->min_ops = min_ops;
}

int	push_best(t_list **stack_a, t_list **stack_b, int size_a, int size_b)
{
	t_list	*curr;
	t_num	optinum;
	int		i;
	int		curr_ops;
	int		b_neighbor;

	i = 0;
	curr = *stack_a;
	// check if curr == NULL ??
	set_num(&optinum, get_content(curr), 0, INT_MAX);
	while (curr)
	{
		b_neighbor = get_sorted_position(*stack_b, get_content(curr));
		curr_ops = get_min_ops(size_a, size_b, i, b_neighbor);
		if (curr_ops < optinum.min_ops)
		{
			set_num(&optinum, get_content(curr), i, curr_ops);
			optinum.b_neighbor = b_neighbor;
		}
		curr = curr->next;
		i++;
	}
	ft_printf("---->>>> BEST is : %d (%d moves)\n", optinum.value, optinum.min_ops);
	return (push_number(stack_a, stack_b, &optinum));
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
int	sort_three(t_list **stack, t_stackname stack_name)
{
	int		size;
	int		first;
	int		second;
	int		third;

	if (!stack || !*stack)
		return (1);
	size = ft_lstsize(*stack);
	if (size == 2 && !is_sorted(*stack, -1, ASC))
		return (sx(stack, VERBOSE, stack_name), 0);
	if (size != 3 || is_sorted(*stack, -1, ASC))
		return (1);
	first = get_content((*stack));
	second = get_content((*stack)->next);
	third = get_content((*stack)->next->next);
	if (third > first && third > second)
		return (sx(stack, VERBOSE, stack_name), 0);
	if (is_sorted(*stack, -1, DESC))
		return (sx(stack, VERBOSE, stack_name), rrx(stack, VERBOSE, stack_name), 0);
	if (first > second && first > third)
		return (rx(stack, VERBOSE, stack_name), 0);
	rrx(stack, VERBOSE, stack_name);
	if (first < third)
		sx(stack, VERBOSE, stack_name);
	return (0);
}

int	turk_sort(t_list **stack_a, t_list **stack_b)
{
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = 0;
	if (size_a <= 3)
		return (ft_printf("SORTING THREE!\n"), sort_three(stack_a, STACK_A));
	px(stack_a, stack_b, VERBOSE, STACK_B);
	px(stack_a, stack_b, VERBOSE, STACK_B);
	size_a -= 2;
	while (size_a - size_b > 3)
	{
		ft_printf("size_a %d size_b %d\n\n", size_a, size_b);
		push_best(stack_a, stack_b, size_a, size_b);
		size_b++;
	}
	ft_printf("------- SORT THREE ------\n");
	ft_printf("	STACK A:");
	print_list(*stack_a);
	sort_three(stack_a, STACK_A);
	ft_printf("------ STACK_B -----\n");
	print_list(*stack_b);
	ft_printf("------ STACK_A -----\n");
	print_list(*stack_a);
	return (0);
}
