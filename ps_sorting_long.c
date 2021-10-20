/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:19:54 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 18:49:53 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_sorted(t_data *data, int from)
{
	if (from == 1)
	{
		game("ra\n", data);
		++data->sortedindex;
	}
	if (from == 2)
	{
		game("pa\n", data);
		game("ra\n", data);
		data->stk2min = get_min(data->stk2);
		data->stk2max = get_max(data->stk2);
		++data->sortedindex;
	}
}

void	return_to_a(t_data *data, long long **from, long long len)
{
	int			median;
	long long	*tmp;

	data->slice->threshold[++data->slice->i] = data->stk1[0];
	median = len / 2;
	data->stk2min = get_min(data->stk2);
	tmp = selection_sort(*from, len);
	while (len--)
	{
		if ((*from)[0] == data->stk2min)
			push_to_sorted(data, 2);
		if ((*from)[0] > tmp[median - 1])
			game("pa\n", data);
		else
			game("rb\n", data);
	}
	free(tmp);
}

void	initial_split(t_data *data, long long **from, long long len)
{
	int			median;
	long long	*tmp;

	median = len / 2;
	tmp = selection_sort(*from, len);
	while (len--)
	{
		if ((*from)[0] < tmp[median])
			game("pb\n", data);
		else
			game("ra\n", data);
	}
	free(tmp);
}

void	feed_b(t_data *data)
{
	if (data->slice->threshold[data->slice->i] == STOP)
	{
		while (data->stk1[0] != data->stkmin)
		{
			if (data->stk1[0] == data->sorted[data->sortedindex])
				push_to_sorted(data, 1);
			else
				game("pb\n", data);
		}
	}
	else
	{
		while (data->stk1[0] != data->slice->threshold[data->slice->i])
		{
			if (data->stk1[0] == data->sorted[data->sortedindex])
				push_to_sorted(data, 1);
			else
				game("pb\n", data);
		}
		--data->slice->i;
	}
}

void	push_to_a(t_data *data)
{
	int	i;

	i = 0;
	data->stk2min = get_min(data->stk2);
	data->stk2max = get_max(data->stk2);
	while (data->stk2[0] != STOP)
	{
		if (data->stk2[0] == data->stk2min)
			push_to_sorted(data, 2);
		else if (data->stk2[0] == data->stk2max)
		{
			game("pa\n", data);
			data->stk2max = get_max(data->stk2);
			++data->sortedindex;
			++i;
		}
		else
		{
			data->direction = get_direction(data, data->stk2);
			if (data->direction == RIGHT)
				game("rb\n", data);
			else
				game("rrb\n", data);
		}
	}
	while (i--)
		game("ra\n", data);
}

void	algo_long(t_data *data)
{
	if (issorted(data->stk1))
		return ;
	data->slice->threshold[data->slice->i] = STOP;
	initial_split(data, &data->stk1, stoplen(data->stk1));
	while (1)
	{
		if (issorted(data->stk1) && data->stk2[0] == STOP)
			break ;
		while (stoplen(data->stk2) > SLICE)
			return_to_a(data, &data->stk2, stoplen(data->stk2));
		while (data->stk2[0] != STOP)
			push_to_a(data);
		feed_b(data);
	}
}
