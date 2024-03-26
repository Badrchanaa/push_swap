/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:38:21 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/26 01:22:12 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_content(t_list *node)
{
	return (*((int *)node->content));
}

int	get_list_max(t_list *stack, int limit)
{
	t_list	*curr;
	int		max;
	int		max_pos;
	int		i;

	max = INT_MIN;
	max_pos = -1;
	i = 0;
	curr = stack;
	while (curr)
	{
		if (get_content(curr) >= max && get_content(curr) <= limit)
		{
			max = get_content(curr);
			max_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_pos);
}

int	get_list_min(t_list *stack, int limit)
{
	t_list	*curr;
	int		min;
	int		pos;
	int		i;

	min = INT_MAX;
	pos = -1;
	curr = stack;
	i = 0;
	while (curr)
	{
		if (get_content(curr) <= min && get_content(curr) >= limit)
		{
			min = get_content(curr);
			pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos);
}

int	get_sorted_position(t_list *stack, int num, int sort_mode)
{
	int	pos;

	if (sort_mode == DESC)
	{
		pos = get_list_max(stack, num);
		if (pos < 0)
			return (get_list_max(stack, INT_MAX));
		return (pos);
	}
	pos = get_list_min(stack, num);
	if (pos < 0)
		return (get_list_min(stack, INT_MIN));
	return (pos);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
