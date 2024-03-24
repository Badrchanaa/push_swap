/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:26:18 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/24 00:27:13 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_op(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(op, "pa\n", ft_strlen(op)))
		px(stack_a, stack_b, SILENT, STACK_A);
	else if (!ft_strncmp(op, "pb\n", ft_strlen(op)))
		px(stack_a, stack_b, SILENT, STACK_B);
	else if (!ft_strncmp(op, "sa\n", ft_strlen(op)))
		sx(stack_a, SILENT, STACK_A);
	else if (!ft_strncmp(op, "sb\n", ft_strlen(op)))
		sx(stack_b, SILENT, STACK_B);
	else if (!ft_strncmp(op, "ra\n", ft_strlen(op)))
		rx(stack_a, SILENT, STACK_A);
	else if (!ft_strncmp(op, "rb\n", ft_strlen(op)))
		rx(stack_b, SILENT, STACK_B);
	else if (!ft_strncmp(op, "rra\n", ft_strlen(op)))
		rrx(stack_a, SILENT, STACK_A);
	else if (!ft_strncmp(op, "rrb\n", ft_strlen(op)))
		rrx(stack_b, SILENT, STACK_B);
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
	if (!is_sorted(*stack_a, -1, ASC) || stack_b)
		return (ft_lstclear(&stack_b, free), KO);
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
		ft_putendl_fd("KO", 1);
	ft_lstclear(&lst, free);
	return (0);
}
