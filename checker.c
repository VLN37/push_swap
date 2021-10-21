/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 05:30:18 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/21 11:38:44 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init(t_data *data, int argc, char **argv)
{
	// data->instructions = NULL;
	// data->instructions[0] = NULL;
	data->str = NULL;
	data->size = argc - 1;
	data->stk1 = (long long *)malloc(sizeof(long long) * (data->size + 1));
	data->stk2 = (long long *)malloc(sizeof(long long) * (data->size + 1));
	argvtoint(argc, argv, data);
}

void	cleanup(t_data *data, int error)
{
	free(data->stk1);
	free(data->stk2);
	free(data->str);
	free(data);
	if (error == EXIT_KO)
		ft_putstr_fd("KO\n", 1);
	else if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else
		ft_putstr_fd("OK\n", 1);
	exit(0);
}

void	check(t_data *data)
{
	int	i;

	i = -1;
	if (data->instructions)
		while (data->instructions[++i])
			game(data->instructions[i], data);
	if (issorted(data->stk1) && (data->stk2)[0] == STOP)
		cleanup(data, EXIT_SUCCESS);
	else
		cleanup(data, EXIT_KO);
}

int	is_input_valid(char *str)
{
	if (!ft_strncmp(str, "sa\n", 10) || !ft_strncmp(str, "sb\n", 10))
		return (1);
	else if (!ft_strncmp(str, "ra\n", 10) || !ft_strncmp(str, "rb\n", 10))
		return (1);
	else if (!ft_strncmp(str, "pa\n", 10) || !ft_strncmp(str, "pb\n", 10))
		return (1);
	else if (!ft_strncmp(str, "rra\n", 10) || !ft_strncmp(str, "rrb\n", 10))
		return (1);
	else if (!ft_strncmp(str, "rr\n", 10) || !ft_strncmp(str, "ss\n", 10))
		return (1);
	else if (!ft_strncmp(str, "rrr\n", 10))
		return (1);
	else
		return (0);
}

void read_input(t_data *data)
{
	char *str;

	str = get_next_line(0);
	while (str)
	{
		if (!is_input_valid(str))
		{
			free(str);
			cleanup(data, EXIT_FAILURE);
		}
		if (ft_strncmp("dowhile", str, 10) && str)
		{
			data->str = ftex_strmerge(data->str, str);
			free(str);
		}
		str = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	init(data, argc, argv);
	validate_checker(data, argc, argv);
	read_input(data);
	parse_input(data);
	check(data);
}
