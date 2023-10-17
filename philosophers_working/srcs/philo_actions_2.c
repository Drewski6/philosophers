/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:19:21 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/17 16:00:13 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_save_last_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_data);
	philo->last_ate = ft_get_time();
	pthread_mutex_unlock(&philo->m_data);
}

static void	ft_grab_forks_even(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_m_printf(philo->info, "%05ld %d has taken a fork\n",
		ft_get_time() - philo->info->start_time, philo->id);
	pthread_mutex_lock(philo->l_fork);
	ft_m_printf(philo->info, "%05ld %d has taken a fork\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_m_printf(philo->info, "%05ld %d is eating\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_save_last_eat(philo);
	ft_msleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	ft_grab_forks_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ft_m_printf(philo->info, "%05ld %d has taken a fork\n",
		ft_get_time() - philo->info->start_time, philo->id);
	pthread_mutex_lock(philo->r_fork);
	ft_m_printf(philo->info, "%05ld %d has taken a fork\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_m_printf(philo->info, "%05ld %d is eating\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_save_last_eat(philo);
	ft_msleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	ft_grab_forks(t_philo *philo)
{
	if (philo->id % 2)
		ft_grab_forks_odd(philo);
	else
		ft_grab_forks_even(philo);
	return ;
}

void	ft_m_printf(t_info *info, const char *s, t_ms time_stamp, int id)
{
	pthread_mutex_lock(&info->m_info_data);
	if (!info->someone_died)
	{
		pthread_mutex_lock(&info->m_printf);
		printf(s, time_stamp, id);
		pthread_mutex_unlock(&info->m_printf);
	}
	pthread_mutex_unlock(&info->m_info_data);
}
