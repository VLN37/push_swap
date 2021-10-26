/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:01:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 18:55:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_new_metrics(t_data *data)
{
	game("pa\n", data);
	data->stk2max = get_max(data->stk2);
	data->direction = get_direction(data, data->stk2);
}

static void	sortb(t_data *data)
{
	data->stk2max = get_max(data->stk2);
	while (1)
	{
		if (issorted_rev(data->stk2))
		{
			while (data->stk2[0] != STOP)
				game("pa\n", data);
			break ;
		}
		if (data->stk2[0] == data->stk2max)
			get_new_metrics(data);
		else if (data->stk2[0] == data->stkmin && data->direction == RIGHT)
			game("rb\n", data);
		else if (data->stk2[0] == data->stkmin && data->direction == LEFT)
			game("rrb\n", data);
		else if (data->stk2[0] < data->stk2[1])
			game("sb\n", data);
		else if (data->direction == LEFT)
			game("rrb\n", data);
		else
			game("rb\n", data);
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
			game("ra\n", data);
		else if (data->stk1[0] > data->stk1[1] && \
		data->stk2[0] < data->stk2[1] && data->stk2[0] != data->stkmin)
			game("ss\n", data);
		else if (data->stk1[0] > data->stk1[1])
			game("sa\n", data);
		else if (data->stk1[0] <= data->stkmed)
			game("pb\n", data);
		else
			game("rr\n", data);
		if (DEBUG)
			printstacks(data);
	}
}
