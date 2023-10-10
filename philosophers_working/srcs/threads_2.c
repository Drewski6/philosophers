/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:24:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/10 16:13:57 by dpentlan         ###   ########.fr       */
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
		info->philos[i].dead = 1;
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
