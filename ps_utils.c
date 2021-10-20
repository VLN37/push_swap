/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:08:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 12:05:32 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	get_max(long long *stk)
{
	int	i;
	int	max;

	i = 0;
	max = -2147482648;
	while (stk[i] != STOP)
	{
		if (stk[i] > max)
			max = stk[i];
		++i;
	}
	return (max);
}

long long	get_min(long long *stk)
{
	int	i;
	int	min;

	i = 0;
	min = 2147483647;
	while (stk[i] != STOP)
	{
		if (stk[i] < min)
			min = stk[i];
		++i;
	}
	return (min);
}

int	get_direction(t_data data, long long *stk)
{
	int	i;
	int	j;
	int	len;

	len = stoplen(stk);
	j = 0;
	i = 0;
	while (j < len)
	{
		if (stk[len - j - 1] == data.stk2max \
		|| stk[len - j - 1] == data.stk2min)
			break ;
		j++;
	}
	while (stk[i] != STOP)
	{
		if (stk[i] == data.stk2max || stk[i] == data.stk2min)
			break ;
		i++;
	}
	if (j <= i)
		return (LEFT);
	return (RIGHT);
}

long long	stoplen(long long *stk)
{
	int	i;

	i = 0;
	while (stk[i] != STOP)
		i++;
	return (i);
}

void	cleanup(t_data data, int error)
{
	free(data.sorted);
	free(data.backup);
	free(data.stk1);
	free(data.stk2);
	free(data.trial);
	close(3);
	if (error)
		exit(1);
	exit(0);
}
