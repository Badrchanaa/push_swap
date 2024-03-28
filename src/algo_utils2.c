/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:01:27 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/28 01:25:22 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	c_rr(int size, int pos)
{
	return ((size - pos) % size);
}

t_uint	get_min_ops(int size_a, int size_b, int pos_a, int pos_b)
{
	int	rra;
	int	rrb;
	int	min;

	rra = c_rr(size_a, pos_a);
	rrb = c_rr(size_b, pos_b);
	min = ft_max(rra, rrb);
	min = ft_min(min, ft_max(pos_a, pos_b));
	return (ft_min(min, ft_min(rra + pos_b, rrb + pos_a)));
}

void	repeat_op(t_list **stack_a, t_list **stack_b, int ca, int cb)
{
	long	ac[2];

	ac[0] = ft_abs(ca) + 1;
	ac[1] = ft_abs(cb) + 1;
	while (ft_min(--ac[0], --ac[1]) != 0 && ca * cb > 0)
	{
		if (ca > 0)
			r_all(stack_a, stack_b, VERBOSE);
		else
			rr_all(stack_a, stack_b, VERBOSE);
	}
	while (ac[0]-- > 0)
	{
		if (ca > 0)
			rx(stack_a, VERBOSE, STACK_A);
		else
			rrx(stack_a, VERBOSE, STACK_A);
	}
	while (ac[1]-- > 0)
	{
		if (cb > 0)
			rx(stack_b, VERBOSE, STACK_B);
		else
			rrx(stack_b, VERBOSE, STACK_B);
	}
}
