/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:29:58 by bchanaa           #+#    #+#             */
/*   Updated: 2024/01/30 18:55:46 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_content(t_list *node)
{
	return (*(int *)node->content);
}

int	sort(t_list	**stack_a, t_list **stack_b)
{
	t_list	*curr;

	curr = *stack_a;
	while (curr && curr->next)
	{
		if (get_content(curr) > get_content(curr->next))
			sa(stack_a, VERBOSE);
		pb(stack_a, stack_b, VERBOSE);
		curr = curr->next;
	}
	curr = *stack_b;
	while (curr && curr->next)
	{
		if (get_content(curr) < get_content(curr->next))
			sb(stack_b, VERBOSE);
		else
			pa(stack_a, stack_b, VERBOSE);
		curr = curr->next;
	}
	if (curr)
		pa(stack_a, stack_b, VERBOSE);
	return (0);
}
