/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_argv_dupl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:54:41 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 15:11:08 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	do_argvs_duplicate(int count, char **args)
{
	int	i;
	int	k;
	int	num1;
	int	num2;

	k = 0;
	i = 0;
	while (i < count)
	{
		num1 = ft_atoi(args[i], NULL);
		k = i + 1;
		while (k < count)
		{
			num2 = ft_atoi(args[k], NULL);
			if (num1 == num2)
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
