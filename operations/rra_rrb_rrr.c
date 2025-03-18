/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:00:40 by apple             #+#    #+#             */
/*   Updated: 2025/03/11 19:24:29 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_size *s, int *stack_a)
{
	int	i;

	i = s->a_size;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_a[s->a_size];
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_size *s, int *stack_b)
{
	int	i;

	i = s->b_size;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_b[s->b_size];
	ft_printf("rrb\n");
}

void	rra_rrb(t_size *s, int *stack_a, int *stack_b)
{
	int	i;

	i = s->a_size;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_a[s->a_size];
	i = s->b_size;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_b[s->b_size];
	ft_printf("rrr\n");
}
