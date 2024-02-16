/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:54:00 by bchanaa           #+#    #+#             */
/*   Updated: 2024/02/01 12:54:35 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>

# define OK 0
# define KO 1
# define VERBOSE 0
# define SILENT 1

void	ft_free_split(char **ar);
bool	is_duplicate(t_list *lst, int num, int num_index);
void	print_list(t_list *lst);
bool	valid_content(char *str);

t_list	*args_to_list(int ac, char *av[]);
void	push_swap(t_list **lst);
t_list	*parse_list(t_list **lst);

t_list	*pop(t_list **stack);
void	swap(t_list **stack);
void	push(t_list **stack, t_list *node);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

void	sa(t_list **stack_a, int mode);
void	sb(t_list **stack_b, int mode);
void	ra(t_list **stack_a, int mode);
void	rb(t_list **stack_b, int mode);
void	pb(t_list **stack_a, t_list **stack_b, int mode);
void	pa(t_list **stack_a, t_list **stack_b, int mode);
void	rra(t_list **stack_a, int mode);
void	rrb(t_list **stack_b, int mode);

int		sort(t_list **stack_a, t_list **stack_b);

#endif
