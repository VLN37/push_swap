/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/05 10:18:10 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	long int	*arr = (long int*)malloc(sizeof(long int) * 10 + 1);

	long int	i = -1;
	while (++i < 10)
	{
		arr[i] = i;
	}
	arr[i] = 2147483648;
	i = -1;
	while (++i < 11)
		printf("%ld\n", arr[i]);

}
