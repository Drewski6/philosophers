/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:18:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/09 23:19:30 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

/*
**	NAME
		ft_create_philos
**	DESCRIPTION
		Loop that creates philosophers.
**	RETURN
		Returns 0 on Success and 1 on Failure.
*/

static bool	ft_create_philos(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->num_philo)
	{
		info->philos[i].id = i;
		info->philos[i].info = info;
		if (pthread_create(&info->philos[i].thread_id, NULL,
				ft_pthread_entry_point, &info->philos[i]))
			return (printf("Error: Could not create all philosophers\n"), 1);
		i++;
	}
	return (0);
}

/*
**	NAME
		ft_init_mutexes
**	DESCRIPTION
		Initializes all mutexes that will be used.
**	RETURN
		Returns 0 on Success and 1 on Failure.
*/

static bool	ft_init_mutexes(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->m_printf, NULL))
		return (1);
	while (i < info->num_philo)
		pthread_mutex_init(&info->philos[i++].m_fork, NULL);
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

	i = 0;
	pthread_mutex_destroy(&info->m_printf);
	while (i < info->num_philo)
		pthread_mutex_destroy(&info->philos[i++].m_fork);
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
	ft_recall_philos(info);
	ft_destroy_mutexes(info);
	if (info->philos)
		free(info->philos);
	info->philos = NULL;
}

/*
**	NAME
		ft_philo_init
**	DESCRIPTION
		Calls basic setup functions: Arg parsing, initializing mutexes, setting
		start time, and calls function to create all philos.
**	RETURN
		Returns 0 on Success or 1 on Failure.
*/

bool	ft_philo_init(int argc, char **argv, t_info *info)
{
	if (ft_arg_count(argc))
		return (1);
	if (ft_arg_parse(argc, argv, info))
		return (1);
	info->philos = (t_philo *)malloc(info->num_philo * sizeof(t_philo));
	if (!info->philos)
		return (printf("Error: malloc\n"), 1);
	ft_bzero(info->philos, sizeof(t_philo) * info->num_philo);
	if (ft_init_mutexes(info))
		return (1);
	info->start_time = ft_get_time();
	if (ft_create_philos(info))
		return (1);
	return (0);
}

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
		ret = pthread_join(*current, NULL);
		if (ret == 3)
			return (printf("thread with ID %ld DNE\n", *current), 1);
		i++;
	}
	return (0);
}
