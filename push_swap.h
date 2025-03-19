/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:11:44 by apple             #+#    #+#             */
/*   Updated: 2025/03/19 12:24:11 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}   t_stack;

typedef struct stack_size
{
    int a_size;
    int b_size;
}   t_size;

t_stack	*ft_new(int data);
t_stack	*ft_add_back(t_stack **head, int data);
void free_stack(t_stack *stack);
size_t count_stack_size(t_stack **stack);

int	argv_is_int(int argc, char *argv[]);
int	do_argvs_duplicate(int argc, char *argv[]);
int	argv_is_sorted(t_stack *stack);

void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	rra_rrb(t_stack **stack_a, t_stack **stack_b);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	sa_sb(t_stack **stack_a, t_stack **stack_b);
void    sort(t_stack **stack_a, t_stack **stack_b);

void    case_1(t_stack **stack_a);
void case_2(t_stack **stack_a, t_stack **stack_b);

#endif
