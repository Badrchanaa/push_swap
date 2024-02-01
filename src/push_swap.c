/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:43:31 by bchanaa           #+#    #+#             */
/*   Updated: 2024/01/30 18:50:47 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// prints operations to sort the list passed as argument.
void	push_swap(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (!stack_a || !*stack_a)
		ft_printf("push_swap: list is empty!\n");
	sort(stack_a, &stack_b);
	if (stack_b)
		ft_printf("push_swap: algo not working properly!\n");
	return ;
}
