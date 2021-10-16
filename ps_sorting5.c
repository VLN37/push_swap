/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:19:54 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/16 03:43:18 by jofelipe         ###   ########.fr       */
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

t_data	algo1(t_data data)
{
	data = split(data, &data.stack1, &data.stack2, stoplen(data.stack1));
	data = split2(data, &data.stack2, &data.stack1, stoplen(data.stack2));
	return (data);
}
