/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:19:54 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/18 10:11:24 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	split2(t_data data, long long **from, long long **to, long long len)
{
	int			median;
	long long	*tmp;

	median = len / 2;
	tmp = selection_sort(*from, len);
	while (len--)
	{
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
		if ((*from)[0] < tmp[median - 1])
			data = game("pb\n", data, &data.trialiter);
		else
			data = game("ra\n", data, &data.trialiter);
	}
	free(tmp);
	return (data);
}

t_data second_push(t_data data)
{
	while (data.stack1[0] != data.stackmin)
		data = game("pb\n", data, &data.trialiter);
	return (data);
}

t_data	push_to_a(t_data data)
{
	int	i;

	i = 0;
	data.stack2min = get_min(data.stack2);
	data.stack2max = get_max2(data.stack2);
	while (data.stack2[0] != STOP)
	{
		data.direction = get_direction(data, data.stack2);
		if (data.stack2[0] == data.stack2min)
		{
			data = game("pa\n", data, &data.trialiter);
			data = game("ra\n", data, &data.trialiter);
			data.stack2min = get_min(data.stack2);
		}
		if (data.stack2[0] == data.stack2max)
		{
			data = game("pa\n", data, &data.trialiter);
			data.stack2max = get_max2(data.stack2);
			i++;
		}
		else
		{
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

t_data	algo1(t_data data)
{
	int	min;
	int	max;

	data = split(data, &data.stack1, &data.stack2, stoplen(data.stack1));
	min = data.stack1[0];
	max = get_max(data.stack1, &data.direction);
	data = split2(data, &data.stack2, &data.stack1, stoplen(data.stack2));
	data = push_to_a(data);
	while (*data.stack1 != min)
		data = game("pb\n", data, &data.trialiter);
	data = push_to_a(data);
	data = second_push(data);
	data = split2(data, &data.stack2, &data.stack1, stoplen(data.stack2));
	data = push_to_a(data);
	data = second_push(data);
	data = push_to_a(data);
	return (data);
}
