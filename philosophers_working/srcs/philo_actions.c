/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/09 19:13:13 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	philo_eat(t_philo *philo)
{
	// pthread_mutex_lock(&philo->info->m_printf);
	// printf("philo #%d is eating\n", philo->id);
	// pthread_mutex_unlock(&philo->info->m_printf);
	pthread_mutex_lock(&philo->m_fork);
	msleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->m_fork);
	return ;
}

void	philo_sleep(t_philo *philo)
{
	(void) philo;
	msleep(philo->info->time_to_sleep);
	return ;
}

void	philo_wait(t_philo *philo)
{
	(void) philo;
	msleep(10);
	return ;
}

void	*pthread_entry_point(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_wait(philo);
	}
	return (0);
}
