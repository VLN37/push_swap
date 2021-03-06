/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 05:37:12 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/06 23:00:41 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse_input(t_data *data)
{
	if (!data->str)
		return ;
	data->str = ftex_str_replace_all(data->str, "\n", "__0x69__");
	data->str = ftex_str_replace_all(data->str, "__0x69__", "\n$$$");
	data->instructions = ft_split(data->str, '$');
}

void	argvtoint(int argc, char **argv, t_data *data)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
		data->stk1[i] = ftex_atoll(argv[i + 1]);
	data->stk1[i] = (long long)STOP;
	i = -1;
	while (++i < data->size)
		data->stk2[i] = (long long)STOP;
}
