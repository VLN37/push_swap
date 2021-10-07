/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:13 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/07 15:38:10 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_data
{
	long long	*stack1;
	long long	*stack2;
	int			nbr_count;
}	t_data;

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# define STOP 2147483648

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	validation(int argc, char **argv, t_data data);
t_data argvtoint(int argc, char **argv, t_data data);
void cleanup(t_data data, int error);

#endif
