/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:45:01 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 12:04:58 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	swap(long long *stk)
{
	long long	holder;

	if (stk[0] == STOP || stk[1] == STOP)
		return ;
	holder = stk[0];
	stk[0] = stk[1];
	stk[1] = holder;
}

void	rotate(long long *stk)
{
	long long	holder;
	int			len;

	len = stoplen(stk);
	if (len < 2)
		return ;
	holder = stk[0];
	ft_memmove(stk, &stk[1], (len - 1) * sizeof(long long));
	stk[len - 1] = holder;
}

void	rev_rotate(long long *stk)
{
	long long	holder;
	int			len;

	len = stoplen(stk);
	if (len < 2)
		return ;
	holder = stk[len - 1];
	ft_memmove(&stk[1], stk, (len - 1) * sizeof(long long));
	stk[0] = holder;
}
