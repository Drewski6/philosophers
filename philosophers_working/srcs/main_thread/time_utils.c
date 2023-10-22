/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:38:17 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/22 22:48:16 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	NAME
		ft_get_time
**	DESCRIPTION
		Uses the gettimeofday function to get the current time.
		This time is given to us in a struct so we return a t_ms type.
		t_ms stands for type_milliseconds and represents the current time in
		milliseconds.
**	RETURN
		Returns the current time as a t_ms type (long int).
*/

t_ms	ft_get_time(void)
{
	struct timeval	time;
	t_ms			time_ms;

	time_ms = 0;
	gettimeofday(&time, NULL);
	time_ms += time.tv_sec * 1000;
	time_ms += time.tv_usec / 1000;
	return (time_ms);
}

/*
**	NAME
		ft_msleep
**	DESCRIPTION
		Uses usleep and waits for integer amount of time.
		Takes integer time and waits for 1 millisecond * int time_in_ms
**	RETURN
		Void function does not return a value.
*/

void	ft_msleep(int time_in_ms)
{
	usleep(time_in_ms * 1000);
}
