/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:33:22 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/15 02:41:41 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	get_slice(t_data data)
{
	int	numbers_left;
	int	index;

	index = SLICE * data.currslice;
	if ((data.currslice + 1) * SLICE > data.nbr_count)
		numbers_left = data.nbr_count % SLICE;
	else
		numbers_left = SLICE;
	data.direction = get_direction(data);
	while (numbers_left)
	{
		if (data.stack1[0] >= data.sorted[index])
		{
			data = game("pb\n", data, &data.trialiter);
			data.direction = get_direction(data);
			--numbers_left;
		}
		else if (data.direction == LEFT)
			data = game("rra\n", data, &data.trialiter);
		else
			data = game("ra\n", data, &data.trialiter);
	}
	data.currslice--;
	return (data);
}

t_data	algo1(t_data data)
{
	int	i;

	i = 0;
	data.currslice = data.nbr_count / SLICE;
	data = get_slice(data);
	// printstacks(data);
	data = get_slice(data);
	// printstacks(data);
	// printf("here\n");

	return (data);
}
