/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:12:55 by dpentlan          #+#    #+#             */
/*   Updated: 2023/07/11 22:22:56 by dpentlan         ###   ########.fr       */
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

int	verify_arg(char *arg, int *arg_int_value)
{
	int	ret_int;

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
			return (1);
		i++;
	}
	return (0);
}

int	print_args(t_args *args)
{
	printf("num_philo: %d\n", args->num_philo);
	printf("time_to_die: %d\n", args->time_to_die);
	printf("time_to_eat: %d\n", args->time_to_eat);
	printf("time_to_sleep: %d\n", args->time_to_sleep);
	printf("num_tt_eat: %d\n", args->num_tt_eat);
	return (0);
}
