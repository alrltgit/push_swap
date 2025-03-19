/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:54:52 by apple             #+#    #+#             */
/*   Updated: 2025/03/19 09:27:59 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	temp->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = temp;
	*stack_a = temp;
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	temp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = temp;
	*stack_b = temp;
	ft_printf("pa\n");
}
