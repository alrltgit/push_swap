/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:51:55 by apple             #+#    #+#             */
/*   Updated: 2025/03/26 18:10:44 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printf_stack(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *temp;

    temp = stack_a;
    ft_printf("stack_a: \n");
    while (temp)
    {
        ft_printf("%d ", temp->data);
        temp = temp->next;
    }
    ft_printf("\n");
    ft_printf("stack_b: \n");
    temp = stack_b;
    while (temp)
    {
        ft_printf("%d ", temp->data);
        temp = temp->next;
    }
    ft_printf("\n");
}

int	argv_is_valid(int argc, char *argv[])
{
	if (argv_is_int(argc, argv) == 0 || do_argvs_duplicate(argc, argv) == 0)
		return (0);
	return (1);
}

static void	check_error_flag(t_stack *stack, int error_flag)
{
	if (error_flag)
	{
		ft_printf("Error.\n");
		free_stack(stack);
		exit(1);
	}
}

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_size *s;
    int i;
    int error_flag;

    if (argc <= 2)
        return (0);
    if (!argv_is_valid(argc, argv))
    {
        ft_printf("Error.\n");
        exit(1);
    }
    s = malloc(sizeof(int));
    s->a_size = argc - 1;
    s->b_size = 0;
    stack_a = NULL;
    stack_b = NULL;
    error_flag = 0;
    i = 1;
    while (i < argc)
    {
        ft_add_back(&stack_a, ft_atoi(argv[i], &error_flag));
        check_error_flag(stack_a, error_flag);
        i++;
    }
    if (argv_is_sorted(stack_a))
    {
        ft_printf("Error.\n");
        exit(1);
    }
    else
        sort(s, &stack_a, &stack_b);
    // printf_stack(stack_a, stack_b);
    // if (argv_is_sorted(stack_a))
    //     ft_printf("Stack_a is sorted.\n");
    // else
    //     ft_printf("Stack_a is not sorted.\n");
    // if (stack_b_is_sorted(&stack_b))
    //     ft_printf("Stack_b is sorted.\n");
    // else
    //     ft_printf("Stack_b is not sorted.\n");
    free_stack(stack_a);
    return (0);
}