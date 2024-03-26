/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:44:45 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/26 02:40:01 by bchanaa          ###   ########.fr       */
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

int	c_rr(int size, int pos)
{
	return ((size - pos) % size);
}

unsigned int	get_min_ops(int size_a, int size_b, int pos_a, int pos_b)
{
	int	rra;
	int	rrb;
	int	min;

	rra = c_rr(size_a, pos_a);
	rrb = c_rr(size_b, pos_b);
	min = ft_max(rra, rrb);// rra OR rrb
	min = ft_min(min, ft_max(pos_a, pos_b)); // (rra||rrb) || (ra || rb)
	return (ft_min(min, ft_min(rra + pos_b, rrb + pos_a)));// (
}

unsigned int	which_ops(int size_a, int size_b, int pos_a, int pos_b)
{
	int				rxrrx;
	int				r;
	int				rr;

	rr = ft_max(c_rr(size_a, pos_a), c_rr(size_b, pos_b));//rra || rrb
	r = ft_max(pos_a, pos_b);//RA || RB
	rxrrx = ft_min(pos_a + c_rr(size_b, pos_b), pos_b + c_rr(size_a, pos_a)); // rarrb ||  rbrra
	//ft_printf("RR: %d | R: %d | RXRRX: %d\n", rr, r, rxrrx);
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

	//ft_printf("-- REPEAT OP: count_a: %d | count_b: %d\n", count_a, count_b);
	if (count_a * count_b > 0)// check if they have the same sign
		common_ops = ft_min(ft_abs(count_a), ft_abs(count_b));
	else
		common_ops = 0;
	tmp = common_ops;
	while (common_ops > 0)
	{
		if (count_a > 0 || count_b > 0)
			r_all(stack_a, stack_b, VERBOSE);
		else if (count_a < 0 || count_b < 0)
			rr_all(stack_a, stack_b, VERBOSE);
		common_ops--;
	}
	if (count_a < 0)
		count_a += tmp;
	else
		count_a -= tmp;
	if (count_b < 0)
		count_b += tmp;
	else
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
	//ft_printf("-----------------------------------\n");
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
	//ft_printf("PUSHNUM: SIZE A: %d | SIZE B: %d | POS: %d | NEIGHB: %d\n", size_a, size_b, num->pos, num->b_neighbor);
	ops_type = which_ops(size_a, size_b, num->pos, num->b_neighbor);
	pos_a = num->pos;
	pos_b = num->b_neighbor;
	//ft_printf("	PUSH NUMBER: pos_a: %d, pos_b: %d | size_a %d size_b %d\n", pos_a, pos_b, size_a, size_b);
	if (ops_type == R)
		repeat_op(stack_a, stack_b, pos_a, pos_b);
	else if (ops_type == RR)
		repeat_op(stack_a, stack_b, -c_rr(size_a, pos_a), -c_rr(size_b, pos_b));
	if (ops_type == RXRRX)
	{
		if (pos_a + c_rr(size_b, pos_b) < pos_b + c_rr(size_a, pos_a)) // RARRB
			repeat_op(stack_a, stack_b, pos_a, -c_rr(size_b, pos_b));
		else
			repeat_op(stack_a, stack_b, -c_rr(size_a, pos_a), pos_b);
	}
	px(stack_a, stack_b, VERBOSE, STACK_B);
	return (0);
}

int	push_back(t_list **stack_a, t_list **stack_b, int size_a)
{
	t_list	*curr;
	int		sorted_pos;

	curr = *stack_b;
	while (curr)
	{
		sorted_pos = get_sorted_position(*stack_a, get_content(curr), ASC);
		if (sorted_pos < size_a / 2)
			repeat_op(stack_a, stack_b, sorted_pos, 0);
		else
			repeat_op(stack_a, stack_b, -c_rr(size_a, sorted_pos), 0);
		curr = curr->next;
		px(stack_a, stack_b, VERBOSE, STACK_A);
		size_a++;
	}
	sorted_pos = get_list_min(*stack_a, INT_MIN);
	if (sorted_pos < size_a / 2)
		repeat_op(stack_a, stack_b, sorted_pos, 0);
	else
		repeat_op(stack_a, stack_b, sorted_pos - size_a, 0);
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
		b_neighbor = get_sorted_position(*stack_b, get_content(curr), DESC);
		curr_ops = get_min_ops(size_a, size_b, i, b_neighbor);
		//ft_printf("	CURR OPS: %d\n", curr_ops);
		if (curr_ops < optinum.min_ops)
		{
			set_num(&optinum, get_content(curr), i, curr_ops);
			optinum.b_neighbor = b_neighbor;
		}
		curr = curr->next;
		i++;
	}
//	ft_printf("	BEST OPS: %d\n", optinum.min_ops);
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
	//ft_printf("---- SORT START ---\n");
	//ft_printf("--> SIZE A: %d || SIZE B: %d\n", size_a, size_b);
	if (size_a <= 3)
		return (sort_three(stack_a, STACK_A));
	px(stack_a, stack_b, VERBOSE, STACK_B);
	px(stack_a, stack_b, VERBOSE, STACK_B);
	size_a -= 2;
	size_b = 2;
	while (size_a > 3)
	{
	//	ft_printf("--> SIZE A: %d || SIZE B: %d\n", size_a, size_b);
		push_best(stack_a, stack_b, size_a, size_b);
		size_a--;
		size_b++;
	}
	int sorted_pos = get_list_max(*stack_b, INT_MAX);
	if (sorted_pos < size_b / 2)
		repeat_op(stack_a, stack_b, 0, sorted_pos);
	else
		repeat_op(stack_a, stack_b, 0, sorted_pos - size_b);
	sort_three(stack_a, STACK_A);
	//print_list(*stack_b);
	push_back(stack_a, stack_b, size_a);
	return (0);
}
