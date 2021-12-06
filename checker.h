/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:58:08 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/06 12:25:10 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# define STOP 2147483648
# define EXIT_KO 2

typedef struct s_data
{
	long long	*stk1;
	long long	*stk2;
	int			size;
	char		*str;
	char		**instructions;
}	t_data;

void		push(long long *src, long long *dest);
void		swap(long long *stk);
void		rotate(long long *stk);
void		rev_rotate(long long *stk);
void		game(char *str, t_data *data);
void		cleanup(t_data *data, int error);
t_bool		issorted(long long *stk);
long long	stoplen(long long *stk);
void		parse_input(t_data *data);
void		argvtoint(int argc, char **argv, t_data *data);
void		validate_checker(t_data *data, int argc, char **argv);
void		init(t_data *data, int argc, char **argv);
void		read_input(t_data *data);
void		check(t_data *data);

#endif
