/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_2_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:59:03 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 15:33:34 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_to_stack_a(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
	while (s->b_size > 0)
		push_a(s, stack_a, stack_b);
}

int	count_moves_a(t_size *s, t_stack **stack_a, int data)
{
	int	moves_a;
	int	ra;
	int	rra;

	ra = find_count_to_zero(stack_a, data);
	rra = s->a_size - ra;
	if (ra < rra)
		moves_a = ra;
	else
		moves_a = rra;
	return (moves_a);
}

int	count_moves_b(t_size *s, t_stack **stack_b, int data)
{
	s->rb_moves = find_place_in_b(stack_b, data);
	return (s->rb_moves);
}

void	move_num_on_top(t_cost *cheapest, t_size *s, t_stack **stack_a)
{
	if (cheapest->index <= (s->a_size / 2))
		rotate_idx(stack_a, cheapest->index);
	else
		reverse_rotate_idx(s, stack_a, cheapest->index);
}

int	count_total_cost(t_size *s, t_stack **stack_a, t_stack **stack_b, int data)
{
	int	total_cost;

	s->moves_a = count_moves_a(s, stack_a, data);
	s->rb_moves = count_moves_b(s, stack_b, data);
	if (s->b_size == 0)
		s->rrb_moves = 0;
	else
		s->rrb_moves = s->b_size - s->rb_moves;
	if (s->rb_moves <= s->rrb_moves)
		total_cost = s->rb_moves + s->moves_a;
	else
		total_cost = s->rrb_moves + s->moves_a;
	return (total_cost);
}
