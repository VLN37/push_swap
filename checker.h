#ifndef CHECKER_H
# define CHECKER_H

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

#define STOP 2147483648

typedef struct s_data
{
	long long	*stk1;
	long long	*stk2;
	int			size;
	char		*str;
}	t_data;

void		push(long long *src, long long *dest);
void		swap(long long *stk);
void		rotate(long long *stk);
void		rev_rotate(long long *stk);
void		game(char *str, t_data *data);
void		cleanup(t_data *data, int error);
int			issorted(long long *stk);
long long	stoplen(long long *stk);
void		argvtoint(int argc, char **argv, t_data *data);



#endif
