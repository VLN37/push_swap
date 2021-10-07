/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/07 15:56:52 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	init(int argc, char **argv, t_data data)
{
	data.nbr_count = argc - 1;
	printf("%d", data.nbr_count);
	data.stack1 = (long long*)malloc(sizeof(long long) * (data.nbr_count + 1));
	data.stack2 = (long long*)malloc(sizeof(long long) * (data.nbr_count + 1));
	data = argvtoint(argc, argv, data);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data data;

	data = init(argc, argv, data);
	if (!validation(argc, argv, data))
		return (1);
	int i = 0;
	while (data.stack1[i] != STOP)
		printf("%lld\n", data.stack1[i++]);
	cleanup(data, EXIT_SUCCESS);
}
