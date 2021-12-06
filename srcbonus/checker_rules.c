/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 06:45:53 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/06 12:43:06 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(long long *src, long long *dest)
{
	int	srclen;
	int	destlen;

	if (src[0] == STOP)
		return ;
	srclen = stoplen(src);
	destlen = stoplen(dest);
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
