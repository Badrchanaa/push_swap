/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:12:06 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/23 21:57:45 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(t_stackname stack_name, const char *op_name)
{
	ft_putstr_fd((char *)op_name, 1);
	if (stack_name == STACK_A)
		ft_putendl_fd("a", 1);
	else if (stack_name == STACK_B)
		ft_putendl_fd("b", 1);
}

void	px(t_list **stack_a, t_list **stack_b, int mode, t_stackname stack_name)
{
	if (stack_name == STACK_A)
		push(stack_a, pop(stack_b));
	else if (stack_name == STACK_B)
		push(stack_b, pop(stack_a));
	if (mode == VERBOSE)
		print_op(stack_name, PUSH);
}

void	sx(t_list **stack, int mode, t_stackname stack_name)
{
	swap(stack);
	if (mode == VERBOSE)
		print_op(stack_name, SWAP);
}

void	rx(t_list **stack, int mode, t_stackname stack_name)
{
	rotate(stack);
	if (mode == VERBOSE)
		print_op(stack_name, ROTATE);
}

void	rrx(t_list **stack, int mode, t_stackname stack_name)
{
	reverse_rotate(stack);
	if (mode == VERBOSE)
		print_op(stack_name, REVERSE_ROTATE);
}

void	rr_all(t_list **stack_a, t_list **stack_b, int mode)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (mode == VERBOSE)
		ft_putendl_fd("rrr", 1);
}

void	r_all(t_list **stack_a, t_list **stack_b, int mode)
{
	rotate(stack_a);
	rotate(stack_b);
	if (mode == VERBOSE)
		ft_putendl_fd("rr", 1);
}
