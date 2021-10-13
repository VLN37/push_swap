/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:08:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/12 22:50:31 by jofelipe         ###   ########.fr       */
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

void	cleanup(t_data data, int error)
{
	free(data.backup);
	free(data.stack1);
	free(data.stack2);
	free(data.trial);
	close(3);
	if (error)
		exit(1);
	exit(0);
}
