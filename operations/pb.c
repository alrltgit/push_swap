/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:31:01 by apple             #+#    #+#             */
/*   Updated: 2025/03/18 13:22:13 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	stack_a_realloc(t_size *s, int *stack_a)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	s->a_size--;
	stack_a = my_realloc(stack_a, (s->a_size) * sizeof(int));
	if (!stack_a)
	{
		ft_printf("Memory for stack_a wasn't allocated.\n");
		return ;
	}
}

static void	stack_b_realloc(t_size *s, int *stack_a, int **stack_b)
{
	int	i;

	i = s->b_size;
	while (i > 0)
	{
		(*stack_b)[i] = (*stack_b)[i - 1];
		i--;
	}
	(*stack_b)[0] = stack_a[0];
	s->b_size++;
	*stack_b = my_realloc(*stack_b, (s->b_size) * sizeof(int));
	if (!*stack_b)
	{
		ft_printf("Memory for stack_b wasn't allocated.\n");
		return ;
	}
}

static void	stack_b_zero_case(t_size *s, int *stack_a, int **stack_b)
{
	*stack_b = malloc(sizeof(int));
	if (!*stack_b)
	{
		ft_printf("Memory for array wasn't allocated.\n");
		free(stack_a);
		return ;
	}
	(*stack_b)[0] = stack_a[0];
	s->b_size++;
}

void	push_b(t_size *s, int *stack_a, int **stack_b)
{
	if (s->a_size == 0)
	{
		ft_printf("Stack A is empty.\n");
		return ;
	}
	if (s->b_size == 0)
		stack_b_zero_case(s, stack_a, stack_b);
	else
		stack_b_realloc(s, stack_a, stack_b);
	stack_a_realloc(s, stack_a);
	ft_printf("pb\n");
}
