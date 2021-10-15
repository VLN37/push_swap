/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:08:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/15 02:37:25 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_direction(t_data data)
{
	int	i;
	int	j;
	int	len;

	len = stoplen(data.stack1);
	j = 0;
	i = 0;
	while (j < len)
	{
		if (data.stack1[len - j] >= data.sorted[data.currslice * SLICE])
			break;
		j++;

	}
	while (data.stack1[i] != STOP)
	{
		if (data.stack1[i] >= data.sorted[(data.currslice * SLICE)])
			break ;
		i++;
	}
	if (j < i)
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
	free(data.backup);
	free(data.stack1);
	free(data.stack2);
	free(data.trial);
	close(3);
	if (error)
		exit(1);
	exit(0);
}
