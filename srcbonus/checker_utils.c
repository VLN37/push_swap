/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 06:46:12 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/06 12:19:27 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long long	stoplen(long long *stk)
{
	int	i;

	i = 0;
	while (stk[i] != STOP)
		i++;
	return (i);
}

t_bool	issorted(long long *stk)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (stk[i] != STOP)
	{
		while (stk[j] != STOP)
		{
			if (stk[i] > stk[j])
				return (false);
			else
				j++;
		}
		i++;
		j = i + 1;
	}
	return (true);
}

void	init(t_data *data, int argc, char **argv)
{
	data->str = NULL;
	data->instructions = NULL;
	data->size = argc - 1;
	data->stk1 = (long long *)malloc(sizeof(long long) * (data->size + 1));
	data->stk2 = (long long *)malloc(sizeof(long long) * (data->size + 1));
	argvtoint(argc, argv, data);
}

void	cleanup(t_data *data, int error)
{
	int	i;

	i = -1;
	if (data->instructions)
		while (data->instructions[++i])
			free(data->instructions[i]);
	free(data->instructions);
	free(data->stk1);
	free(data->stk2);
	free(data->str);
	free(data);
	if (error == EXIT_KO)
		ft_putstr_fd("KO\n", 1);
	else if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	else
		ft_putstr_fd("OK\n", 1);
	exit(EXIT_SUCCESS);
}
