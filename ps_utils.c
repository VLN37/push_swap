/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:08:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/18 09:27:57 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	get_max2(long long *stack)
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
	return (max);
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
	if (i >= (stoplen(stack) / 2) - 1)
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

long long	stopperlen(long long *stack, long long stopper)
{
	int	i;

	i = 0;
	while (stack[i] != stopper)
		i++;
	return (i);
}

long long	stoplen(long long *stack)
{
	int	i;

	i = 0;
	while (stack[i] != STOP)
		i++;
	return (i);
}

void	reset(t_data *data)
{
	int	i;

	i = -1;
	while (data->backup[++i] != STOP)
		data->stack1[i] = data->backup[i];
	i = -1;
	while (++i < data->nbr_count)
		data->stack2[i] = (long long)STOP;
}


void	cleanup(t_data data, int error)
{
	free(data.sorted);
	free(data.backup);
	free(data.stack1);
	free(data.stack2);
	free(data.trial);
	close(3);
	if (error)
		exit(1);
	exit(0);
}
