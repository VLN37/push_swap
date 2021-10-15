/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:14:36 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/14 22:21:40 by jofelipe         ###   ########.fr       */
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

long long	get_max(long long *stack, int *direction)
{
	int	i;
	int	max;

	i = 0;
	max = -2147482648;
	while (stack[i] != STOP)
	{
		if (stack[i] > max)
			max = stack[i];
		++i;
	}
	if (i > stoplen(stack) / 2)
		*direction = LEFT;
	else
		*direction = RIGHT;
	return (max);
}

long long	get_min(long long *stack)
{
	int	i;
	int	min;

	i = 0;
	min = 2147483647;
	while (stack[i] != STOP)
	{
		if (stack[i] < min)
			min = stack[i];
		++i;
	}
	return (min);
}

long long	get_median(long long *arr)
{
	int	median;
	int	j;

	j = 0;
	median = stoplen(arr) / 2;
	return (arr[median]);
}
