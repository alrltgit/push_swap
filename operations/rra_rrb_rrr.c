/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:00:40 by apple             #+#    #+#             */
/*   Updated: 2025/03/19 09:19:10 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack *last;
	t_stack *second_last;

	if (!stack_a || !*stack_a || !(*stack_a) ->next)
		return ;
	last = *stack_a;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_a;
	(*stack_a)->prev = last;
	*stack_a = last;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack *last;
	t_stack *second_last;

	if (!stack_b || !*stack_b || !(*stack_b) ->next)
		return ;
	last = *stack_b;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_b;
	(*stack_b)->prev = last;
	*stack_b = last;
	ft_printf("rrb\n");
}

void	rra_rrb(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
}
