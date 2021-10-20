/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:01:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 12:07:02 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	sortb(t_data data)
{
	data.stk2max = get_max(data.stk2);
	while (1)
	{
		if (issorted_rev(data.stk2))
		{
			while (data.stk2[0] != STOP)
				data = game("pa\n", data, &data.trialiter);
			break ;
		}
		if (data.stk2[0] == data.stk2max)
		{
			data = game("pa\n", data, &data.trialiter);
			data.stk2max = get_max(data.stk2);
			data.direction = get_direction(data, data.stk2);
		}
		else if (data.stk2[0] == data.stkmin && data.direction == RIGHT)
			data = game("rb\n", data, &data.trialiter);
		else if (data.stk2[0] == data.stkmin && data.direction == LEFT)
			data = game("rrb\n", data, &data.trialiter);
		else if (data.stk2[0] < data.stk2[1])
			data = game("sb\n", data, &data.trialiter);
		else if (data.direction == LEFT)
			data = game("rrb\n", data, &data.trialiter);
		else
			data = game("rb\n", data, &data.trialiter);
		if (DEBUG)
			printstacks(data);
	}
	return (data);
}

t_data	algo_short(t_data data)
{
	data.stkmin = get_min(data.stk1);
	data.stk1max = get_max(data.stk1);
	while (1)
	{
		if (issorted(data.stk1))
		{
			if (issorted_rev(data.stk2) && data.stk2[0] == STOP)
				break ;
			else
				data = sortb(data);
		}
		else if (data.stk1[0] == data.stk1max)
			data = game("ra\n", data, &data.trialiter);
		else if (data.stk1[0] > data.stk1[1] && \
		data.stk2[0] < data.stk2[1] && data.stk2[0] != data.stkmin)
			data = game("ss\n", data, &data.trialiter);
		else if (data.stk1[0] > data.stk1[1])
			data = game("sa\n", data, &data.trialiter);
		else if (data.stk1[0] <= data.stkmed)
			data = game("pb\n", data, &data.trialiter);
		else
			data = game("rr\n", data, &data.trialiter);
		if (DEBUG)
			printstacks(data);
	}
	return (data);
}
