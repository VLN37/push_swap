/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:25:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/15 01:29:53 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	get_relative_min(long long *stack, long long curr)
{
	long long	min;

	min = STOP;
	while (*stack != STOP)
	{
		if (*stack < min && *stack > curr)
			min = *stack;
		stack++;
	}
	return (min);
}

int	selection_sort(t_data data)
{
	long long	curr;
	int			i;

	i = -1;
	curr = -2147483648;
	while (curr != STOP)
	{
		curr = get_relative_min(data.stack1, curr);
		data.sorted[++i] = curr;
	}
	// for (int j = 0; data.sorted[j - 1] != STOP; j++)
	// 	printf("%lld ", data.sorted[j]);
	return (get_median(data.sorted));
}

t_data	bubble(t_data data)
{
	data.stack1max = get_max(data.stack1, &data.direction);
	while (1)
	{
		if (issorted(data.stack1))
			break ;
		if (data.stack1[0] == data.stack1max)
			data = game("ra\n", data, &data.trialiter);
		else if (data.stack1[1] < data.stack1[0])
			data = game("sa\n", data, &data.trialiter);
		else
			data = game("ra\n", data, &data.trialiter);
		if (DEBUG)
			printstacks(data);
	}
	data.stackmedian = get_median(data.stack1);
	printf("iter = %i\n", data.trialiter);
	return (data);
}
