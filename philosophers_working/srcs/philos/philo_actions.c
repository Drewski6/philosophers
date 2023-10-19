/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/19 12:43:40 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static void	ft_philo_sleep(t_philo *philo)
{
	ft_m_printf(philo->info, "%05ld %d is sleeping\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_msleep(philo->info->time_to_sleep);
	return ;
}

static void	ft_philo_wait(t_philo *philo)
{
	ft_m_printf(philo->info, "%05ld %d is thinking\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_msleep(1);
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

static bool	ft_philo_check_num_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_data);
	if (philo->p_num_meals == philo->num_tt_eat)
		return (pthread_mutex_unlock(&philo->m_data), 1);
	return (pthread_mutex_unlock(&philo->m_data), 0);
}

/*
	NAME
		ft_pthread_entry_point
	DESCRIPTION
		Entry point for newly created threads.
	RETURN
		Only returns null pointer on completion.
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
		if (ft_philo_check_num_meals(philo))
			return (0);
	}
	return (0);
}
