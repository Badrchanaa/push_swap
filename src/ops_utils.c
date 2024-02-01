/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:07:31 by bchanaa           #+#    #+#             */
/*   Updated: 2024/01/29 21:33:11 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack, t_list *node)
{
	ft_lstadd_front(stack, node);
}

t_list	*pop(t_list **stack)
{
	t_list	*node;

	if (!stack)
		return (NULL);
	node = *stack;
	if (!node)
		return (NULL);
	*stack = node->next;
	node->next = NULL;
	return (node);
}

void	rotate(t_list **stack)
{
	t_list	*node;

	node = pop(stack);
	ft_lstadd_back(stack, node);
}

void	swap(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = pop(stack);
	second_node = pop(stack);
	push(stack, first_node);
	push(stack, second_node);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*curr;
	t_list	*prev;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	prev = curr;
	curr = curr->next;
	if (!curr)
		return ;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr = prev->next;
	prev->next = NULL;
	push(stack, curr);
}
