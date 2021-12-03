/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:44:17 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/03 11:25:15 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_isdigit_str(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

static int	isargvdigits(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isdigit_str(argv[i++]))
			return (0);
	}
	return (1);
}

static int	isarrayint(long long *arr, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (arr[i] > (long long)INT_MAX || arr[i] < (long long)INT_MIN)
			return (0);
		++i;
	}
	return (1);
}

static int	isarrayunique(long long *arr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arr[j] != STOP)
	{
		while (arr[i] != STOP)
		{
			if (arr[j] == arr[i])
				return (0);
			++i;
		}
		++j;
		i = j + 1;
	}
	return (1);
}

void	validate_checker(t_data *data, int argc, char **argv)
{
	if (!isargvdigits(argc, argv))
		cleanup(data, EXIT_FAILURE);
	if (!isarrayint(data->stk1, argc))
		cleanup(data, EXIT_FAILURE);
	if (!isarrayunique(data->stk1))
		cleanup(data, EXIT_FAILURE);
}
