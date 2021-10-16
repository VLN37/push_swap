/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:25:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/16 02:19:22 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_data	bubble(t_data data)
{
	data.stack1max = get_max(data.stack1, &data.direction);
	while (1)
	{
		if (issorted(data.stack1))
			break ;
		if (data.stack1[0] == data.stack1max)
			data = game("ra\n", data, &data.trialiter);
		else if (data.stack1[1] < data.stack1[0])
			data = game("sa\n", data, &data.trialiter);
		else
			data = game("ra\n", data, &data.trialiter);
		if (DEBUG)
			printstacks(data);
	}
	printf("iter = %i\n", data.trialiter);
	return (data);
}
