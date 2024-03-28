/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:54:00 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/28 01:34:46 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# define OK 0
# define KO 1
# define ERROR 2
# define VERBOSE 0
# define SILENT 1

# define STACK_A 2
# define STACK_B 4

# define ROTATE "r"
# define REVERSE_ROTATE "rr"
# define SWAP "s"
# define PUSH "p"

# define ASC 1
# define DESC 2

typedef unsigned char	t_stackname;
typedef unsigned int	t_uint;

typedef struct s_num
{
	int	value;
	int	pos;
	int	nb_pos;
	int	min_ops;
}			t_num;

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

void	px(t_list **stack_a, t_list **stack_b, \
			int mode, t_stackname stack_name);
void	sx(t_list **stack, int mode, t_stackname stack_name);
void	rx(t_list **stack, int mode, t_stackname stack_name);
void	rrx(t_list **stack, int mode, t_stackname stack_name);
void	rr_all(t_list **stack_a, t_list **stack_b, int mode);
void	r_all(t_list **stack_a, t_list **stack_b, int mode);
void	ss(t_list **stack_a, t_list **stack_b, int mode);

t_uint	get_min_ops(int size_a, int size_b, int pos_a, int pos_b);
void	repeat_op(t_list **stack_a, t_list **stack_b, int count_a, int count_b);
int		get_sorted_position(t_list *stack, int num, int sort_mode);
int		turk_sort(t_list **stack_a, t_list **stack_b);
bool	is_sorted(t_list *lst, int size, int sort_mode);

int		get_content(t_list *node);
int		get_list_max(t_list *stack, int limit);
int		get_list_min(t_list *stack, int limit);
int		c_rr(int size, int pos);
int		push_last_elements(t_list **stack_a, t_list **stack_b, int size);

#endif
