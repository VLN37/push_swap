/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/07 12:58:16 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	long long	*stack1 = (long long*)malloc(sizeof(long long) * 11 + 1);
	long long	*stack2 = (long long*)malloc(sizeof(long long) * 11 + 1);

	stack1 = argvtoint(argc, argv, stack1);
	if (!validation(argc, argv, stack1))
		return (1);

	int i = 0;
	while (stack1[i] != STOP)
		printf("%lld\n", stack1[i++]);
}
