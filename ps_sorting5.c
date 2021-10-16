/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:19:54 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/16 01:54:15 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	split(t_data data)
{
	int	i;

	i = data.nbr_count;
	printf("%d\n", data.nbr_count);
	printf("%d\n", data.stackmedian);
	while (i--)
	{
		if (data.stack1[0] > data.sorted[data.stackmedian])
			data = game("pb\n", data, &data.trialiter);
		else
			data = game("ra\n", data, &data.trialiter);
	}
	return (data);
}

t_data	algo1(t_data data)
{
	data = split(data);

	return (data);
}
