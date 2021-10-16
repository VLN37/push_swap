/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:33:22 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/15 06:03:38 by jofelipe         ###   ########.fr       */
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

int	get_push_direction(long long *stack, long long to_find)
{
	int	i;

	i = 0;
	while (stack[i] != to_find)
		i++;
	if (i > (stoplen(stack) / 2))
		return (LEFT);
	return (RIGHT);
}

t_data	push_to_stack_point(t_data data)
{
	if (data.stack2[0] == get_max2(data.stack2))
	{
		data.push = get_min(data.stack2);
		while (data.stack2[0] != STOP)
			data = game("pa\n", data, &data.trialiter);
	}
	else
	{
		if (get_push_direction(data.stack1, data.push) == LEFT)
			while (*data.stack1 != data.push)
				game("rra\n", data, &data.trialiter);
		else
			while (*data.stack1 != data.push)
				game("ra\n", data, &data.trialiter);
		data.push = get_min(data.stack2);
		while (data.stack2 != STOP)
			game("pa\n", data, &data.trialiter);
	}
	return (data);
}

// t_data	sortb(t_data data)
// {
// 	//printf("here\n");
// 	data.stack2max = get_max(data.stack2, &data.direction);
// 	while (1)
// 	{
// 		if (issorted_rev(data.stack2))
// 		{
// 			push_to_stack_point(data);
// 			break ;
// 		}
// 		if (data.stack2[0] == data.stack2max)
// 		{
// 			data = game("pa\n", data, &data.trialiter);
// 			get_direction(data, data.stack2);
// 			// printf("%d\n", data.direction);
// 		}
// 		else if (data.stack2[0] == data.stackmin && data.direction == RIGHT)
// 			data = game("rb\n", data, &data.trialiter);
// 		else if (data.stack2[0] == data.stackmin && data.direction == LEFT)
// 			data = game("rrb\n", data, &data.trialiter);
// 		else if (data.stack2[0] < data.stack2[1])
// 			data = game("sb\n", data, &data.trialiter);
// 		else if (data.direction == LEFT)
// 			data = game("rrb\n", data, &data.trialiter);
// 		else
// 			data = game("rb\n", data, &data.trialiter);
// 		if (DEBUG)
// 			printstacks(data);
// 	}
// 	return (data);

t_data	algo1(t_data data)
{
	int	i;

	i = 0;
	if (data.nbr_count > SLICE)
		data.currslice = data.nbr_count / SLICE;
	else
		data.currslice = 0;

	while (data.currslice != -1)
	{
		data = get_slice(data);
		printstacks(data);
	}
	// data = get_slice(data);
	// printstacks(data);
	// printf("here\n");

	return (data);
}
