/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:25:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/13 00:24:34 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	insertion_sort(t_data data)
{
	long long	tmp[data.nbr_count + 1];

	ft_memcpy(tmp, data.stack1, sizeof(long long) * (data.nbr_count + 1));

}

t_data algo1(t_data data)
{
	int	i;

	i = 0;
	data.stack1max = get_max(data.stack1);
	while (1)
	{
		if (data.stack1[0] == data.stack1max)
			game("ra\n", data);
		else if (data.stack1[0] > data.stack1[1])
			game("sa\n", data);
		else if (data.stack1[0] < data.stackmedian)
			game("pb\n", data);
		else
			game("ra\n", data);
	}
}

t_data	bubble(t_data data)
{
	int	i;

	i = 0;
	data.stack1max = get_max(data.stack1);
	while (++i)
	{
		if (issorted(data.stack1))
			break ;
		if (data.stack1[0] == data.stack1max)
			data = game("ra\n", data);
		else if (data.stack1[1] < data.stack1[0])
			data = game("sa\n", data);
		else
			data = game("ra\n", data);
		if (DEBUG)
			printstacks(data);
	}
	data.stackmedian = get_median(data.stack1);
	printf("median = %lld\n", data.stackmedian);
	data.trialiter = i;
	printf("iter = %i\n", data.trialiter);
	return (data);
}
