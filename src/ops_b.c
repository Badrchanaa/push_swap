/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:12:06 by bchanaa           #+#    #+#             */
/*   Updated: 2024/01/30 18:04:58 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **stack_b, int mode)
{
	swap(stack_b);
	if (mode == VERBOSE)
		ft_putendl_fd("sb", 1);
}

void	rb(t_list **stack_b, int mode)
{
	rotate(stack_b);
	if (mode == VERBOSE)
		ft_putendl_fd("rb", 1);
}

void	rrb(t_list **stack_b, int mode)
{
	reverse_rotate(stack_b);
	if (mode == VERBOSE)
		ft_putendl_fd("rra", 1);
}

void	pb(t_list **stack_a, t_list **stack_b, int mode)
{
	push(stack_b, pop(stack_a));
	if (mode == VERBOSE)
		ft_putendl_fd("pb", 1);
}
