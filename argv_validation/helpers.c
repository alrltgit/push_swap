/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:47:41 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 09:48:49 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	argv_is_valid(int count, char **args)
{
	if (argv_is_int(count, args) == 0 || do_argvs_duplicate(count, args) == 0)
		return (0);
	return (1);
}

void	check_error_flag(t_stack *stack, int error_flag)
{
	if (error_flag)
	{
		ft_printf("Error.\n");
		free_stack(stack);
		exit(1);
	}
}

void if_valid_sort(t_size *s, char **args, t_stack *stack_a, t_stack *stack_b)
{
    if (!argv_is_valid(s->count, args))
    {
        ft_printf("Error.\n");
        free(args);
        free_stack(stack_a);
        exit(1);
    }
    if (argv_is_sorted(stack_a))
    {
        ft_printf("Error.\n");
        free(args);
        free_stack(stack_a);
        exit(1);
    }
    else
        sort(s, &stack_a, &stack_b);
}