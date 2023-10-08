/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/08 13:17:27 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	philo_eat(t_philo *philo)
{
	(void) philo;
	msleep(10);
	pthread_mutex_lock(&philo->info->m_printf);
	printf("philo #%d is eating\n", philo->id);
	pthread_mutex_unlock(&philo->info->m_printf);
	return ;
}

void	philo_sleep(t_philo *philo)
{
	(void) philo;
	msleep(10);
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
	pthread_mutex_lock(&philo->info->m_printf);
	printf("You created a new thread! samp_arg is: %p\n", philo);
	pthread_mutex_unlock(&philo->info->m_printf);
	philo_eat(philo);
	philo_sleep(philo);
	philo_wait(philo);
	return (0);
}
