/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:29:37 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/22 21:29:10 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	game2(char *str, t_data *data)
{
	if (!ft_strncmp(str, "rr\n", 3))
	{
		rotate(data->stk1);
		rotate(data->stk2);
		return (1);
	}
	else if (!ft_strncmp(str, "rrr\n", 4))
	{
		rev_rotate(data->stk1);
		rev_rotate(data->stk2);
		return (1);
	}
	else if (!ft_strncmp(str, "ss\n", 3))
	{
		swap(data->stk1);
		swap(data->stk2);
		return (1);
	}
	else
		return (0);
}

void	game(char *str, t_data *data)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap(data->stk1);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap(data->stk2);
	else if (!ft_strncmp(str, "pa\n", 3))
		push(data->stk2, data->stk1);
	else if (!ft_strncmp(str, "pb\n", 3))
		push(data->stk1, data->stk2);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate(data->stk1);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate(data->stk2);
	else if (!ft_strncmp(str, "rra\n", 4))
		rev_rotate(data->stk1);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rev_rotate(data->stk2);
	else if (!game2(str, data))
	{
		ft_putstr_fd("Error\n", 2);
		cleanup(data, EXIT_FAILURE);
	}
	data->res = ftex_strmerge(data->res, ft_strdup(str));
	data->iter++;
	if (DEBUG)
		printstacks(data);
}
