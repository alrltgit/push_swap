/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:26:34 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 15:45:23 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_max(t_stack **stack)
{
	t_stack	*current;
	int		max;

	if (!stack || !(*stack))
		return (0);
	current = *stack;
	max = current->data;
	while (current)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}

int	find_min(t_stack **stack)
{
	t_stack	*current;
	int		min;

	if (!stack || !(*stack))
		return (0);
	current = *stack;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}

void	rotate_idx(t_stack **stack_a, int idx)
{
	int	i;

	i = idx;
	while (i > 0)
	{
		rotate_a(stack_a);
		i--;
	}
}

void	reverse_rotate_idx(t_size *s, t_stack **stack_a, int idx)
{
	int	i;

	i = idx;
	while (i < s->a_size)
	{
		reverse_rotate_a(stack_a);
		i++;
	}
}

int	find_count_to_zero(t_stack **stack, int value)
{
	t_stack	*temp;
	int		idx;

	temp = *stack;
	idx = 0;
	while (temp)
	{
		if (temp->data == value)
			break ;
		temp = temp->next;
		idx++;
	}
	return (idx);
}
