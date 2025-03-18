/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:11:44 by apple             #+#    #+#             */
/*   Updated: 2025/03/18 23:14:41 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct stack_size
{
    int a_size;
    int b_size;
}   t_size;

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}   t_stack;

t_stack	*ft_add_back(t_stack **head, int data);
void free_stack(t_stack *stack);

int	argv_is_int(int argc, char *argv[]);
int	do_argvs_duplicate(int argc, char *argv[]);
int	argv_is_sorted(t_stack *stack);

#endif
