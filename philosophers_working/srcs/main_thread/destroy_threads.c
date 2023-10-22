/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:24:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/23 00:46:42 by dpentlan         ###   ########.fr       */
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

static bool	ft_recall_philos(t_info *info)
{
	int			i;
	int			ret;
	pthread_t	*current;

	i = 0;
	while (i < info->num_philo)
	{
		current = &(info->philos[i].thread_id);
		ret = pthread_join(*current, NULL);
		if (ret == 3)
			return (1);
		i++;
	}
	return (0);
}

/*
**	NAME
		ft_destroy_mutexes
**	DESCRIPTION
		Destroys mutexes to wrap up.
**	RETURN
		Void function does not return a value.
*/

static void	ft_destroy_mutexes(t_info *info)
{
	int	i;

	pthread_mutex_destroy(&info->m_ready);
	pthread_mutex_destroy(&info->m_info_data);
	pthread_mutex_destroy(&info->m_printf);
	i = 0;
	while (i < info->num_philo)
		pthread_mutex_destroy(&info->philos[i++].m_data);
	i = 0;
	while (i < info->num_philo)
		pthread_mutex_destroy(&info->m_forks[i++]);
}

/*
**	NAME
		ft_free_info
**	DESCRIPTION
		Joins all open threads with ft_recall_philos then frees malloced
		philo info.
**	RETURN
		Void function returns nothing.
*/

void	ft_free_info(t_info *info)
{
	if (info->philos)
		ft_recall_philos(info);
	if (info->m_forks)
	{
		ft_destroy_mutexes(info);
		free(info->m_forks);
		info->m_forks = NULL;
	}
	if (info->philos)
	{
		free(info->philos);
		info->philos = NULL;
	}
}
