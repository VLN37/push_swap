/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:35 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/07 13:09:47 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

long long *argvtoint(int argc, char **argv, long long *arr)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
		arr[i] = ftex_atoll(argv[i + 1]);
	arr[i] = 2147483648;
	return (arr);
}
