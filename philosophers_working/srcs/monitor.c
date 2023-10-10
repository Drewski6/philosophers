/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:20:15 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/10 17:51:22 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	ft_philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_printf);
	printf("%05ld %d has died\n",
		ft_get_time() - philo->info->start_time, philo->id);
	pthread_mutex_unlock(&philo->info->m_printf);
	return ;
}

/*
**	NAME
		ft_monitor
**	DESCRIPTION
		Used by the main thread to monitor the status of the philos' alive status
**	RETURN
		Void only returns in case where num_tt_eat is defined by user.
*/

bool	ft_monitor(t_info *info)
{
	int		i;

	(void) info;
	while (1)
	{
		i = 0;
		while (i < info->num_philo)
		{
			pthread_mutex_lock(&info->philos[i].m_data);
			if (ft_get_time() - info->philos[i].last_ate >= info->time_to_die)
				return (ft_philo_died(&info->philos[i]),
					pthread_mutex_unlock(&info->philos[i].m_data), 1);
			pthread_mutex_unlock(&info->philos[i].m_data);
			i++;
		}
	}
	return (0);
}
