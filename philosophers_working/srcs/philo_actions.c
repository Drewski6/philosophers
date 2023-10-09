/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/09 22:24:21 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	ft_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_fork);
	ft_msleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->m_fork);
	return ;
}

void	ft_philo_sleep(t_philo *philo)
{
	(void) philo;
	ft_msleep(philo->info->time_to_sleep);
	return ;
}

void	ft_philo_wait(t_philo *philo)
{
	(void) philo;
	ft_msleep(10);
	return ;
}

void	*ft_pthread_entry_point(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		ft_philo_eat(philo);
		ft_philo_sleep(philo);
		ft_philo_wait(philo);
	}
	return (0);
}
