/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:19:59 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/23 20:59:19 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	print_list(lst);
	push_swap(&lst);
	print_list(lst);
	ft_lstclear(&lst, free);
	return (0);
}
