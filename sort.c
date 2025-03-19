/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:12:25 by apple             #+#    #+#             */
/*   Updated: 2025/03/19 17:29:17 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void sort(t_stack **stack_a, t_stack **stack_b)
{
    (void)*stack_b;
    if (count_stack_size(stack_a) == 2)
        swap_a(stack_a);
    else if (count_stack_size(stack_a) == 3)
        case_1(stack_a);
    else if (count_stack_size(stack_a) == 4 || count_stack_size(stack_a) == 5)
        case_2(stack_a, stack_b);
    else if (count_stack_size(stack_a) > 5)
        case_3(stack_a, stack_b);
    // push_b(stack_a, stack_b);
    // push_a(stack_a, stack_b);
    // rotate_a(stack_a);
    // rotate_b(stack_b);
    // reverse_rotate_a(stack_a);
    // reverse_rotate_b(stack_b);
    // rra_rrb(stack_a, stack_b);
    // swap_b(stack_b);
    // sa_sb(stack_a, stack_b);
}