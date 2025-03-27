/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:32:20 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 16:25:34 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_place_in_a(t_stack **stack_a, int num)
{
	t_stack	*current;
	int		moves;

	moves = 0;
	if (!stack_a || !(*stack_a))
		return (0);
	if (num > find_max(stack_a))
		moves = rotate_to_max_2(stack_a, moves);
	else if (num < find_min(stack_a))
		moves = rotate_to_min_2(stack_a, moves);
	else
	{
		current = *stack_a;
		while (current->next)
		{
			if (num > current->data && num < current->next->data)
				break ;
			current = current->next;
			moves++;
		}
		moves += 1;
	}
	return (moves);
}

void	sort_stack_a(t_size *s, t_stack **stack_a,
	t_stack **stack_b, t_cost *cheapest)
{
	int	moves;

	if (!stack_a || !stack_b)
		return ;
	(void)s;
	if (cheapest->ra_moves <= cheapest->rra_moves)
		moves = cheapest->ra_moves;
	else
		moves = cheapest->rra_moves;
	if (moves < 0)
		moves *= -1;
	rotate_stack_a_2(cheapest, stack_a, moves);
}

int	count_total_a_cost(t_size *s, t_stack **stack_a,
	t_stack **stack_b, int data)
{
	int	total_cost;

	s->moves_b = count_moves_stack_b(s, stack_b, data);
	s->ra_moves = count_moves_stack_a(s, stack_a, data);
	if (s->a_size == 0)
		s->rra_moves = 0;
	else
		s->rra_moves = s->a_size - s->ra_moves;
	if (s->ra_moves <= s->rra_moves)
		total_cost = s->ra_moves + s->moves_b;
	else
		total_cost = s->rra_moves + s->moves_b;
	return (total_cost);
}

void	update_cheapest_num_a_info(t_cost *cheapest_a, t_size *s,
	t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*temp;
	int		total_cost;
	int		idx;

	idx = 0;
	temp = *stack_b;
	while (temp)
	{
		if (!*stack_b)
			return ;
		total_cost = count_total_a_cost(s, stack_a, stack_b, temp->data);
		if (total_cost < cheapest_a->cost)
		{
			cheapest_a->index = idx;
			cheapest_a->cost = total_cost;
			cheapest_a->move_b = s->moves_b;
			cheapest_a->ra_moves = s->ra_moves;
			cheapest_a->rra_moves = s->rra_moves;
		}
		idx++;
		temp = temp->next;
	}
}

void	find_cheapest_number_a(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
	t_cost	*cheapest_a;

	cheapest_a = malloc(sizeof(t_cost));
	cheapest_a->cost = INT_MAX;
	update_cheapest_num_a_info(cheapest_a, s, stack_b, stack_a);
	move_num_b_on_top(cheapest_a, s, stack_b);
	sort_stack_a(s, stack_a, stack_b, cheapest_a);
	push_a(s, stack_a, stack_b);
	free(cheapest_a);
}
