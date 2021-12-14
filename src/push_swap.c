/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/07 19:40:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*init(int argc, char **argv, t_data *data)
{
	data->slice = (t_slice *)malloc(sizeof(t_slice));
	data->slice->i = 0;
	data->sortedindex = 0;
	data->iter = 0;
	data->res = NULL;
	data->size = argc - 1;
	data->backup = (long long *)malloc(sizeof(long long) * (data->size + 1));
	data->stk1 = (long long *)malloc(sizeof(long long) * (data->size + 1));
	data->stk2 = (long long *)malloc(sizeof(long long) * (data->size + 1));
	argvtoint(argc, argv, data);
	data->sorted = selection_sort(data->stk1, stoplen(data->stk1));
	data->stkmed = get_median(data->stk1, stoplen(data->stk1));
	data->stkmin = get_min(data->stk1);
	data->stkmax = get_max(data->stk1);
	return (data);
}

void	choose_algo(t_data *data)
{
	if (data->size <= 11)
		algo_short(data);
	else
		algo_long(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (EXIT_FAILURE);
	data = (t_data *)malloc(sizeof(t_data));
	init(argc, argv, data);
	validation(argc, argv, data);
	choose_algo(data);
	ft_putstr_fd(data->res, 1);
	cleanup(data, EXIT_SUCCESS);
}
