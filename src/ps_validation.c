/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:56:20 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/06 16:18:00 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		{
			ft_putstr_fd("Error\n", 2);
			return (false);
		}
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
		{
			ft_putstr_fd("Error\n", 2);
			return (false);
		}
		++i;
	}
	return (true);
}

t_bool	isarrayunique(long long *arr)
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
			{
				ft_putstr_fd("Error\n", 2);
				return (false);
			}
			++i;
		}
		++j;
		i = j + 1;
	}
	return (true);
}

void	validation(int argc, char **argv, t_data *data)
{
	if (isargvdigits(argc, argv) == false)
		cleanup(data, EXIT_FAILURE);
	if (isarrayint(data->stk1, argc) == false)
		cleanup(data, EXIT_FAILURE);
	if (isarrayunique(data->stk1) == false)
		cleanup(data, EXIT_FAILURE);
}
