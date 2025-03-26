/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:11:44 by apple             #+#    #+#             */
/*   Updated: 2025/03/26 23:02:23 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
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
    int rrb_moves;
    int rb_moves;
    int ra_moves;
    int rra_moves;
}   t_size;

typedef struct s_cost
{
    int index;
    int cost;
    int move_a;
    int move_b;
    int rb_moves;
    int rrb_moves;
    int ra_moves;
    int rra_moves;
} t_cost;

void printf_stack(t_stack *stack_a, t_stack *stack_b);
int stack_b_is_sorted(t_stack **stack);

t_stack	*ft_new(int data);
t_stack	*ft_add_back(t_stack **head, int data);
void free_stack(t_stack *stack);
size_t count_stack_size(t_stack **stack);

int	argv_is_int(int argc, char *argv[]);
int	do_argvs_duplicate(int argc, char *argv[]);
int	argv_is_sorted(t_stack *stack);

void	push_a(t_size *s, t_stack **stack_a, t_stack **stack_b);
void	push_b(t_size *s, t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	rra_rrb(t_stack **stack_a, t_stack **stack_b);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	sa_sb(t_stack **stack_a, t_stack **stack_b);
void    sort(t_size *s, t_stack **stack_a, t_stack **stack_b);

// void	small_stack_sort(t_stack **stack);

void    case_1(t_stack **stack_a);
void    case_2(t_size *s, t_stack **stack_a, t_stack **stack_b);
void    case_3(t_size *s, t_stack **stack_a, t_stack **stack_b);
void    case_4(t_size *s, t_stack **stack_a, t_stack **stack_b);
// void	sort_stack(t_size *s, t_stack **stack_a, t_stack **stack_b);

int find_hold_first(t_stack **stack_a, int chunk_min, int chunk_max);
int find_hold_second(t_stack **stack_a, int chunk_min, int chunk_max);
int find_count_to_zero(t_stack **stack, int value);
int find_count_to_max(t_size *s, int hold_second_idx);
void rotate_idx(t_stack **stack_a, int idx);
void reverse_rotate_idx(t_size *s, t_stack **stack_a, int idx);

// int     find_lowest(t_stack **stack_a);
// int     find_highest(t_stack **stack_a);
// t_stack *find_cheapest_number(t_stack **stack);
// void	find_idx(int stack_size, t_stack **stack);

// void	sort_stack(t_size *s, t_stack **stack_a, t_stack **stack_b);
void find_cheapest_number_a(t_size *s, t_stack **stack_a, t_stack **stack_b);
int find_min(t_stack **stack);
int find_max(t_stack **stack);
void move_num_on_top(t_cost cheapest, t_size *s, t_stack **stack_a);

#endif
