/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:38:17 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/09 22:22:07 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_msleep(int time_in_ms)
{
	usleep(time_in_ms * 1000);
}
