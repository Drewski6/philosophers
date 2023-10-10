/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/10 15:48:15 by dpentlan         ###   ########.fr       */
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

void	*ft_pthread_entry_point(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		if (philo->dead)
			return (0);
		ft_philo_eat(philo);
		if (philo->dead)
			return (0);
		ft_philo_sleep(philo);
		if (philo->dead)
			return (0);
		ft_philo_wait(philo);
	}
	return (0);
}
