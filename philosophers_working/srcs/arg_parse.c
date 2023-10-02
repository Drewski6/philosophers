/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:12:55 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/02 14:12:31 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_count(int argc)
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

static int	verify_arg(char *arg, int *arg_int_value)
{
	int	ret_int;

	if (verify_all_pos(arg))
		return (1);
	ret_int = ft_atoi(arg);
	if (ft_atoi_backcheck(arg, ret_int))
		return (1);
	else
		*arg_int_value = ret_int;
	return (0);
}

int	arg_parse(int argc, char **argv, t_args *args)
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
