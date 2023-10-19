/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:12:55 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/19 15:29:11 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_arg_count(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Incorrect number of arguments.\n");
		return (1);
	}
	return (0);
}

static bool	ft_verify_all_pos(char *arg)
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

static bool	ft_edgecases(int *arg_int_value, int i)
{
	if (i == 1)
		if (*arg_int_value == 1)
			return (1);
	return (0);
}

static bool	ft_verify_arg(char *arg, int *arg_int_value)
{
	int	ret_int;

	if (ft_verify_all_pos(arg))
		return (1);
	ret_int = ft_atoi(arg);
	if (ft_atoi_backcheck(arg, ret_int))
		return (1);
	if (ret_int == 0)
		return (1);
	*arg_int_value = ret_int;
	return (0);
}

bool	ft_arg_parse(int argc, char **argv, t_info *info)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_verify_arg(argv[i], &((int *)info)[i - 1])
			|| ft_edgecases(&((int *)info)[i - 1], i))
		{
			printf("Error: Invalid arguments.\n");
			return (1);
		}
		i++;
	}
	return (0);
}
