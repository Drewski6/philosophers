/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/29 21:35:40 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	NAME
		ft_philo_sleep
**	DESCRIPTION
		Prints that the philosopher is sleeping, then sleeps.
**	RETURN
		Bool function returns 0 on success and 1 on failed sleep.
*/

static bool	ft_philo_sleep(t_philo *philo)
{
	ft_m_printf(philo, "%s%ld %s%d %sis sleeping\n",
		ft_get_time() - philo->info->start_time);
	if (ft_msleep(philo->info, philo->time_to_sleep))
		return (1);
	return (0);
}

/*
**	NAME
		ft_philo_wait
**	DESCRIPTION
		Prints that this philosopher is thinking, then sleeps for 1 ms.
**	RETURN
		Void function does not return a value.
*/

void	ft_philo_wait(t_philo *philo)
{
	ft_m_printf(philo, "%s%ld %s%d %sis thinking\n",
		ft_get_time() - philo->info->start_time);
	ft_msleep(NULL, 1);
	return ;
}

/*
**	NAME
		ft_check_if_philo_dead
**	DESCRIPTION
		Checks if any philo has died yet by checking info struct.
**	RETURN
		Bool function returns 1 if someone_died is set to 1
		or 0 if someone_died is set to 0.
*/

bool	ft_check_if_philo_dead(t_info *info)
{
	pthread_mutex_lock(&info->m_info_data);
	if (info->someone_died)
		return (pthread_mutex_unlock(&info->m_info_data), 1);
	else
		return (pthread_mutex_unlock(&info->m_info_data), 0);
}

/*
**	NAME
		ft_philo_check_num_meals
**	DESCRIPTION
		Checks if the philo has eaten has many meals as he/she should have.
**	RETURN
		Bool function returns 1 if philo has eaten enough meals,
		or 0 if philo has not eaten enough meals.
*/

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
		This is the philo loop.
	RETURN
		Only returns NULL (0x0) on completion.
*/

void	*ft_pthread_entry_point(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&philo->info->m_ready);
	pthread_mutex_unlock(&philo->info->m_ready);
	if (philo->info->num_philo % 2)
		ft_philo_odd_sync(philo, 0);
	while (1)
	{
		if (philo->id % 2)
			ft_philo_wait(philo);
		if (philo->info->num_philo % 2)
			ft_philo_odd_sync(philo, 1);
		ft_philo_eat(philo);
		ft_philo_sleep(philo);
		if (ft_check_if_philo_dead(philo->info))
			return (0);
		if (!(philo->id % 2))
			ft_philo_wait(philo);
		if (ft_philo_check_num_meals(philo))
			return (0);
		if (philo->info->num_philo % 2)
			ft_philo_odd_sync(philo, 2);
	}
	return (0);
}
