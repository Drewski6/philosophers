/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:24:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/17 16:01:47 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

/*
**	NAME
		ft_recall_philos
**	DESCRIPTION
		Free function for any open threads in order to cleanly exit.
**	RETURN
		Bool function returns 0 on Success and 1 on Failure.
*/

bool	ft_recall_philos(t_info *info)
{
	int			i;
	int			ret;
	pthread_t	*current;

	i = 0;
	ret = 0;
	while (i < info->num_philo)
	{
		current = &(info->philos[i].thread_id);
		pthread_mutex_lock(&info->m_info_data);
		info->someone_died = 1;
		pthread_mutex_unlock(&info->m_info_data);
		ret = pthread_join(*current, NULL);
		if (ret == 3)
			return (printf("thread with ID %ld DNE\n", *current), 1);
		i++;
	}
	return (0);
}

/*
	NAME
		ft_assign_forks
	DESCRIPTION
		Loops over the philos and assigns them an already initialized m_forks
		mutex from info->m_forks.
	RETURN
		Void functions returns nothing.
*/

void	ft_assign_forks(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->num_philo)
	{
		info->philos[i].r_fork = &info->m_forks[i];
		if (i == 0)
			info->philos[i].l_fork = &info->m_forks[info->num_philo - 1];
		else
			info->philos[i].l_fork = &info->m_forks[i - 1];
		i++;
	}
}

bool	ft_alloc_philos_and_forks(t_info *info)
{
	info->philos = (t_philo *)malloc(info->num_philo * sizeof(t_philo));
	if (!info->philos)
		return (printf("Error: malloc\n"), 1);
	ft_bzero(info->philos, sizeof(t_philo) * info->num_philo);
	info->m_forks = (pthread_mutex_t *)malloc(
			info->num_philo * sizeof(pthread_mutex_t));
	if (!info->m_forks)
		return (printf("Error: malloc\n"), 1);
	ft_bzero(info->m_forks, sizeof(pthread_mutex_t) * info->num_philo);
	return (0);
}

/*
	NAME
		ft_everyone_ready
	DESCRIPTION
		 Checks if all the philos are in ready status by looping over them.
	RETURN
		Returns 1 for true (all philos are ready) or 
		0 (at least 1 philo is not ready)for false.
*/

bool	ft_everyone_ready(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&info->m_info_data);
	if (info->everyone_ready == 1)
		return (pthread_mutex_unlock(&info->m_info_data), 1);
	pthread_mutex_unlock(&info->m_info_data);
	while (i < info->num_philo)
	{
		pthread_mutex_lock(&info->philos[i].m_data);
		if (info->philos[i].ready != 1)
			return (pthread_mutex_unlock(&info->philos[i].m_data), 0);
		pthread_mutex_unlock(&info->philos[i].m_data);
		i++;
	}
	pthread_mutex_lock(&info->m_info_data);
	info->everyone_ready = 1;
	pthread_mutex_unlock(&info->m_info_data);
	return (1);
}

void	ft_set_philo_ready(t_philo *philo, bool status)
{
	pthread_mutex_lock(&philo->m_data);
	philo->ready = status;
	pthread_mutex_unlock(&philo->m_data);
}
