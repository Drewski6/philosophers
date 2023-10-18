/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:35:38 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/09 22:26:24 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(char *)str = 0;
		str++;
		i++;
	}
}

/*	
**	The ft_atoi function returns an int or 0 on error. 
**	But if the input is '0' then its imposible to tell there was an error or not.
**	This function double checks the input and return from ft_atoi to make sure the
**	output is the expected output.
**	This avoids ambiguity in the 0 return from ft_atoi.
**/

bool	ft_atoi_backcheck(char *s_num, int num)
{
	int	i;

	i = 0;
	while (*s_num == 32 || *s_num == '\f' || *s_num == '\n'
		|| *s_num == '\r' || *s_num == '\t' || *s_num == '\v'
		|| *s_num == '+' || *s_num == '-')
		s_num++;
	while (s_num[i])
		i++;
	if (i == 0)
		return (1);
	if (num == -2147483648 && i != 10)
		return (1);
	if (num < 0)
		num *= -1;
	while (i > 0)
	{
		if ((num % 10) + 48 != s_num[i - 1])
			return (1);
		num /= 10;
		i--;
	}
	return (0);
}

/*  *** int_build (integer build) ***
 *
 *  Takes a string of ascii numerical characters and builds an integer
 *  of the same value.
 *  Returns integer representation of input string.
 */

static int	ft_int_build(char *str)
{
	int	ret_int;

	ret_int = 0;
	while (*str >= '0' && *str <= '9')
	{
		ret_int += *str - '0';
		if (str[1] >= '0' && str[1] <= '9')
			ret_int *= 10;
		str++;
	}
	return (ret_int);
}

/*  *** ft_atoi (42 ascii to integer) ***
 *
 *  Takes a string with ascii numbers, spaces or a single '+' or '-' sign.
 *  Returns a signed integer representation of of the string entered.
 */

int	ft_atoi(const char *nptr)
{
	int	mult;

	mult = 1;
	while (*nptr == 32 || *nptr == '\f' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '-' || *nptr == 43)
	{
		if (*nptr == '-')
			mult *= -1;
		nptr++;
	}
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			return (ft_int_build((char *)nptr) * mult);
		else
			return (0);
	}
	return (0);
}

/*  *** ft_isdigit (42 is digit) ***
 *
 *  Takes an integer value for ascii character.
 *  returns 1 if the character is a digit character.
 *  returns 0 if the character is not a digit character.
 */

bool	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
