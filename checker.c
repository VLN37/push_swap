/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 05:30:18 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/21 07:41:42 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init(t_data *data, int argc, char **argv)
{
	data->size = argc - 1;
	data->stk1 = (long long *)malloc(sizeof(long long) * (data->size + 1));
	data->stk2 = (long long *)malloc(sizeof(long long) * (data->size + 1));
	argvtoint(argc, argv, data);
}

void	cleanup(t_data *data, int error)
{
	free(data->stk1);
	free(data->stk2);
	free(data->str);
	free(data);
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else
	{
		ft_putstr_fd("OK\n", 1);
		exit(0);
	}
}

void	check(t_data *data)
{
	data->str = get_next_line(0);
	while (data->str)
	{
		game(data->str, data);
		free(data->str);
		data->str = get_next_line(0);
	}
	if (issorted(data->stk1) && (data->stk2)[0] == STOP)
		cleanup(data, EXIT_SUCCESS);
	else
		cleanup(data, EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	init(data, argc, argv);
	check(data);
}
