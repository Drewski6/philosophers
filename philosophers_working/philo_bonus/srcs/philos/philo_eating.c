/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:19:21 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/28 15:56:21 by dpentlan         ###   ########.fr       */
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
	sem_wait(philo->s_data);
	philo->last_ate = ft_get_time();
	if (philo->p_num_meals == -1)
		philo->p_num_meals = 1;
	else
		philo->p_num_meals += 1;
	sem_post(philo->s_data);
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
	sem_wait(philo->r_fork);
	ft_m_printf(philo, "%s%ld %s%d %shas taken a fork\n",
		ft_get_time() - philo->info->start_time);
	if (philo->r_fork == philo->l_fork)
	{
		sem_wait(philo->s_data);
		if (philo->p_num_meals == -1)
			philo->p_num_meals = 1;
		else
			philo->p_num_meals += 1;
		sem_post(philo->s_data);
		ft_msleep(philo->info, philo->info->time_to_die);
		sem_post(philo->r_fork);
		return ;
	}
	sem_wait(philo->l_fork);
	ft_m_printf(philo, "%s%ld %s%d %shas taken a fork\n",
		ft_get_time() - philo->info->start_time);
	ft_m_printf(philo, "%s%ld %s%d %sis eating\n",
		ft_get_time() - philo->info->start_time);
	ft_save_last_eat(philo);
	ft_msleep(philo->info, philo->time_to_eat);
	sem_post(philo->l_fork);
	sem_post(philo->r_fork);
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
	sem_wait(philo->l_fork);
	ft_m_printf(philo, "%s%ld %s%d %shas taken a fork\n",
		ft_get_time() - philo->info->start_time);
	sem_wait(philo->r_fork);
	ft_m_printf(philo, "%s%ld %s%d %shas taken a fork\n",
		ft_get_time() - philo->info->start_time);
	ft_m_printf(philo, "%s%ld %s%d %sis eating\n",
		ft_get_time() - philo->info->start_time);
	if (!ft_msleep(philo->info, philo->time_to_eat))
		ft_save_last_eat(philo);
	sem_post(philo->r_fork);
	sem_post(philo->l_fork);
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
		&& philo->id == 0
		&& philo->p_num_meals > 0)
	{
		ft_philo_wait(philo);
		if (ft_msleep(philo->info, philo->time_to_eat * 2))
			return ;
	}
	if (flag == 1
		&& philo->id == 0
		&& philo->p_num_meals != 0)
	{
		ft_philo_wait(philo);
		if (philo->time_to_eat < philo->info->time_to_die
			- (philo->time_to_sleep + philo->time_to_eat))
			ft_msleep(philo->info, philo->time_to_eat);
		return ;
	}
	if (flag == 2
		&& philo->id != 0
		&& philo->time_to_eat < philo->info->time_to_die
		- (philo->time_to_sleep + philo->time_to_eat))
		ft_msleep(philo->info, philo->time_to_eat);
	return ;
}
