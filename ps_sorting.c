/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:25:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/09 20:49:18 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(long long *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (stack[i] != STOP)
	{
		while (stack[j] != STOP)
		{
			if (stack[i] > stack[j])
				return (0);
			else
				j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

long long	get_max(t_data data)
{
	int	i;

	i = 0;
	data.stack1max = 0;
	while (data.stack1[i] != STOP)
	{
		if (data.stack1[i] > data.stack1max)
			data.stack1max = data.stack1[i];
		++i;
	}
	return (data.stack1max);
}

t_data	bubble(t_data data)
{
	int	i;

	i = 0;
	data.stack1max = get_max(data);
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
	data.trialiter = i;
	return (data);
}

// long long getmedian(int *arr)
// {
// 	long long	*tmp;
// 	long long	stackmedian;
// 	int			i;

// 	i = stoplen(arr);
// 	tmp = (int *)malloc((i + 1) * sizeof(long long));
// 	ft_memcpy(tmp, arr, (i + 1) * sizeof(long long));

// }

// int	algo1(t_data data)
// {
// 	int	i;

// 	i = 0;
// 	data.stack1max = get_max(data);
// }
