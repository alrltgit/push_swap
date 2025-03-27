/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:26:34 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 10:28:05 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../push_swap.h"

int find_max(t_stack **stack)
{
    t_stack *current;
    int max;

    if (!stack || !(*stack))
        return (0);

    current = *stack;
    max = current->data;

    while (current)
    {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return (max);
}

int find_min(t_stack **stack)
{
    t_stack *current;
    int min;

    if (!stack || !(*stack))
        return (0);

    current = *stack;
    min = current->data;

    while (current)
    {
        if (current->data < min)
            min = current->data;
        current = current->next;
    }
    return min;
}