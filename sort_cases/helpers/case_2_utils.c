/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_2_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:14:55 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 15:39:52 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_stack_a(t_size *s, t_stack **stack_a, int max_min)
{
	if (s->ra_moves <= s->rra_moves)
	{
		while ((*stack_a)->data != max_min)
			rotate_a(stack_a);
	}
	else
	{
		while ((*stack_a)->data != max_min)
			reverse_rotate_a(stack_a);
	}
}

void	rotate_stack_b(t_cost *cheapest, t_stack **stack_b, int moves)
{
	if (cheapest->rb_moves <= cheapest->rrb_moves)
	{
		while (moves > 0)
		{
			rotate_b(stack_b);
			moves--;
		}
	}
	else
	{
		while (moves > 0)
		{
			reverse_rotate_b(stack_b);
			moves--;
		}
	}
}

int	rotate_to_max(t_stack **stack_b, int moves)
{
	t_stack	*current;

	current = *stack_b;
	while (current && current->data != find_max(stack_b))
	{
		current = current->next;
		moves++;
	}
	return (moves);
}

int	rotate_to_min(t_stack **stack_b, int moves)
{
	t_stack	*current;

	current = *stack_b;
	while (current && current->data != find_min(stack_b))
	{
		current = current->next;
		moves++;
	}
	moves += 1;
	return (moves);
}

void	final_rotate(t_size *s, t_stack **stack_a)
{
	int		max_min;
	int		max_idx;
	t_stack	*temp;

	max_min = find_min(stack_a);
	temp = *stack_a;
	max_idx = 0;
	while (temp)
	{
		if (temp->data == max_min)
			break ;
		max_idx++;
		temp = temp->next;
	}
	s->ra_moves = max_idx;
	s->rra_moves = s->a_size - s->ra_moves;
	rotate_stack_a(s, stack_a, max_min);
}
