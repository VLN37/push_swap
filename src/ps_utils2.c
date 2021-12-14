/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:14:36 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/10 19:18:10 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	issorted_rev(long long *stk)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (stk[i] != STOP)
	{
		while (stk[j] != STOP)
		{
			if (stk[i] < stk[j])
				return (false);
			else
				j++;
		}
		i++;
		j = i + 1;
	}
	return (true);
}

t_bool	issorted(long long *stk)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (stk[i] != STOP)
	{
		while (stk[j] != STOP)
		{
			if (stk[i] > stk[j])
				return (false);
			else
				j++;
		}
		i++;
		j = i + 1;
	}
	return (true);
}

static long long	get_relative_min(long long *stk, long long curr)
{
	long long	min;

	min = (long long)STOP;
	while (*stk != STOP)
	{
		if (*stk < min && *stk > curr)
			min = *stk;
		stk++;
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
	ret[++i] = (long long)STOP;
	return (ret);
}

long long	get_median(long long *arr, int len)
{
	long long	ret;
	long long	*tmp;

	tmp = selection_sort(arr, len);
	if (len == 1)
	{
		ret = tmp[0];
		free(tmp);
		return (ret);
	}
	ret = tmp[(len / 2) - 1];
	free(tmp);
	return (ret);
}
