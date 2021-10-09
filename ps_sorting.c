/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:25:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/09 15:44:30 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(long long *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (stack[i] != STOP)
	{
		while (stack[j] != STOP)
		{
			if (stack[i] > stack[j])
				return (0);
			else
				j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	bubble(t_data data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (issorted(data.stack1))
			break ;
		if (data.stack1[0] == 9)
		{
			printf("ra\n");
			rotate(data.stack1);
			i++;
		}
		else if (data.stack1[1] < data.stack1[0])
		{
			printf("sa\n");
			swap(data.stack1);
			i++;
		}
		else
		{
			printf("ra\n");
			rotate(data.stack1);
			i++;
		}
		printstacks(data);
	}
	return (i);
}
