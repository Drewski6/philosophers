/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:20:15 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/17 16:02:56 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	ft_philo_died(t_philo *philo)
{
	ft_m_printf(philo->info, "%05ld %d died\n",
		ft_get_time() - philo->info->start_time, philo->id);
	//printf("someone_died %d\n", philo->info->someone_died);
	pthread_mutex_lock(&philo->info->m_info_data);
	philo->info->someone_died = 1;
	pthread_mutex_unlock(&philo->info->m_info_data);
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

	while (!ft_everyone_ready(info))
		usleep(5);
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
