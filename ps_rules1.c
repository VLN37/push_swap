/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:45:01 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/07 21:54:52 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stoplen(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != STOP)
		i++;
	return (i);
}

void	push(long long *src, long long *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (src[i] == STOP)
		return ;
	while(dest[j] != STOP)
		j++;
	ft_memmove(&dest[1], dest, j * sizeof(long long));
	dest[0] = src[0];
	while (src[i] != STOP)
		i++;
	ft_memmove(src, &src[1], (i - 1) * sizeof(long long));
	src[i - 1] = STOP;
}

void	swap(long long *stack)
{
	long long	holder;

	if (*stack == STOP)
		return ;
	holder = stack[0];
	stack[0] = stack[1];
	stack[1] = holder;
}
