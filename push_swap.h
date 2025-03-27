/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:11:44 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 21:22:16 by apple            ###   ########.fr       */
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
	int			data;
	struct Node	*prev;
	struct Node	*next;
}	t_stack;

typedef struct stack_size
{
	int	a_size;
	int	b_size;
	int	count;
	int	rrb_moves;
	int	rb_moves;
	int	ra_moves;
	int	rra_moves;
	int	moves_a;
	int	moves_b;
	int	idx;
}	t_size;

typedef struct s_cost
{
	int	index;
	int	cost;
	int	move_a;
	int	move_b;
	int	rb_moves;
	int	rrb_moves;
	int	ra_moves;
	int	rra_moves;
}	t_cost;

void	printf_stack(t_stack *stack_a, t_stack *stack_b);
// int stack_b_is_sorted(t_stack **stack);

t_stack	*ft_new(int data);
t_stack	*ft_add_back(t_stack **head, int data);
void	free_stack(t_stack *stack);

int		argv_is_valid(int count, char **args);
void	check_error_flag(t_stack *stack, int error_flag);
void	if_valid_sort(t_size *s, char **args,
			t_stack *stack_a, t_stack *stack_b);
int		argv_is_int(int count, char **args);
int		do_argvs_duplicate(int count, char **args);
int		argv_is_sorted(t_stack *stack);
void	push_a(t_size *s, t_stack **stack_a, t_stack **stack_b);
void	push_b(t_size *s, t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	rra_rrb(t_stack **stack_a, t_stack **stack_b);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	sa_sb(t_stack **stack_a, t_stack **stack_b);
void	sort(t_size *s, t_stack **stack_a, t_stack **stack_b);
void	case_1(t_stack **stack_a);
void	case_2(t_size *s, t_stack **stack_a, t_stack **stack_b);
int		count_moves_a(t_size *s, t_stack **stack_a, int data);
int		count_moves_b(t_size *s, t_stack **stack_b, int data);
void	move_num_on_top(t_cost *cheapest, t_size *s, t_stack **stack_a);
int		find_place_in_b(t_stack **stack_b, int num);
void	push_to_stack_a(t_size *s, t_stack **stack_a, t_stack **stack_b);
int		find_max(t_stack **stack);
int		find_min(t_stack **stack);
int		count_total_cost(t_size *s, t_stack **stack_a,
			t_stack **stack_b, int data);
int		count_moves_stack_b(t_size *s, t_stack **stack_b, int data);
int		count_moves_stack_a(t_size *s, t_stack **stack_a, int data);
void	move_num_b_on_top(t_cost *cheapest, t_size *s, t_stack **stack_b);
int		find_place_in_a(t_stack **stack_a, int num);
void	rotate_stack_a_2(t_cost *cheapest, t_stack **stack_a, int moves);
int		rotate_to_max_2(t_stack **stack_a, int moves);
int		rotate_to_min_2(t_stack **stack_a, int moves);
void	rotate_stack_a(t_size *s, t_stack **stack_a, int max_min);
void	rotate_stack_b(t_cost *cheapest, t_stack **stack_b, int moves);
int		rotate_to_max(t_stack **stack_b, int moves);
int		rotate_to_min(t_stack **stack_b, int moves);
void	final_rotate(t_size *s, t_stack **stack_a);
int		find_count_to_zero(t_stack **stack, int value);
void	rotate_idx(t_stack **stack_a, int idx);
void	reverse_rotate_idx(t_size *s, t_stack **stack_a, int idx);
void	find_cheapest_number_a(t_size *s, t_stack **stack_a, t_stack **stack_b);
int		find_min(t_stack **stack);
int		find_max(t_stack **stack);
void	move_num_on_top(t_cost *cheapest, t_size *s, t_stack **stack_a);

#endif
