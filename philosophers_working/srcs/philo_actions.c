/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/10 17:33:51 by dpentlan         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->info->m_printf);
	printf("%05ld %d is sleeping\n",
		ft_get_time() - philo->info->start_time, philo->id);
	pthread_mutex_unlock(&philo->info->m_printf);
	ft_msleep(philo->info->time_to_sleep);
	return ;
}

void	ft_philo_wait(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_printf);
	printf("%05ld %d is thinking\n",
		ft_get_time() - philo->info->start_time, philo->id);
	pthread_mutex_unlock(&philo->info->m_printf);
	usleep(10);
	return ;
}

static bool	ft_check_if_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_data);
	if (philo->dead)
		return (pthread_mutex_unlock(&philo->m_data), 1);
	else
		return (pthread_mutex_unlock(&philo->m_data), 0);
}

void	*ft_pthread_entry_point(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
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
		if (!philo->id % 2)
			ft_philo_wait(philo);
	}
	return (0);
}
