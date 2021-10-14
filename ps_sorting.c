/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:25:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/14 00:09:27 by jofelipe         ###   ########.fr       */
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
	long long	tmp[data.nbr_count + 1];
	long long 	curr;
	int	i;

	i = -1;
	ft_memcpy(tmp, data.stack1, sizeof(long long) * (data.nbr_count + 1));
	curr = -2147483648;
	while (curr != STOP)
	{
		curr = get_relative_min(data.stack1, curr);
		tmp[++i] = curr;
	}
	for (int j = 0; tmp[j - 1] != STOP; j++)
		printf("%lld ", tmp[j]);
	return (get_median(tmp));
}

t_data	bubble(t_data data)
{
	data.stack1max = get_max(data.stack1);
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
