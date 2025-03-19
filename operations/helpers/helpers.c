/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:48:05 by apple             #+#    #+#             */
/*   Updated: 2025/03/19 12:25:32 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../push_swap.h"

size_t count_stack_size(t_stack **stack)
{
    t_stack *temp;
    size_t count;

    temp = *stack;
    count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    // ft_printf("stack_size: %d\n", count);
    return (count);
}