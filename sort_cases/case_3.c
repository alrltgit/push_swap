// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   case_3.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/13 18:58:14 by apple             #+#    #+#             */
// /*   Updated: 2025/03/25 16:43:55 by apple            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../push_swap.h"

// int stack_b_is_sorted(t_stack **stack)
// {
//     t_stack	*temp;

// 	temp = *stack;
// 	while (temp && temp->next)
// 	{
// 		if (temp->data < temp->next->data)
// 			return (0);
// 		temp = temp->next;
// 	}
// 	return (1);
// }

// t_stack *find_max(t_stack **stack)
// {
//     t_stack *current;
//     t_stack *max_node;
//     int max;

//     if (!stack || !(*stack))
//         return (0);

//     current = *stack;
//     max = current->data;
//     while (current)
//     {
//         if (current->data > max)
//         {
//             max = current->data;
//             max_node = current;
//         }
//         current = current->next;
//     }
//     return (max_node);
// }

// t_stack *find_min(t_stack **stack)
// {
//     t_stack *current;
//     t_stack *min_node;
//     int min;

//     if (!stack || !(*stack))
//         return (0);

//     current = *stack;
//     min = current->data;
//     while (current)
//     {
//         if (current->data < min)
//         {
//             min = current->data;
//             min_node = current;
//         }
//         current = current->next;
//     }
//     return (min_node);
// }

// void	place_min_on_top(t_stack **stack_a)
// {
// 	t_stack	*temp;

// 	temp = find_min(stack_a);
// 	while ((*stack_a)->data != temp->data)
// 	{
// 		if (temp->above_medium)
// 			rotate_a(stack_a);
// 		else
// 			reverse_rotate_a(stack_a);
// 	}
// }

// void	find_idx(int stack_size, t_stack **stack)
// {
// 	int		i;
// 	int		medium;
// 	t_stack	*temp;

// 	i = 0;
// 	temp = (*stack);
// 	if (!temp)
// 		return ;
// 	medium = stack_size / 2;
// 	while (temp)
// 	{
// 		temp->index = i;
// 		if (i <= medium)
// 		    temp->above_medium = true;
// 		else
// 			temp->above_medium = false;
// 		temp = temp->next;
// 		i++;
// 	}
// }

// t_stack *find_cheapest_number(t_stack **stack)
// {
//     t_stack	*temp;

// 	temp = *stack;
// 	if (!temp)
// 		return (NULL);
// 	while (temp)
// 	{
// 		if (temp->cheapest)
// 			return (temp);
// 		temp = temp->next;
// 	}
// 	return (NULL);
// }

// void find_num_position(int size, t_stack **stack)
// {
//     int i = 0;
//     int half_stack;
//     t_stack *temp;

//     temp = *stack;
//     half_stack = size / 2;
//     while (temp)
//     {
//         temp->idx = i;
//         if (temp->idx <= half_stack)
//             temp->above_half = true;
//         else
//             temp->above_half = false;
//         temp = temp->next;
//         i++;
//     }
// }

// void find_num_stack_a(t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack *temp_a;
//     t_stack *temp_b;
//     t_cost cheapest;
//     t_stack *target;

//     temp_a = *stack_a;
//     while (temp_a)
//     {
//         cheapest.cost = INT_MAX;
//         temp_b = *stack_b;
//         while (temp_b)
//         {
//             if (temp_b->data < temp_a->data && temp_b->data > cheapest.cost)
//             {
//                 cheapest.cost = temp_b->data;
//                 target = temp_b;
//             }
//             temp_b = temp_b->next;
//         }
//         if (cheapest.cost == INT_MAX)
//             temp_a->target = find_max(stack_a);
//         else
//             temp_a->target = target;
//         temp_a = temp_a->next;
//     }
// }

// void	find_num_stack_b(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack *temp_a;
//     t_stack *temp_b;
//     t_cost cheapest;
//     t_stack *target;

//     temp_b = *stack_b;
//     while (temp_b)
//     {
//         cheapest.cost = INT_MAX;
//         temp_a = *stack_a;
//         while (temp_a)
//         {
//             if (temp_a->data < temp_b->data && temp_a->data > cheapest.cost)
//             {
//                 cheapest.cost = temp_b->data;
//                 target = temp_a;
//             }
//             temp_a = temp_a->next;
//         }
//         if (cheapest.cost == INT_MAX)
//             temp_b->target = find_min(stack_a);
//         else
//             temp_b->target = target;
//         temp_b = temp_b->next;
//     }
// }

// void count_num_cost_stack_a(t_size *s, t_stack **stack_a)
// {
// 	t_stack	*temp_a;
    
// 	temp_a = *stack_a;
//     while (temp_a)
// 	{
// 		(temp_a)->push_cost = (temp_a)->index;
// 		if (!(temp_a->above_medium))
// 			temp_a->push_cost = s->a_size - (temp_a->index);
// 		if (temp_a->target->above_medium)
// 			temp_a->push_cost += temp_a->target->index;
// 		else
// 			temp_a->push_cost += s->b_size - (temp_a->target->index);
// 		temp_a = temp_a->next;
// 	}
// }

// void num_best_to_move(t_stack **stack)
// {
//     int	cheapest;
// 	t_stack	*cheapest_move;
// 	t_stack	*temp;

// 	temp = *stack;
// 	if (!temp)
// 		return ;
// 	cheapest = INT_MAX;
// 	while (temp)
// 	{
// 		if (temp->push_cost < cheapest)
// 		{
// 			cheapest = temp->push_cost;
// 			cheapest_move = temp;
// 		}
// 		temp = temp->next;
// 	}
// 	cheapest_move->cheapest = true;
// }

// void	find_stack_info(t_size *s, t_stack **stack_a, t_stack **stack_b)
// {
//     int a_size = s->a_size;
//     int b_size = s->b_size;
// 	find_num_position(a_size, stack_a);
// 	find_num_position(b_size, stack_b);
// 	find_num_stack_a(stack_a, stack_b);
// 	count_num_cost_stack_a(s, stack_a);
// 	num_best_to_move(stack_a);
// }

// void	check_top_nodes(t_stack **stack, t_stack *top, char name)
// {
// 	// while (*stack != top)
// 	// {
// 		if (name == 'a')
// 		{
// 			if (top->above_half)
// 				rotate_a(stack);
// 			else
// 				reverse_rotate_a(stack);
// 		}
// 		else if (name == 'b')
// 		{
// 			if (top->above_half)
// 				rotate_b(stack);
// 			else
// 				reverse_rotate_b(stack);
// 		}
        
// 	// }
// }

// void push_to_b(t_size *s, t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack *cheapest_num;

//     cheapest_num = find_cheapest_number(stack_a);
//     if (cheapest_num->above_medium && cheapest_num->target->above_medium)
// 		rotate_idx(s, stack_a, stack_b, cheapest_num);
// 	else if (!(cheapest_num->above_medium) && !(cheapest_num->target->above_medium))
// 		reverse_rotate_idx(s, stack_a, stack_b, cheapest_num);
// 	// check_top_nodes(stack_a, cheapest_num, 'a');
// 	check_top_nodes(stack_b, cheapest_num->target, 'b');
// 	// push_b(s, stack_a, stack_b);
// }

// void	move_back_stack_b(t_size *s, t_stack **stack_a, t_stack **stack_b)
// {
//     int a_size = s->a_size;
//     int b_size = s->b_size;
// 	find_idx(a_size, stack_a);
// 	find_idx(b_size, stack_b);
// 	find_num_stack_b(stack_a, stack_b);
// }

// void	move_to_stack_a(t_size *s, t_stack **stack_a, t_stack **stack_b)
// {
// 	check_top_nodes(stack_a, (*stack_b)->target, 'a');
// 	push_a(s, stack_a, stack_b);
// }

// void	small_stack_sort(t_stack **stack)
// {
// 	t_stack	*max;

// 	if (*stack == NULL || (*stack)->next == NULL)
// 		return ;
// 	if ((*stack)->next->next == NULL)
// 	{
// 		if ((*stack)->data > (*stack)->next->data)
// 			swap_a(stack);
// 		return ;
// 	}
// 	max = find_max(stack);
// 	if (*stack == max)
// 		rotate_a(stack);
// 	else if ((*stack)->next == max)
// 		reverse_rotate_a(stack);
// 	if ((*stack)->data > (*stack)->next->data)
// 		swap_a(stack);
// }

// void case_3(t_size *s, t_stack **stack_a, t_stack **stack_b)
// {
//     int	a_size;

// 	a_size = s->a_size;
// 	if (a_size-- > 3 && !argv_is_sorted(*stack_a))
// 		push_b(s, stack_a, stack_b);
// 	if (a_size-- > 3 && !argv_is_sorted(*stack_a))
// 		push_b(s, stack_a, stack_b);
// 	// while (a_size-- > 3 && !argv_is_sorted(*stack_a))
// 	// {
// 		find_stack_info(s, stack_a, stack_b);
// 		push_to_b(s, stack_a, stack_b);
// 	// }
// 	// small_stack_sort(stack_a);
// 	// while (*stack_b)
// 	// {
// 	// 	move_back_stack_b(s, stack_a, stack_b);
// 	// 	move_to_stack_a(s, stack_a, stack_b);
// 	// }
// 	// find_idx(a_size, stack_a);
// 	// place_min_on_top(stack_a);
// }
