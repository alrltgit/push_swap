/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:54:52 by apple             #+#    #+#             */
/*   Updated: 2025/03/16 17:27:33 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_size *s, int **stack_a, int **stack_b)
{
	int	i;
	int *stack_a_temp;
	int *stack_b_temp;

	stack_a_temp = realloc(*stack_a, sizeof(int) * (s->a_size + 1));
	if (!stack_a_temp)
	{
		ft_printf("Memory wasn't allocated.\n");
		return ;
	}
	*stack_a = stack_a_temp;
	i = s->a_size;
	while (i > 0)
	{
		(*stack_a)[i] = (*stack_a)[i - 1];
		i--;
	}
	(*stack_a)[0] = (*stack_b)[0];
	stack_b_temp = realloc(*stack_b, sizeof(int) * (s->b_size - 1));
	if (!stack_b_temp)
	{
		ft_printf("Memory wasn't allocated.\n");
		return ;
	}
	*stack_b = stack_b_temp;
	i = 0;
	while (i < s->b_size)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		i++;
	}
	s->a_size++;
	s->b_size--;
	ft_printf("pa\n");
}
