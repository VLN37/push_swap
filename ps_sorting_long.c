/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:19:54 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 11:58:30 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	push_to_sorted(t_data data, int from)
{
	if (from == 1)
	{
		data = game("ra\n", data, &data.trialiter);
		++data.sortedindex;
	}
	if (from == 2)
	{
		data = game("pa\n", data, &data.trialiter);
		data = game("ra\n", data, &data.trialiter);
		data.stk2min = get_min(data.stack2);
		data.stk2max = get_max(data.stack2);
		++data.sortedindex;
	}
	return (data);
}

t_data	split2(t_data data, long long **from, long long **to, long long len)
{
	int			median;
	long long	*tmp;

	data.slice->threshold[++data.slice->i] = data.stack1[0];
	median = len / 2;
	data.stk2min = get_min(data.stack2);
	tmp = selection_sort(*from, len);
	while (len--)
	{
		if ((*from)[0] == data.stk2min)
			data = push_to_sorted(data, 2);
		if ((*from)[0] > tmp[median - 1])
			data = game("pa\n", data, &data.trialiter);
		else
			data = game("rb\n", data, &data.trialiter);
	}
	free(tmp);
	return (data);
}

t_data	split(t_data data, long long **from, long long **to, long long len)
{
	int			median;
	long long	*tmp;

	median = len / 2;
	tmp = selection_sort(*from, len);
	while (len--)
	{
		// if ((*from)[0] == data.sorted[data.sortedindex])
		// {
		// 	printf("%lld\n", data.sorted[data.sortedindex]);
		// 	data = push_to_sorted(data, 1);
		// 	++data.sortedindex;
		// 	len--;
		// }
		if ((*from)[0] < tmp[median - 1])
			data = game("pb\n", data, &data.trialiter);
		else
			data = game("ra\n", data, &data.trialiter);
	}
	free(tmp);
	return (data);
}

t_data	second_push(t_data data)
{
	if (data.slice->threshold[data.slice->i] == STOP)
	{
		while (data.stack1[0] != data.stkmin)
		{
			if (data.stack1[0] == data.sorted[data.sortedindex])
				data = push_to_sorted(data, 1);
			else
				data = game("pb\n", data, &data.trialiter);
		}
	}
	else
	{
		while (data.stack1[0] != data.slice->threshold[data.slice->i])
		{
			if (data.stack1[0] == data.sorted[data.sortedindex])
				data = push_to_sorted(data, 1);
			else
				data = game("pb\n", data, &data.trialiter);
		}
		--data.slice->i;
	}
	return (data);
}

t_data	push_to_a(t_data data)
{
	int	i;

	i = 0;
	data.stk2min = get_min(data.stack2);
	data.stk2max = get_max(data.stack2);
	while (data.stack2[0] != STOP)
	{
		if (data.stack2[0] == data.stk2min)
			data = push_to_sorted(data, 2);
		if (data.stack2[0] == data.stk2max)
		{
			data = game("pa\n", data, &data.trialiter);
			data.stk2max = get_max(data.stack2);
			++data.sortedindex;
			++i;
		}
		else
		{
			data.direction = get_direction(data, data.stack2);
			if (data.direction == RIGHT)
				data = game("rb\n", data, &data.trialiter);
			else
				data = game("rrb\n", data, &data.trialiter);
		}
	}
	while (i--)
		data = game("ra\n", data, &data.trialiter);
	return (data);
}

t_data	algo_long(t_data data)
{
	if (issorted(data.stack1))
		return (data);
	data.slice->threshold[data.slice->i] = STOP;
	data = split(data, &data.stack1, &data.stack2, stoplen(data.stack1));
	while (1)
	{
		if (issorted(data.stack1) && data.stack2[0] == STOP)
			break ;
		while (stoplen(data.stack2) > 26)
			data = split2(data, &data.stack2, &data.stack1, stoplen(data.stack2));
		while (data.stack2[0] != STOP)
			data = push_to_a(data);
		data = second_push(data);
	}
	return (data);
}
