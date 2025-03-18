/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:49:46 by apple             #+#    #+#             */
/*   Updated: 2025/03/11 13:48:33 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(int *stack_a)
{
	int	temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	ft_printf("sa\n");
}

void	swap_b(int *stack_b)
{
	int	temp;

	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	ft_printf("sb\n");
}

void	sa_sb(int *stack_a, int *stack_b)
{
	int	temp_1;
	int	temp_2;

	temp_1 = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp_1;
	temp_2 = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp_2;
	ft_printf("ss\n");
}
