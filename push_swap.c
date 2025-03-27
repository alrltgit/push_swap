/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:51:55 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 22:00:50 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	printf_stack(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_stack	*temp;

// 	temp = stack_a;
//     ft_printf("stack_a: \n");
//     while (temp)
//     {
//         ft_printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     ft_printf("\n");
//     ft_printf("stack_b: \n");
//     temp = stack_b;
//     while (temp)
//     {
//         ft_printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     // printf_stack(stack_a, stack_b);
//     // if (argv_is_sorted(stack_a))
//     //     ft_printf("Stack_a is sorted.\n");
//     // else
//     //     ft_printf("Stack_a is not sorted.\n");
//     // if (stack_b_is_sorted(&stack_b))
//     //     ft_printf("Stack_b is sorted.\n");
//     // else
//     //     ft_printf("Stack_b is not sorted.\n");
//     ft_printf("\n");
// }

static char	**split_str(t_size *s, int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		s->count = 0;
		while (args[s->count])
			s->count++;
	}
	else
	{
		args = argv + 1;
		s->count = argc - 1;
	}
	return (args);
}

static t_stack	*create_stack_a(t_size *s, char **args)
{
	int		i;
	int		error_flag;
	t_stack	*stack_a;

	stack_a = NULL;
	error_flag = 0;
	i = 0;
	while (i < s->count)
	{
		ft_add_back(&stack_a, ft_atoi(args[i], &error_flag));
		check_error_flag(stack_a, error_flag);
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_size	*s;
	char	**args;

	args = NULL;
	if (argc < 2)
		exit(0);
	s = malloc(sizeof(t_size));
	args = split_str(s, argc, argv);
	s->a_size = s->count;
	s->b_size = 0;
	stack_b = NULL;
	stack_a = create_stack_a(s, args);
	if_valid_sort(s, args, stack_a, stack_b);
	if (argc == 2)
		free(args);
	free_stack(stack_a);
	return (0);
}
