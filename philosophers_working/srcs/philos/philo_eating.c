/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:19:21 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/25 15:46:35 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	NAME
		ft_save_last_eat
**	DESCRIPTION
		Gets the current time and saves it in the philos last_ate variable.
		Also increments the philo_num_meals eaten variable for meal tracking.
**	RETURN
		Void function does not return a value.
*/

static void	ft_save_last_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_data);
	philo->last_ate = ft_get_time();
	philo->p_num_meals += 1;
	pthread_mutex_unlock(&philo->m_data);
}

/*
**	NAME
		ft_grab_forks_even
**	DESCRIPTION
		Function for even number philosophers to grab their forks.
		- First grab r fork by locking r_fork mutex and print message.
		- Second grab l fork and print message.
		- msleep for time_to_eat time.
		- save the last time eaten after msleep.
		- Release forks in reverse order by unlocking mutex.
**	RETURN
		Void function does not return a value.
*/

static void	ft_grab_forks_even(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_m_printf(philo->info, "%ld %d has taken a fork\n",
		ft_get_time() - philo->info->start_time, philo->id);
	if (philo->r_fork == philo->l_fork)
	{
		pthread_mutex_lock(&philo->m_data);
		philo->p_num_meals += 1;
		pthread_mutex_unlock(&philo->m_data);
		ft_msleep(philo->info->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	ft_m_printf(philo->info, "%ld %d has taken a fork\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_m_printf(philo->info, "%ld %d is eating\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_msleep(philo->time_to_eat);
	ft_save_last_eat(philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return ;
}

/*
**	NAME
		ft_grab_forks_odd
**	DESCRIPTION
		Function for odd number philosophers to grab their forks.
		- First grab l fork by locking l_fork mutex and print message.
		- Second grab r fork and print message.
		- msleep for time_to_eat time.
		- save the last time eaten after msleep.
		- Release forks in reverse order by unlocking mutex.
**	RETURN
		Void function does not return a value.
*/

static void	ft_grab_forks_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ft_m_printf(philo->info, "%ld %d has taken a fork\n",
		ft_get_time() - philo->info->start_time, philo->id);
	pthread_mutex_lock(philo->r_fork);
	ft_m_printf(philo->info, "%ld %d has taken a fork\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_m_printf(philo->info, "%ld %d is eating\n",
		ft_get_time() - philo->info->start_time, philo->id);
	ft_msleep(philo->time_to_eat);
	ft_save_last_eat(philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

/*
**	NAME
		ft_philo_eat
**	DESCRIPTION
		Simply sorts philosophers by if their odd or even and calls the
		appropriate function.
**	RETURN
		Void function does not return a value.
*/

void	ft_philo_eat(t_philo *philo)
{
	if (philo->id % 2)
		ft_grab_forks_odd(philo);
	else
		ft_grab_forks_even(philo);
}

/*
	NAME
		ft_philo_odd_sync
	DESCRIPTION
		Used in the case of an odd number of philosophers.
		Adds delay times in between transitions to properly manage scheduling.
	RETURN
		Only calls waits or sleeps and does not return a value.
*/

void	ft_philo_odd_sync(t_philo *philo, int flag)
{
	if (flag == 0
		&& philo->id == 0)
	{
		ft_philo_wait(philo);
		ft_msleep(philo->time_to_eat * 2);
	}
	if (flag == 1
		&& philo->id == 0
		&& philo->p_num_meals != 0)
	{
		ft_philo_wait(philo);
		if (philo->time_to_eat < philo->info->time_to_die
			- (philo->time_to_sleep + philo->time_to_eat))
			ft_msleep(philo->time_to_eat);
	}
	if (flag == 2
		&& philo->id != 0
		&& philo->time_to_eat < philo->info->time_to_die
		- (philo->time_to_sleep + philo->time_to_eat))
		ft_msleep(philo->time_to_eat);
	return ;
}
