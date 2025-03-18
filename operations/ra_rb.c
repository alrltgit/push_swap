/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:28 by apple             #+#    #+#             */
/*   Updated: 2025/03/18 23:22:32 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	rotate_a(t_stack *stack_a)
// {
// 	while (i < s->a_size - 1)
// 	{
// 		stack_a[i] = stack_a[i + 1];
// 		i++;
// 	}
// 	stack_a[s->a_size - 1] = first_num;
// 	ft_printf("ra\n");
// }

void	rotate_b(t_size *s, int *stack_b)
{
	int	i;
	int	first_num;

	first_num = stack_b[0];
	i = 0;
	while (i < s->b_size - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[s->b_size - 1] = first_num;
	ft_printf("rb\n");
}
