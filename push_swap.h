/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:13:13 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/16 02:16:33 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_data
{
	long long	*sorted;
	long long	*backup;
	long long	*stack1;
	long long	*stack2;
	long long	stack1max;
	long long	stack2max;
	long long	stackmin;
	long long	stackmax;
	long long	stackmedian;
	long long	push;
	int			currslice;
	int			direction;
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

# define LEFT 0
# define RIGHT 1

# ifndef DEBUG
#  define DEBUG 0
# endif

# define STOP 2147483648
# define SLICE 25

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void		push(long long *src, long long *dest);
void		swap(long long *stack);
void		rotate(long long *stack);
void		rev_rotate(long long *stack);
int			validation(int argc, char **argv, t_data data);
t_data		argvtoint(int argc, char **argv, t_data data);
t_data		game(char *str, t_data data, int *iter);
void		cleanup(t_data data, int error);
t_data		bubble(t_data data);
void		printstacks(t_data data);
long long	*selection_sort(long long *arr, int len);
void		reset(t_data *data);
long long	stoplen(long long *stack);
long long	get_min(long long *stack);
long long	get_median(long long *arr, int len);
long long	get_max(long long *stack, int *direction);
long long	get_max_two(long long *stack);
int			get_direction(t_data data, long long *stack);
int			issorted(long long *stack);
int			issorted_rev(long long *stack);
t_data		algo1(t_data data);

#endif
