/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:54:08 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/06 12:13:51 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_bool	is_input_valid(char *str)
{
	if (!ft_strncmp(str, "sa\n", 10) || !ft_strncmp(str, "sb\n", 10))
		return (true);
	else if (!ft_strncmp(str, "ra\n", 10) || !ft_strncmp(str, "rb\n", 10))
		return (true);
	else if (!ft_strncmp(str, "pa\n", 10) || !ft_strncmp(str, "pb\n", 10))
		return (true);
	else if (!ft_strncmp(str, "rra\n", 10) || !ft_strncmp(str, "rrb\n", 10))
		return (true);
	else if (!ft_strncmp(str, "rr\n", 10) || !ft_strncmp(str, "ss\n", 10))
		return (true);
	else if (!ft_strncmp(str, "rrr\n", 10))
		return (true);
	else
		return (false);
}

void	read_input(t_data *data)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		if (is_input_valid(str) == false)
		{
			free(str);
			cleanup(data, EXIT_FAILURE);
		}
		if (ft_strncmp("dowhile", str, 10) && str)
			data->str = ftex_strmerge(data->str, str);
		str = get_next_line(STDIN_FILENO);
	}
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
