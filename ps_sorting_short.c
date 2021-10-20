/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:01:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 17:02:36 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortb(t_data *data)
{
	data->stk2max = get_max(data->stk2);
	while (1)
	{
		if (issorted_rev(data->stk2))
		{
			while (data->stk2[0] != STOP)
				game("pa\n", data, &data->iter);
			break ;
		}
		if (data->stk2[0] == data->stk2max)
		{
			game("pa\n", data, &data->iter);
			data->stk2max = get_max(data->stk2);
			data->direction = get_direction(data, data->stk2);
		}
		else if (data->stk2[0] == data->stkmin && data->direction == RIGHT)
			game("rb\n", data, &data->iter);
		else if (data->stk2[0] == data->stkmin && data->direction == LEFT)
			game("rrb\n", data, &data->iter);
		else if (data->stk2[0] < data->stk2[1])
			game("sb\n", data, &data->iter);
		else if (data->direction == LEFT)
			game("rrb\n", data, &data->iter);
		else
			game("rb\n", data, &data->iter);
		if (DEBUG)
			printstacks(data);
	}
}

void	algo_short(t_data *data)
{
	data->stkmin = get_min(data->stk1);
	data->stk1max = get_max(data->stk1);
	while (1)
	{
		if (issorted(data->stk1))
		{
			if (issorted_rev(data->stk2) && data->stk2[0] == STOP)
				break ;
			else
				sortb(data);
		}
		else if (data->stk1[0] == data->stk1max)
			game("ra\n", data, &data->iter);
		else if (data->stk1[0] > data->stk1[1] && \
		data->stk2[0] < data->stk2[1] && data->stk2[0] != data->stkmin)
			game("ss\n", data, &data->iter);
		else if (data->stk1[0] > data->stk1[1])
			game("sa\n", data, &data->iter);
		else if (data->stk1[0] <= data->stkmed)
			game("pb\n", data, &data->iter);
		else
			game("rr\n", data, &data->iter);
		if (DEBUG)
			printstacks(data);
	}
}
