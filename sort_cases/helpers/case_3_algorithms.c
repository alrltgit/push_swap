/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3_algorithms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:52:13 by apple             #+#    #+#             */
/*   Updated: 2025/03/19 14:18:19 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void nums_in_second_part(t_stack **stack_a, int hold_first_idx, int hold_second_idx)
{
    int count_to_max_1;
    int count_to_max_2;

    count_to_max_1 = find_count_to_max_1(stack_a, hold_first_idx);
    count_to_max_2 = find_count_to_max_2(stack_a, hold_second_idx);
    if (count_to_max_2 < count_to_max_1)
        reverse_rotate_idx(stack_a, hold_second_idx);
    else
        reverse_rotate_idx(stack_a, hold_first_idx);
}

void nums_in_first_part(t_stack **stack_a, int hold_first_idx, int hold_second_idx)
{
    int count_to_zero_1;
    int count_to_zero_2;
    
    count_to_zero_1 = find_count_to_zero_1(hold_first_idx);
    count_to_zero_2 = find_count_to_zero_2(hold_second_idx);
    if (count_to_zero_1 < count_to_zero_2)
        rotate_idx(stack_a, hold_first_idx);
    else
        rotate_idx(stack_a, hold_second_idx);
}