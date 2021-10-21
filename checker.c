/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 05:30:18 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/21 11:54:56 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
