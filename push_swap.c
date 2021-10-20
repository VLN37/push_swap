/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 11:42:25 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	init(int argc, char **argv, t_data data, t_slice slice)
{
	dprintf(3, "%d\n", open("./log.txt", O_CREAT | O_RDWR, 0777));
	data.slice = &slice;
	slice.i = 0;
	data.sortedindex = 0;
	data.trialiter = 0;
	data.trial = NULL;
	data.nbr_count = argc - 1;
	data.backup = (long long *)malloc(sizeof(long long) * (data.nbr_count + 1));
	data.stack1 = (long long *)malloc(sizeof(long long) * (data.nbr_count + 1));
	data.stack2 = (long long *)malloc(sizeof(long long) * (data.nbr_count + 1));
	data = argvtoint(argc, argv, data);
	data.sorted = selection_sort(data.stack1, stoplen(data.stack1));
	data.stackmedian = get_median(data.stack1, stoplen(data.stack1));
	data.stackmin = get_min(data.stack1);
	data.stackmax = get_max(data.stack1);
	return (data);
}

void	printstacks(t_data data)
{
	int	i;

	i = 0;
	dprintf(3, "stack a\n");
	while (data.stack1[i] != STOP)
		dprintf(3, "%3lld ", data.stack1[i++]);
	dprintf(3, "\n");
	i = 0;
	dprintf(3, "stack b\n");
	while (data.stack2[i] != STOP)
		dprintf(3, "%3lld ", data.stack2[i++]);
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
	ft_putstr_fd(data.trial, 1);
	ft_putnbr_fd(data.trialiter, 1);
	cleanup(data, EXIT_SUCCESS);
}
