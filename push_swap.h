/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:13 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 12:15:08 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_slice
{
	long long	threshold[50];
	int			i;
}	t_slice;

typedef struct s_data
{
	long long	*sorted;
	int			sortedindex;
	long long	*backup;
	long long	*stk1;
	long long	*stk2;
	long long	stk1max;
	long long	stk2max;
	long long	stk1min;
	long long	stk2min;
	long long	stkmin;
	long long	stkmax;
	long long	stkmed;
	int			direction;
	int			nbr_count;
	char		*res;
	int			iter;
	t_slice		*slice;
}	t_data;

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef DEBUG
#  define DEBUG 1
# endif

# define LEFT 0
# define RIGHT 1
# define STOP 2147483648

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void		push(long long *src, long long *dest);
void		swap(long long *stk);
void		rotate(long long *stk);
void		rev_rotate(long long *stk);
t_data		algo_long(t_data data);
t_data		algo_short(t_data data);
void		validation(int argc, char **argv, t_data data);
t_data		argvtoint(int argc, char **argv, t_data data);
t_data		game(char *str, t_data data, int *iter);
void		cleanup(t_data data, int error);
void		reset(t_data *data);
void		printstacks(t_data data);
long long	*selection_sort(long long *arr, int len);
long long	stoplen(long long *stk);
long long	get_min(long long *stk);
long long	get_median(long long *arr, int len);
long long	get_max(long long *stk);
int			get_direction(t_data data, long long *stk);
int			issorted(long long *stk);
int			issorted_rev(long long *stk);

#endif
