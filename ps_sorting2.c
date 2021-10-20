/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:09:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 10:10:45 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	sortb(t_data data)
{
	// printf("here\n");
	data.stack2max = get_max(data.stack2, &data.direction);
	while (1)
	{
		if (issorted_rev(data.stack2))
		{
			while (data.stack2[0] != STOP)
				data = game("pa\n", data, &data.trialiter);
			break ;
		}
		if (data.stack2[0] == data.stack2max)
		{
			data = game("pa\n", data, &data.trialiter);
			data.stack2max = get_max(data.stack2, &data.direction);
		}
		else if (data.stack2[0] == data.stackmin)
			data = game("rb\n", data, &data.trialiter);
		else if (data.stack2[0] < data.stack2[1])
			data = game("sb\n", data, &data.trialiter);
		else
			data = game("rb\n", data, &data.trialiter);
		if (DEBUG)
			printstacks(data);
	}
	return (data);
}

t_data	algo3(t_data data)
{
	data.stack1max = get_max(data.stack1, &data.direction);
	while (1)
	{
		if (issorted(data.stack1))
		{
			if (issorted_rev(data.stack2) && data.stack2[0] == STOP)
				break ;
			else
				data = sortb(data);
		}
		else if (data.stack1[0] == data.stack1max)
			data = game("ra\n", data, &data.trialiter);
		else if (data.stack1[0] > data.stack1[1])
			data = game("sa\n", data, &data.trialiter);
		else if (data.stack1[0] < data.stackmedian)
			data = game("pb\n", data, &data.trialiter);
		else
			data = game("ra\n", data, &data.trialiter);
		if (DEBUG)
			printstacks(data);
	}
	return (data);
}
