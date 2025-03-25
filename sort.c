/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:12:25 by apple             #+#    #+#             */
/*   Updated: 2025/03/25 16:45:12 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void sort(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    // (void)*stack_b;
    if (count_stack_size(stack_a) == 2)
        swap_a(stack_a);
    else if (count_stack_size(stack_a) == 3)
        small_stack_sort(stack_a);
    else if (count_stack_size(stack_a) > 5)
        // case_3(s, stack_a, stack_b);
        sort_stack(s, stack_a, stack_b);
}