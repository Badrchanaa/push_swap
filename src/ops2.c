/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:25:10 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/28 01:29:28 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ss(t_list **stack_a, t_list **stack_b, int mode)
{
	swap(stack_a);
	swap(stack_b);
	if (mode == VERBOSE)
		ft_putendl_fd("ss", 1);
}
