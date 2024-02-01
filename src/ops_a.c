/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:33:35 by bchanaa           #+#    #+#             */
/*   Updated: 2024/01/30 18:01:43 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int mode)
{
	swap(stack_a);
	if (mode == VERBOSE)
		ft_putendl_fd("sa", 1);
}

void	ra(t_list **stack_a, int mode)
{
	rotate(stack_a);
	if (mode == VERBOSE)
		ft_putendl_fd("ra", 1);
}

void	rra(t_list **stack_a, int mode)
{
	reverse_rotate(stack_a);
	if (mode == VERBOSE)
		ft_putendl_fd("rra", 1);
}

void	pa(t_list **stack_a, t_list **stack_b, int mode)
{
	push(stack_a, pop(stack_b));
	if (mode == VERBOSE)
		ft_putendl_fd("pa", 1);
}
