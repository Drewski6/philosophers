/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:38:17 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/08 13:09:44 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ms	get_time(void)
{
	struct timeval	time;
	t_ms			time_ms;

	time_ms = 0;
	gettimeofday(&time, NULL);
	time_ms += time.tv_sec * 1000;
	time_ms += time.tv_usec / 1000;
	return (time_ms);
}

void	msleep(int time_in_ms)
{
	usleep(time_in_ms * 1000);
}
