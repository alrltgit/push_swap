/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:12:25 by apple             #+#    #+#             */
/*   Updated: 2025/03/24 15:30:01 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void sort(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    // (void)*stack_b;
    if (count_stack_size(stack_a) == 2)
        swap_a(stack_a);
    else if (count_stack_size(stack_a) == 3)
        case_1(stack_a);
    else if (count_stack_size(stack_a) == 4 || count_stack_size(stack_a) == 5)
        case_2(s, stack_a, stack_b);
    else if (count_stack_size(stack_a) > 5 && count_stack_size(stack_a) < 100)
        case_3(s, stack_a, stack_b);
        // case_4(s, stack_a, stack_b);
    // else if (count_stack_size(stack_a) == 100)
        // find_cheapest_number(s, stack_a, stack_b);
        case_3(s, stack_a, stack_b);
}