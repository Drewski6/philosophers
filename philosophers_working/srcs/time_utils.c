/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:38:17 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/07 15:30:42 by dpentlan         ###   ########.fr       */
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
