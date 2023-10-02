/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:12:55 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/02 14:53:25 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	arg_count(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Incorrect number of arguments.\n");
		return (1);
	}
	return (0);
}

static bool	verify_all_pos(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

static bool	verify_arg(char *arg, int *arg_int_value)
{
	int	ret_int;

	if (verify_all_pos(arg))
		return (1);
	ret_int = ft_atoi(arg);
	if (ft_atoi_backcheck(arg, ret_int))
		return (1);
	if (ret_int == 0)
		return (1);
	*arg_int_value = ret_int;
	return (0);
}

bool	arg_parse(int argc, char **argv, t_args *args)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (verify_arg(argv[i], &((int *)args)[i - 1]))
		{
			printf("Error: Invalid arguments.\n");
			return (1);
		}
		i++;
	}
	return (0);
}
