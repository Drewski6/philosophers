/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:24:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/28 15:10:28 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	int			current;

	i = 0;
	while (i < info->num_philo)
	{
		// current = &(info->philos[i].thread_id);
		// ret = pthread_join(*current, NULL);
		// replace with kill? or maybe waitpid.
		current = info->pids[i];
		ret = kill(current, SIGINT);
		if (ret == 3)
			return (1);
		i++;
	}
	return (0);
}

/*
**	NAME
		ft_destroy_semss
**	DESCRIPTION
		Destroys semaphores to wrap up.
**	RETURN
		Void function does not return a value.
*/

static void	ft_destroy_sems(t_info *info)
{
	int	i;

	sem_destroy(&info->s_ready);
	sem_destroy(&info->s_info_data);
	sem_destroy(&info->s_printf);
	i = 0;
	while (i < info->num_philo)
		sem_destroy(&info->philos[i++].s_data);
	i = 0;
	while (i < info->num_philo)
		sem_destroy(&info->s_forks[i++]);
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
	if (info->s_forks)
	{
		ft_destroy_sems(info);
		free(info->s_forks);
		info->s_forks = NULL;
	}
	if (info->philos)
	{
		free(info->philos);
		info->philos = NULL;
	}
}
