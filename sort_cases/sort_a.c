/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:32:20 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 00:13:46 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

int find_place_in_a(t_stack **stack_a, int num)
{
    t_stack *current;
    int moves = 0;

    if (!stack_a || !(*stack_a))
        return 0;
    if (num > find_max(stack_a))
    {
        current = *stack_a;
        while (current && current->data != find_max(stack_a))
        {
            current = current->next;
            moves++;
        }
        return (moves += 1);
    }
    else if (num < find_min(stack_a))
    {
        current = *stack_a;
        while (current && current->data != find_min(stack_a))
        {
            current = current->next;
            moves++;
        }
        return (moves);
    }
    else
    {
        current = *stack_a;
        while (current->next)
        {
            if (num > current->data && num < current->next->data)
                break;
            current = current->next;
            moves++;
        }
        return (moves += 1);
    }
    return (0);
}

int count_moves_stack_b(t_size *s, t_stack **stack_b, int data)
{
    int moves_b;
    int rb;
    int rrb;
    
    rb = find_count_to_zero(stack_b, data);
    rrb = s->b_size - rb;
    if (rb < rrb)
        moves_b = rb;
    else
        moves_b = rrb;
    return (moves_b);
}

int count_moves_stack_a(t_size *s, t_stack **stack_a, int data)
{
    s->ra_moves = find_place_in_a(stack_a, data);
    return (s->ra_moves);
}

void move_num_b_on_top(t_cost cheapest, t_size *s, t_stack **stack_b)
{
    if (cheapest.index <= (s->b_size / 2))
        rotate_idx(stack_b, cheapest.index);
    else
        reverse_rotate_idx(s, stack_b, cheapest.index);
}

void sort_stack_a(t_size *s, t_stack **stack_a, t_stack **stack_b, t_cost cheapest)
{
    int moves;

    if (!stack_a || !stack_b)
        return ;
    (void)s;
    if (cheapest.ra_moves <= cheapest.rra_moves)
        moves = cheapest.ra_moves;
    else
        moves = cheapest.rra_moves;
    if (moves < 0)
        moves *= -1;
    if (cheapest.ra_moves <= cheapest.rra_moves)
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

void find_cheapest_number_a(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    t_cost cheapest_a;
    int moves_b;
    int total_cost;

    cheapest_a.cost = INT_MAX;
    int i = 0;
    temp = *stack_b;
    while (temp)
    {
        if (!*stack_b)
            return ;
        moves_b = count_moves_stack_b(s, stack_b, temp->data);
        s->ra_moves = count_moves_stack_a(s, stack_a, temp->data);
        if (s->a_size == 0)
            s->rra_moves = 0;
        else
            s->rra_moves = s->a_size - s->ra_moves;
        if (s->ra_moves <= s->rra_moves)
            total_cost = s->ra_moves + moves_b;
        else
            total_cost = s->rra_moves + moves_b;
        if (total_cost < cheapest_a.cost)
        {
            cheapest_a.index = i;
            cheapest_a.cost = total_cost;
            cheapest_a.move_b = moves_b;
            cheapest_a.ra_moves = s->ra_moves;
            cheapest_a.rra_moves = s->rra_moves;
        }
        i++;
        temp = temp->next;
    }
    move_num_b_on_top(cheapest_a, s, stack_b);
    sort_stack_a(s, stack_a, stack_b, cheapest_a);
    push_a(s, stack_a, stack_b);
    // case_1(stack_a);
    // printf_stack(*stack_a, *stack_b);
}