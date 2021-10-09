/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/09 15:43:31 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	init(int argc, char **argv, t_data data)
{
	int	i;

	data.nbr_count = argc - 1;
	data.stack1 = (long long *)malloc(sizeof(long long) * (data.nbr_count + 1));
	data.stack2 = (long long *)malloc(sizeof(long long) * (data.nbr_count + 1));
	data = argvtoint(argc, argv, data);
	i = 0;
	while (i < data.nbr_count)
		data.stack2[i++] = STOP;
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
	// i = 0;
	// dprintf(3, "stack b\n");
	// while (data.stack2[i] != STOP)
	// 	dprintf(3, "%3lld ", data.stack2[i++]);
	dprintf(3, "\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	dprintf(3, "%d\n", open("./log.txt", O_CREAT | O_RDWR));
	data = init(argc, argv, data);
	if (!validation(argc, argv, data))
		return (1);
	dprintf(3, "%d\n", bubble(data));
	cleanup(data, EXIT_SUCCESS);
}
