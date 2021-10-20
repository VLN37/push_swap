/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:08:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 11:13:10 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	get_max(long long *stack)
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

int	get_direction(t_data data, long long *stack)
{
	int	i;
	int	j;
	int	len;

	len = stoplen(stack);
	j = 0;
	i = 0;
	while (j < len)
	{
		if (stack[len - j - 1] == data.stack2max || stack[len - j - 1] == data.stack2min)
			break;
		j++;

	}
	while (stack[i] != STOP)
	{
		if (stack[i] == data.stack2max || stack[i] == data.stack2min)
			break ;
		i++;
	}
	if (j <= i)
		return (LEFT);
	return (RIGHT);
}

long long	stoplen(long long *stack)
{
	int	i;

	i = 0;
	while (stack[i] != STOP)
		i++;
	return (i);
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
