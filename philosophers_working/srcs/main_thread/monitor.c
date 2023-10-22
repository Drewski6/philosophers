/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:20:15 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/22 22:39:15 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	NAME
		ft_philo_died
**	DESCRIPTION
		This function Runs when ft_monitor detects that a philosopher has lived 
		passed its time_to_die.
**	RETURN
		Void function does not return a value.
*/

static void	ft_philo_died(t_philo *philo)
{
	ft_m_printf(philo->info, "%05ld %d died\n",
		ft_get_time() - philo->info->start_time, philo->id);
	pthread_mutex_lock(&philo->info->m_info_data);
	philo->info->someone_died = 1;
	pthread_mutex_unlock(&philo->info->m_info_data);
}

/*
**	NAME
		ft_check_all_philos_have_eaten
**	DESCRIPTION
		Checks that each philosopher has eaten.
		- First checks if num_tt_eat is set.
		- Second checks if num_tt_eat == p_num_meals.
		- Last runs a loop to check if all philos are done.
**	RETURN
		Returns bool value indicating 1 (SUCCESS ie. all philos have eaten)
		or 0 (FAILURE ie. not all philos have eaten or num_tt_eat not set).
*/

static bool	ft_check_all_philos_have_eaten(t_philo *philo)
{
	int		i;
	t_info	*info;

	i = 0;
	info = philo->info;
	pthread_mutex_lock(&philo->m_data);
	if (!(philo->num_tt_eat))
		return (pthread_mutex_unlock(&philo->m_data), 0);
	if (philo->num_tt_eat != philo->p_num_meals)
		return (pthread_mutex_unlock(&philo->m_data), 0);
	pthread_mutex_unlock(&philo->m_data);
	pthread_mutex_lock(&info->m_info_data);
	while (i < info->num_philo)
	{
		pthread_mutex_lock(&info->philos[i].m_data);
		if (info->philos[i].num_tt_eat != info->philos[i].p_num_meals)
			return (pthread_mutex_unlock(&info->philos[i].m_data),
				pthread_mutex_unlock(&info->m_info_data), 0);
		pthread_mutex_unlock(&info->philos[i].m_data);
		i++;
	}
	return (pthread_mutex_unlock(&info->m_info_data), 1);
}

/*
**	NAME
		ft_monitor
**	DESCRIPTION
		Used by the main thread to monitor the status of the philos' alive status
		NOTE: i++ in last function call to ft_check_all_philos_have_eaten.
			This is to save 1 line for the norminette lol.
**	RETURN
		Returns bool 1 indicating a philo has died; or 0 indicating successful
		finish.
*/

bool	ft_monitor(t_info *info)
{
	int		i;

	pthread_mutex_lock(&info->m_info_data);
	while (ft_get_time() < info->start_time)
		ft_msleep(1);
	pthread_mutex_unlock(&info->m_info_data);
	pthread_mutex_unlock(&info->m_ready);
	ft_msleep(5);
	while (1)
	{
		i = 0;
		while (i < info->num_philo)
		{
			pthread_mutex_lock(&info->philos[i].m_data);
			if (ft_get_time() - info->philos[i].last_ate >= info->time_to_die
				&& info->philos[i].p_num_meals != info->philos[i].num_tt_eat)
				return (ft_philo_died(&info->philos[i]),
					pthread_mutex_unlock(&info->philos[i].m_data), 1);
			pthread_mutex_unlock(&info->philos[i].m_data);
			if (ft_check_all_philos_have_eaten(&info->philos[i++]))
				return (0);
			usleep(1);
		}
	}
	return (0);
}
