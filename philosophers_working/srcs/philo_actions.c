/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/10 16:52:21 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	ft_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_printf);
	printf("philo #%d is eating.\n", philo->id);
	pthread_mutex_unlock(&philo->info->m_printf);
	ft_msleep(philo->info->time_to_eat);
	return ;
}

void	ft_philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_printf);
	printf("philo #%d is sleeping.\n", philo->id);
	pthread_mutex_unlock(&philo->info->m_printf);
	ft_msleep(philo->info->time_to_sleep);
	return ;
}

void	ft_philo_wait(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_printf);
	printf("philo #%d is waiting.\n", philo->id);
	pthread_mutex_unlock(&philo->info->m_printf);
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
		if (ft_check_if_philo_dead(philo))
			return (0);
		ft_philo_eat(philo);
		if (ft_check_if_philo_dead(philo))
			return (0);
		ft_philo_sleep(philo);
		if (ft_check_if_philo_dead(philo))
			return (0);
		ft_philo_wait(philo);
	}
	return (0);
}
