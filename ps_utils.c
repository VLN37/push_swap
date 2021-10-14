/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:08:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/14 01:00:00 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
