/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:56:20 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/08 14:26:58 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
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
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	return (1);
}

static int	isarrayint(long long *arr, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
		{
			printf("%lld\n", arr[i]);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		++i;
	}
	return (1);
}

int	isarrayunique(long long *arr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arr[j] != STOP)
	{
		while(arr[i] != STOP)
		{
			if (arr[j] == arr[i])
			{
				ft_putstr_fd("Duplicate found\n", 2);
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			++i;
		}
		++j;
		i = j + 1;
	}
	return (1);
}

int	validation(int argc, char **argv, t_data data)
{
	if (!isargvdigits(argc, argv))
		return (0);
	if (!isarrayint(data.stack1, argc))
		return (0);
	if (!isarrayunique(data.stack1))
		return (0);
	return (1);
}
