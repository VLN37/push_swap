/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/08 13:45:30 by jofelipe         ###   ########.fr       */
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
	printf("stack 1\n");
	while (data.stack1[i] != STOP)
		printf("%3lld ", data.stack1[i++]);
	printf("\n");
	i = 0;
	printf("stack 2\n");
	while (data.stack2[i] != STOP)
		printf("%3lld ", data.stack2[i++]);
	printf("\n\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = init(argc, argv, data);
	if (!validation(argc, argv, data))
		return (1);
	printstacks(data);
	swap(data.stack1);
	printstacks(data);
	push(data.stack1, data.stack2);
	printstacks(data);
	rotate(data.stack1);
	printstacks(data);
	cleanup(data, EXIT_SUCCESS);
}
