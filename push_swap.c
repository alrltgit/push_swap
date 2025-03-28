/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:51:55 by apple             #+#    #+#             */
/*   Updated: 2025/03/28 22:52:44 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		check_error_flag(s, args, stack_a, error_flag);
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
	s->argc = argc;
	stack_b = NULL;
	stack_a = create_stack_a(s, args);
	if_valid_sort(s, args, stack_a, stack_b);
	return (0);
}
