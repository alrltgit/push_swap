/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_argv_dupl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:54:41 by apple             #+#    #+#             */
/*   Updated: 2025/03/18 22:42:27 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	do_argvs_duplicate(int argc, char *argv[])
{
	int i, k;
	int num1, num2;

	i = 1;
	while (i < argc)
	{
		num1 = ft_atoi(argv[i], NULL); // Convert to int
		k = i + 1;
		while (k < argc)
		{
			num2 = ft_atoi(argv[k], NULL);
			if (num1 == num2)
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
