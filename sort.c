/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:12:25 by apple             #+#    #+#             */
/*   Updated: 2025/03/26 20:04:56 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void sort(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    if (s->a_size == 2)
        swap_a(stack_a);
    else if (s->a_size > 2 && s->a_size < 5)
        case_1(stack_a);
    else if (s->a_size >= 5)
        case_3(s, stack_a, stack_b);
}