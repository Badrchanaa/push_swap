#include "push_swap.h"

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
	ft_lstclear(&lst, free);
	return (0);
}
