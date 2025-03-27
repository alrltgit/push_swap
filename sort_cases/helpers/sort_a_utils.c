/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:26:44 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 14:35:16 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../push_swap.h"

void rotate_stack_a_2(t_cost *cheapest, t_stack **stack_a, int moves)
{
    if (cheapest->ra_moves <= cheapest->rra_moves)
    {
        while (moves > 0)
        {
            rotate_a(stack_a);
            moves--;
        }
    }
    else
    {
        while (moves > 0)
        {
            reverse_rotate_a(stack_a);
            moves--;
        }
    }
}

int rotate_to_max_2(t_stack **stack_a, int moves)
{
    t_stack *current;

    current = *stack_a;
    while (current && current->data != find_max(stack_a))
    {
        current = current->next;
        moves++;
    }
    moves += 1;
    return (moves);
}

int rotate_to_min_2(t_stack **stack_a, int moves)
{
    t_stack *current;

    current = *stack_a;
    while (current && current->data != find_min(stack_a))
    {
        current = current->next;
        moves++;
    }
    return (moves);
}
