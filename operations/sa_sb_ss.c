/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:49:46 by apple             #+#    #+#             */
/*   Updated: 2025/03/19 09:31:27 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack *first;
	t_stack *second;
	int temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	temp = first->data;
	first->data = second->data;
	second->data = temp;
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	t_stack *first;
	t_stack *second;
	int temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	temp = first->data;
	first->data = second->data;
	second->data = temp;
	ft_printf("sb\n");
}

void	sa_sb(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}
