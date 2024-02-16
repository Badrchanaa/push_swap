/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:06:36 by bchanaa           #+#    #+#             */
/*   Updated: 2024/02/16 21:17:22 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*parse_content(void	*content)
{
	int		*new_content;
	int		sign;
	char	*str;

	str = (char *)content;
	sign = 1;
	if (!valid_content(str))
		return (NULL);
	while (*str == 32)
		str++;
	if (*str == '+' || *str == '-')
		sign = 44 - (str++)[0];
	new_content = malloc(sizeof(int));
	if (!new_content)
		return (NULL);
	*new_content = ft_atoi(str) * sign;
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
		if (!content || is_duplicate(new_lst, *content, i))
			return (ft_lstclear(&new_lst, free), NULL);
		curr = curr->next;
		i++;
	}
	return (new_lst);
}

int	append_argument(t_list **lst, char *arg)
{
	char	**arr;
	int		i;
	t_list	*arg_node;

	i = 0;
	arr = ft_split(arg, ' ');
	if (!arr || !*arr)
		return (free(arr), 1);
	while (arr[i])
	{
		arg_node = ft_lstnew(arr[i]);
		if (!arg_node)
			return (ft_free_split(arr), 1);
		ft_lstadd_back(lst, arg_node);
		i++;
	}
	free(arr);
	return (0);
}

t_list	*args_to_list(int ac, char *av[])
{
	t_list	*head;
	int		i;

	i = 0;
	head = NULL;
	while (i < ac)
	{
		if (append_argument(&head, av[i]) != 0)
			return (ft_lstclear(&head, free), NULL);
		i++;
	}
	return (head);
}
