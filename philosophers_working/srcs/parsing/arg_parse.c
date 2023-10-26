/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:12:55 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/26 15:05:22 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	NAME
		ft_str_all_digit
**	DESCRIPTION
		Takes a string and checks that all the characters are digits.
**	RETURN
		Bool function returns 1 if a character that is not a digit is found
		or 0 if every character is a digit.
*/

static bool	ft_str_all_digit(char *arg)
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

/*
**	NAME
		ft_edgecases
**	DESCRIPTION
		Specific to philosophers project. Searches arguments for ft_edgecases
		that are not allowed.
**	RETURN
		Bool function returns 1 if an edgecases if found: 0 if no edgecases
		are found.
*/

static bool	ft_edgecases(int *arg_int_value, int i)
{
	if (*arg_int_value == 0)
		return (1);
	(void) i;
	return (0);
}

/*
**	NAME
		ft_verify_arg
**	DESCRIPTION
		Receives an argument as char *arg and a pointer to a return integer.
		Checks that all characters in arg are digits,
		then runs through ft_atoi,
		then checks the ft_atoi return to make sure we did not run over,
		sets the return value.
**	RETURN
		Bool function returns 1 if error is found, or 0 on success.
*/

static bool	ft_verify_arg(char *arg, int *arg_int_value)
{
	int	ret_int;

	if (ft_str_all_digit(arg))
		return (1);
	ret_int = ft_atoi(arg);
	if (ft_atoi_backcheck(arg, ret_int))
		return (1);
	*arg_int_value = ret_int;
	return (0);
}

/*
**	NAME
		ft_arg_parse
**	DESCRIPTION
		Parses the arguments input by the user and checks for errors.
		Loops over each argument.
		- First ft_verify_arg checks if argument is all digits and an int.
		- Second ft_edgecases checks that none of the edgecases are met.
**	RETURN
		ret
*/

bool	ft_arg_parse(int argc, char **argv, t_info *info)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_verify_arg(argv[i], &((int *)info)[i - 1])
			|| ft_edgecases(&((int *)info)[i - 1], i))
			return (printf("Error: Invalid arguments.\n"), 1);
		i++;
	}
	return (0);
}
