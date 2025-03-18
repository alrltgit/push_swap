/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_argv_dupl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:54:41 by apple             #+#    #+#             */
/*   Updated: 2025/03/18 22:21:31 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	do_argvs_duplicate(int argc, char *argv[])
{
	char	temp;
	int	i;
	int	k;

	i = 0;
	while (i < argc - 1)
	{
		temp = argv[1][i];
		k = i;
		while (k + 1 < argc - 1)
		{
			if (temp == argv[1][k + 1])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
