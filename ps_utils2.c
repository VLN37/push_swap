/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:14:36 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 11:13:36 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted_rev(long long *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (stack[i] != STOP)
	{
		while (stack[j] != STOP)
		{
			if (stack[i] < stack[j])
				return (0);
			else
				j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

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

static long long	get_relative_min(long long *stack, long long curr)
{
	long long	min;

	min = STOP;
	while (*stack != STOP)
	{
		if (*stack < min && *stack > curr)
			min = *stack;
		stack++;
	}
	return (min);
}

//returns a sorted array that needs to be freed
long long	*selection_sort(long long *arr, int len)
{
	long long	curr;
	long long	*ret;
	int			i;

	ret = malloc(sizeof(long long) * (len + 1));
	i = -1;
	curr = -2147483648;
	while (len--)
	{
		curr = get_relative_min(arr, curr);
		ret[++i] = curr;
	}
	ret[++i] = STOP;
	return (ret);
}

long long	get_median(long long *arr, int len)
{
	long long	ret;
	long long	*tmp;
	int			median;

	tmp = selection_sort(arr, len);
	ret = tmp[(len / 2) - 1];
	free(tmp);
	return (ret);
}
