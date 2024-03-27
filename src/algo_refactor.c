/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_refactor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 03:33:30 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/27 03:49:06 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	push_to_b(t_list **stack_a, t_list **stack_b, t_num *num, int size_a)
{
	int	size_b;
	int	rr;
	int	r;
	int	rxrrx;

	size_b = ft_lstsize(*stack_b);
}

void	send_to_top(t_list **stack_a, t_list **stack_b, int ca, int cb)
{
	int	i;

	i = 0;
	while ((ca - i) * (cb - i) > 0)
	{
		if (ca > 0)
			r_all(stack_a, stack_b, VERBOSE);
		else
			rr_all(stack_a, stack_b, VERBOSE);
		i++;
	}
}
