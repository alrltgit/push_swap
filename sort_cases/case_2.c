/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:58:14 by apple             #+#    #+#             */
/*   Updated: 2025/03/28 13:27:50 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int stack_b_is_sorted(t_stack **stack)
// {
//     t_stack	*temp;

// 	temp = *stack;
// 	while (temp && temp->next)
// 	{
// 		if (temp->data < temp->next->data)
// 			return (0);
// 		temp = temp->next;
// 	}
// 	return (1);
// }

int	find_place_in_b(t_stack **stack_b, int num)
{
	t_stack	*current;
	int		moves;

	moves = 0;
	if (!stack_b || !(*stack_b))
		return (0);
	if (num > find_max(stack_b))
		moves = rotate_to_max(stack_b, moves);
	else if (num < find_min(stack_b))
		moves = rotate_to_min(stack_b, moves);
	else
	{
		current = *stack_b;
		while (current->next)
		{
			if (num < current->data && num > current->next->data)
				break ;
			current = current->next;
			moves++;
		}
		moves += 1;
	}
	return (moves);
}

void	sort_stack_b(t_size *s, t_stack **stack_a,
	t_stack **stack_b, t_cost *cheapest)
{
	int	moves;

	if (!stack_a || !stack_b)
		return ;
	(void)s;
	if (cheapest->rb_moves <= cheapest->rrb_moves)
		moves = cheapest->rb_moves;
	else
		moves = cheapest->rrb_moves;
	if (moves < 0)
		moves *= -1;
	rotate_stack_b(cheapest, stack_b, moves);
}

void	update_cheapest_num_info(t_cost *cheapest, t_size *s,
	t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		idx;
	int		total_cost;

	idx = 0;
	temp = *stack_a;
	while (temp)
	{
		if (!*stack_a)
			return ;
		total_cost = count_total_cost(s, stack_a, stack_b, temp->data);
		if (total_cost < cheapest->cost)
		{
			cheapest->index = idx;
			cheapest->cost = total_cost;
			cheapest->move_a = s->moves_a;
			cheapest->rb_moves = s->rb_moves;
			cheapest->rrb_moves = s->rrb_moves;
		}
		idx++;
		temp = temp->next;
	}
}

void	find_cheapest_number(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
	t_cost	*cheapest;

	cheapest = malloc(sizeof(t_cost));
	cheapest->cost = INT_MAX;
	update_cheapest_num_info(cheapest, s, stack_a, stack_b);
	move_num_on_top(cheapest, s, stack_a);
	sort_stack_b(s, stack_a, stack_b, cheapest);
	push_b(s, stack_a, stack_b);
	case_1(stack_a);
	free(cheapest);
}

void	case_2(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
	while (s->a_size > 3)
		find_cheapest_number(s, stack_a, stack_b);
	while (s->b_size > 0)
		find_cheapest_number_a(s, stack_a, stack_b);
	final_rotate(s, stack_a);
}
