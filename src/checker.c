/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:26:18 by bchanaa           #+#    #+#             */
/*   Updated: 2024/01/30 18:47:16 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *lst)
{
	t_list	*curr;
	int		*content;

	curr = lst;
	while (curr)
	{
		content = curr->content;
		if (!curr->next)
			break ;
		if (*content > *((int *)curr->next->content))
			return (false);
		curr = curr->next;
	}
	return (true);
}

int	handle_op(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(op, "pa\n", ft_strlen(op)))
		pa(stack_a, stack_b, SILENT);
	else if (!ft_strncmp(op, "pb\n", ft_strlen(op)))
		pb(stack_a, stack_b, SILENT);
	else if (!ft_strncmp(op, "sa\n", ft_strlen(op)))
		sa(stack_a, SILENT);
	else if (!ft_strncmp(op, "sb\n", ft_strlen(op)))
		sb(stack_b, SILENT);
	else if (!ft_strncmp(op, "ra\n", ft_strlen(op)))
		ra(stack_a, SILENT);
	else if (!ft_strncmp(op, "rb\n", ft_strlen(op)))
		rb(stack_b, SILENT);
	else if (!ft_strncmp(op, "rra\n", ft_strlen(op)))
		rra(stack_a, SILENT);
	else if (!ft_strncmp(op, "rrb\n", ft_strlen(op)))
		rrb(stack_b, SILENT);
	else
		return (0);
	return (1);
}

int	checker(t_list **stack_a)
{
	char	*operation;
	t_list	*stack_b;

	stack_b = NULL;
	operation = get_next_line(0);
	while (operation)
	{
		if (!handle_op(operation, stack_a, &stack_b))
			return (free(operation), ft_lstclear(&stack_b, free), KO);
		free(operation);
		operation = get_next_line(0);
	}
	if (!is_sorted(*stack_a) || stack_b)
		return (KO);
	return (OK);
}

int	main(int ac, char *av[])
{
	t_list	*lst;

	if (ac == 1)
		return (1);
	lst = args_to_list(ac - 1, av + 1);
	if (!lst)
		return (ft_putendl_fd("Error", 2), 1);
	lst = parse_list(&lst);
	if (!lst)
		return (ft_putendl_fd("Error", 2), 1);
	if (checker(&lst) == OK)
		ft_putendl_fd("OK", 1);
	else
	{
		ft_lstclear(&lst, free);
		ft_putendl_fd("KO", 1);
	}
	ft_lstclear(&lst, free);
	return (0);
}
