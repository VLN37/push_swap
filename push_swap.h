/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:13 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/12 23:35:09 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


typedef struct s_data
{
	long long	*backup;
	long long	*stack1;
	long long	*stack2;
	long long	stack1max;
	long long	stack2max;
	long long	stackmedian;
	int			nbr_count;
	char		*best;
	int			bestiter;
	char		*trial;
	int			trialiter;

}	t_data;

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef DEBUG
#  define DEBUG 0
# endif

# define STOP 2147483648

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int			validation(int argc, char **argv, t_data data);
t_data		argvtoint(int argc, char **argv, t_data data);
void		cleanup(t_data data, int error);
void		push(long long *src, long long *dest);
void		swap(long long *stack);
void		rotate(long long *stack);
void		rev_rotate(long long *stack);
t_data		bubble(t_data data);
void		printstacks(t_data data);
t_data		game(char *str, t_data data);
long long	stoplen(long long *stack);
void		reset(t_data *data);


#endif
