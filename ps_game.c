/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:29:37 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/13 23:10:16 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	game2(char *str, t_data data)
{
	if (!ft_strncmp(str, "rr\n", 3))
	{
		rotate(data.stack1);
		rotate(data.stack2);
		return (1);
	}
	else if (!ft_strncmp(str, "rrr\n", 4))
	{
		rev_rotate(data.stack1);
		rev_rotate(data.stack2);
		return (1);
	}
	else if (!ft_strncmp(str, "ss\n", 3))
	{
		swap(data.stack1);
		swap(data.stack2);
		return (1);
	}
	else
		return (0);
}

char *ft_realloc(char *old, char *append)
{
	char	*new;
	if (!old)
		old = ft_strdup("");
	new = ft_strjoin(old, append);
	free(old);
	return (new);
}

t_data	game(char *str, t_data data, int *iter)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap(data.stack1);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap(data.stack2);
	else if (!ft_strncmp(str, "pa\n", 3))
		push(data.stack2, data.stack1);
	else if (!ft_strncmp(str, "pb\n", 3))
		push(data.stack1, data.stack2);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate(data.stack1);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate(data.stack2);
	else if (!ft_strncmp(str, "rra\n", 4))
		rev_rotate(data.stack1);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rev_rotate(data.stack2);
	else if (!game2(str, data))
	{
		ft_putstr_fd("Command does not exist\n", 2);
		ft_putstr_fd("Error\n", 2);
		cleanup(data, EXIT_FAILURE);
	}
	data.trial = ft_realloc(data.trial, str);
	data.trialiter++;
	return (data);
}
