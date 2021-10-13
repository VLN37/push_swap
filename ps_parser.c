/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:35 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/12 22:49:55 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	argvtoint(int argc, char **argv, t_data data)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
	{
		data.stack1[i] = ftex_atoll(argv[i + 1]);
		data.backup[i] = data.stack1[i];
	}
	data.stack1[i] = (long long)STOP;
	data.backup[i] = data.stack1[i];
	return (data);
}
