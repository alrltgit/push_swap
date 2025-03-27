/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:18:36 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 15:48:37 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	count_moves_stack_b(t_size *s, t_stack **stack_b, int data)
{
	int	moves_b;
	int	rb;
	int	rrb;

	rb = find_count_to_zero(stack_b, data);
	rrb = s->b_size - rb;
	if (rb < rrb)
		moves_b = rb;
	else
		moves_b = rrb;
	return (moves_b);
}

int	count_moves_stack_a(t_size *s, t_stack **stack_a, int data)
{
	s->ra_moves = find_place_in_a(stack_a, data);
	return (s->ra_moves);
}

void	move_num_b_on_top(t_cost *cheapest, t_size *s, t_stack **stack_b)
{
	if (cheapest->index <= (s->b_size / 2))
		rotate_idx(stack_b, cheapest->index);
	else
		reverse_rotate_idx(s, stack_b, cheapest->index);
}
