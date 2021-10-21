/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 06:46:12 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/21 06:50:00 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long long	stoplen(long long *stk)
{
	int	i;

	i = 0;
	while (stk[i] != STOP)
		i++;
	return (i);
}

int	issorted(long long *stk)
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
				return (0);
			else
				j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}
