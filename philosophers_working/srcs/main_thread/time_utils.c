/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:38:17 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/27 15:52:57 by dpentlan         ###   ########.fr       */
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
		Bool function returns 0 is successfully waited for entire time_in_ms
			or 0 if wait was stopped early by philo dying.
*/

bool	ft_msleep(t_info *info, int time_in_ms)
{
	t_ms	finish_time;

	if (!info)
		usleep(time_in_ms);
	else
	{
		finish_time = ft_get_time() + time_in_ms;
		while(ft_get_time() < finish_time)
		{
			usleep(1000);
			if (ft_check_if_philo_dead(info))
				return (1);
		}
	}
	return (0);
}
