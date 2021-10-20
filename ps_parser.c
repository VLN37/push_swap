/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:35 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 12:03:38 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	argvtoint(int argc, char **argv, t_data data)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
	{
		data.stk1[i] = ftex_atoll(argv[i + 1]);
		data.backup[i] = data.stk1[i];
	}
	data.stk1[i] = (long long)STOP;
	data.backup[i] = data.stk1[i];
	i = -1;
	while (i < data.nbr_count)
		data.stk2[++i] = STOP;
	return (data);
}
