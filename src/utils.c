/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:16:18 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/24 00:27:14 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * checks if list is sorted. (asc or desc depending on the sort_mode argument)
 * if size is positive will check only the first n elements where n = size.
*/
bool	is_sorted(t_list *lst, int size, int sort_mode)
{
	t_list	*curr;
	int		*content;
	int		i;

	curr = lst;
	i = 0;
	while ((size < 0 && curr) || (size > 0 && size - i > 0))
	{
		content = curr->content;
		if (!curr->next)
			break ;
		if (sort_mode == ASC && *content > *((int *)curr->next->content))
			return (false);
		else if (sort_mode == DESC && *content < *((int *)curr->next->content))
			return (false);
		curr = curr->next;
	}
	return (true);
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	ft_printf("freeing split\n");
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

bool	is_duplicate(t_list *lst, int num, int num_index)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = lst;
	while (curr)
	{
		if (num == *((int *)curr->content) && i != num_index)
			return (true);
		curr = curr->next;
		i++;
	}
	return (false);
}

void	print_list(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	while (curr)
	{
		ft_printf("%d -> ", *((int *)curr->content));
		curr = curr->next;
	}
	ft_printf("NULL \n");
}

bool	valid_content(char *str)
{
	int	i;
	int	sign;

	while (*str == 32)
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	if (*str == 0)
		return (false);
	i = 0;
	while (*str == '0')
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (false);
	}
	if (ft_strlen(str) != 10)
		return (ft_strlen(str) < 10);
	if (sign == -1 && ft_strncmp(str, "2147483648", 10) > 0)
		return (false);
	return (sign == -1 || ft_strncmp(str, "2147483647", 10) <= 0);
}
