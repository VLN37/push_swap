/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:33:22 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/15 04:03:44 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_slice_size(t_data data)
{
	int	size;

	if (data.nbr_count < SLICE)
		return (data.nbr_count);
	if ((data.currslice + 1) * SLICE > data.nbr_count)
		size = data.nbr_count % SLICE;
	else
		size = SLICE;
	if (data.nbr_count > SLICE && data.nbr_count % SLICE == 0)
		return (SLICE);
	data.direction = get_direction(data, data.stack1);
	return (size);
}

t_data	get_slice(t_data data)
{
	int	numbers_left;
	int	index;

	index = SLICE * data.currslice;
	numbers_left = get_slice_size(data);
	data.direction = get_direction(data, data.stack1);
	while (numbers_left)
	{
		if (data.stack1[0] > data.stack1[1] && data.stack2[0] < data.stack2[1] \
		&& data.stack2[0] != data.stackmin && data.stack1[0] < data.sorted \
		[index] && data.stack2[1] != STOP)
			data = game("ss\n", data, &data.trialiter);
		if (data.stack1[0] >= data.sorted[index])
		{
			data = game("pb\n", data, &data.trialiter);
			data.direction = get_direction(data, data.stack1);
			--numbers_left;
		}
		else if (data.direction == LEFT)
			data = game("rrr\n", data, &data.trialiter);
		else
			data = game("rr\n", data, &data.trialiter);
	}
	--data.currslice;
	return (data);
}

t_data	algo1(t_data data)
{
	int	i;

	i = 0;
	if (data.nbr_count > SLICE)
		data.currslice = data.nbr_count / SLICE;
	else
		data.currslice = 0;
	data = get_slice(data);

	// printstacks(data);
	// data = get_slice(data);
	// printstacks(data);
	// printf("here\n");

	return (data);
}
