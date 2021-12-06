/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:44:17 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/06 12:27:04 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_bool	ft_isdigit_str(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (false);
	return (true);
}

static t_bool	isargvdigits(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isdigit_str(argv[i++]))
			return (false);
	}
	return (true);
}

static t_bool	isarrayint(long long *arr, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (arr[i] > (long long)INT_MAX || arr[i] < (long long)INT_MIN)
			return (false);
		++i;
	}
	return (true);
}

static t_bool	isarrayunique(long long *arr)
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
				return (false);
			++i;
		}
		++j;
		i = j + 1;
	}
	return (true);
}

void	validate_checker(t_data *data, int argc, char **argv)
{
	if (isargvdigits(argc, argv) == false)
		cleanup(data, EXIT_FAILURE);
	if (isarrayint(data->stk1, argc) == false)
		cleanup(data, EXIT_FAILURE);
	if (isarrayunique(data->stk1) == false)
		cleanup(data, EXIT_FAILURE);
}
