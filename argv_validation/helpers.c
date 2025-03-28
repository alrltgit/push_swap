/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:47:41 by apple             #+#    #+#             */
/*   Updated: 2025/03/28 07:26:19 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	argv_is_valid(int count, char **args)
{
	if (argv_is_int(count, args) == 0 || do_argvs_duplicate(count, args) == 0)
		return (0);
	return (1);
}

void	check_error_flag(t_size *s, t_stack *stack, int error_flag)
{
	if (error_flag)
	{
		ft_printf("Error\n");
		free_stack(stack);
		free(s);
		exit(1);
	}
}

void	if_valid_sort(t_size *s, char **args,
		t_stack *stack_a, t_stack *stack_b)
{
	if (!argv_is_valid(s->count, args))
	{
		ft_printf("Error\n");
		free_stack(stack_a);
		free(s);
		exit(1);
	}
	if (argv_is_sorted(stack_a))
	{
		free_stack(stack_a);
		free(s);
		exit(0);
	}
	else
		sort(s, &stack_a, &stack_b);
}
