/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 12:15:08 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	init(int argc, char **argv, t_data data, t_slice slice)
{
	dprintf(3, "%d\n", open("./log.txt", O_CREAT | O_RDWR, 0777));
	data.slice = &slice;
	slice.i = 0;
	data.sortedindex = 0;
	data.iter = 0;
	data.res = NULL;
	data.nbr_count = argc - 1;
	data.backup = (long long *)malloc(sizeof(long long) * (data.nbr_count + 1));
	data.stk1 = (long long *)malloc(sizeof(long long) * (data.nbr_count + 1));
	data.stk2 = (long long *)malloc(sizeof(long long) * (data.nbr_count + 1));
	data = argvtoint(argc, argv, data);
	data.sorted = selection_sort(data.stk1, stoplen(data.stk1));
	data.stkmed = get_median(data.stk1, stoplen(data.stk1));
	data.stkmin = get_min(data.stk1);
	data.stkmax = get_max(data.stk1);
	return (data);
}

void	printstacks(t_data data)
{
	int	i;

	i = 0;
	dprintf(3, "stk a\n");
	while (data.stk1[i] != STOP)
		dprintf(3, "%3lld ", data.stk1[i++]);
	dprintf(3, "\n");
	i = 0;
	dprintf(3, "stk b\n");
	while (data.stk2[i] != STOP)
		dprintf(3, "%3lld ", data.stk2[i++]);
	dprintf(3, "\n\n");
}

t_data	choose_algo(t_data data)
{
	if (data.nbr_count <= 11)
		data = algo_short(data);
	else
		data = algo_long(data);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_slice	slice;

	data = init(argc, argv, data, slice);
	validation(argc, argv, data);
	data = choose_algo(data);
	ft_putstr_fd(data.res, 1);
	ft_putnbr_fd(data.iter, 1);
	cleanup(data, EXIT_SUCCESS);
}
