/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:16:18 by bchanaa           #+#    #+#             */
/*   Updated: 2024/01/26 23:57:42 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_list *lst, int num, int index)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = lst;
	while (curr)
	{
		if (num == *((int *)curr->content) && i != index)
			return (i);
		curr = curr->next;
		i++;
	}
	return (-1);
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
	while (*str == 32)
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == 0)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

void	*parse_content(void	*content)
{
	long	num;
	int		*new_content;
	int		sign;
	int		i;
	char	*str;

	str = (char *)content;
	sign = 1;
	i = 0;
	if (!valid_content(str))
		return (NULL);
	while (*str == 32)
		str++;
	if  (*str == '+' || *str == '-')
		sign = 44 - (str++)[0];
	new_content = malloc(sizeof(int));
	if (!new_content)
		return (NULL);
	num = ft_atoi(str);
	if (num > ((long)INT_MAX + 1))
		return (NULL);
	*new_content = num * sign;
	return (new_content);
}

t_list	*parse_list(t_list **lst)
{
	t_list	*new_lst;
	t_list	*curr;
	int		*content;
	int		i;

	i = 0;
	new_lst = ft_lstmap(*lst, &parse_content, free);
	ft_lstclear(lst, free);
	curr = new_lst;
	while (curr)
	{
		content = curr->content;
		if (!content || search_list(new_lst, *content, i) != -1)
			return (ft_lstclear(&new_lst, free), NULL);
		i++;
	}
	return (new_lst);
}

