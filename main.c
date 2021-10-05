/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/05 13:06:48 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit_str(char *str)
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

int	isargvdigits(int argc, char **argv)
{
	int	i;

	i = 2;

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

// int	isnegativevalid()

// int	isargvint(int argc, char **argv)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = ft_strlen(argv[i]);
// 	if(*argv[i] == '-')
// 	{
// 		if (len > 11)
// 			return (0);
// 		if (len == 11)

// 	}
// }

int	validation(int argc, char **argv)
{
	if (!isargvdigits(argc, argv))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	long long	*stack1 = (long long*)malloc(sizeof(long long) * 11 + 1);
	long long	*stack2 = (long long*)malloc(sizeof(long long) * 11 + 1);
	if (!validation(argc, argv))
		return (1);
	long int	i = -1;
	while (++i < 10)
	{
		stack1[i] = i;
	}
	stack1[i] = 2147483648;
	i = -1;
	while (++i < 11)
		printf("%lld\n", stack1[i]);
}
