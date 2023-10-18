/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/18 11:56:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	ft_philo_eat(t_philo *philo)
{
	ft_grab_forks(philo);
	return ;
}

void	ft_philo_sleep(t_philo *philo)
{
	ft_m_printf(philo->info, "%05ld %d is sleeping\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_msleep(philo->info->time_to_sleep);
	return ;
}

void	ft_philo_wait(t_philo *philo)
{
	ft_m_printf(philo->info, "%05ld %d is thinking\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_msleep(1);
	//usleep(5);
	return ;
}

static bool	ft_check_if_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_info_data);
	if (philo->info->someone_died)
		return (pthread_mutex_unlock(&philo->info->m_info_data), 1);
	else
		return (pthread_mutex_unlock(&philo->info->m_info_data), 0);
}

/*
	NAME
		ft_pthread_entry_point
	DESCRIPTION
		Entry point for newly created threads.
	RETURN
		Only returns null pointer on completion.

// removed
	ft_set_philo_ready(philo, 1);
	while (!ft_everyone_ready(philo->info))
		usleep(5);
	while (1)

*/

void	*ft_pthread_entry_point(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&philo->info->m_ready);
	pthread_mutex_unlock(&philo->info->m_ready);
	while (1)
	{
		if (ft_check_if_philo_dead(philo))
			return (0);
		if (philo->id % 2)
			ft_philo_wait(philo);
		if (ft_check_if_philo_dead(philo))
			return (0);
		ft_philo_eat(philo);
		if (ft_check_if_philo_dead(philo))
			return (0);
		ft_philo_sleep(philo);
		if (ft_check_if_philo_dead(philo))
			return (0);
		if (!(philo->id % 2))
			ft_philo_wait(philo);
	}
	return (0);
}
