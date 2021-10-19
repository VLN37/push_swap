/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:14:36 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/18 09:55:19 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_direction(t_data data, long long *stack)
{
	int	i;
	int	j;
	int	len;

	len = stoplen(stack);
	j = 0;
	i = 0;
	while (j < len)
	{
		if (stack[len - j - 1] == data.stack2max || stack[len - j - 1] == data.stack2min)
			break;
		j++;

	}
	while (stack[i] != STOP)
	{
		if (stack[i] == data.stack2max || stack[i] == data.stack2min)
			break ;
		i++;
	}
	if (j < i)
		return (LEFT);
	return (RIGHT);
}

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

long long	get_relative_min(long long *stack, long long curr)
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
	// for (int j = 0; ret[j] != STOP; j++)
	// 	printf("%lld ", ret[j]);
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
