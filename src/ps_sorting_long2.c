/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_long2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:59:01 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 19:00:47 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
