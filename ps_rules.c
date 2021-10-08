/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:45:01 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/08 13:49:47 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	stoplen(long long *stack)
{
	int	i;

	i = 0;
	while (stack[i] != STOP)
		i++;
	return (i);
}

void	push(long long *src, long long *dest)
{
	int	srclen;
	int	destlen;

	srclen = stoplen(src);
	destlen = stoplen(dest);
	if (src[0] == STOP)
		return ;
	ft_memmove(&dest[1], dest, destlen * sizeof(long long));
	dest[0] = src[0];
	ft_memmove(src, &src[1], (srclen - 1) * sizeof(long long));
	src[srclen - 1] = STOP;
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

void	rotate(long long *stack)
{
	long long	holder;
	int			len;

	len = stoplen(stack);
	holder = stack[0];
	ft_memmove(stack, &stack[1], (len - 1) * sizeof(long long));
	stack[len - 1] = holder;
}

void	rev_rotate(long long *stack)
{
	long long	holder;
	int			len;

	len = stoplen(stack);
	holder = stack[len - 1];
	ft_memmove(&stack[1], stack, (len - 1) * sizeof(long long));
	stack[0] = holder;
}