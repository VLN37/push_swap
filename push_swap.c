/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 10:56:40 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	init(int argc, char **argv, t_data data, t_slice slice)
{
	int		i;

	data.slice = &slice;
	slice.i = 0;
	data.sortedindex = 0;
	data.trial = NULL;
	data.best = NULL;
	data.trialiter = 0;
	data.y = 0;
	data.nbr_count = argc - 1;
	data.backup = (long long *)malloc(sizeof(long long) * (data.nbr_count + 1));
	data.stack1 = (long long *)malloc(sizeof(long long) * (data.nbr_count + 1));
	data.stack2 = (long long *)malloc(sizeof(long long) * (data.nbr_count + 1));
	data = argvtoint(argc, argv, data);
	i = 0;
	while (i <= data.nbr_count)
		data.stack2[i++] = STOP;
	data.sorted = selection_sort(data.stack1, stoplen(data.stack1));
	data.stackmedian = get_median(data.stack1, stoplen(data.stack1));
	data.stackmin = get_min(data.stack1);
	data.stackmax = get_max(data.stack1, &data.direction);
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

int	main(int argc, char **argv)
{
	t_data	data;
	t_slice	slice;

	int i;
	i = 0;
	 dprintf(3, "%d\n", open("./log.txt", O_CREAT | O_RDWR, 0777));
	data = init(argc, argv, data, slice);
	if (!validation(argc, argv, data))
		return (1);

	// data = algo1(data);

	else if (data.nbr_count <= 11)
		data = algo3(data);
	else
		data = algo1(data);

	// data = bubble(data);
	// printstacks(data);
	// reset(&data);
	// printstacks(data);
	// data = bubble(data);
	// printstacks(data);

	// printf("median = %lld\n", data.stackmedian);
	// printf("%d\n", data.trialiter);
	printf("%s", data.trial);
	cleanup(data, EXIT_SUCCESS);
}
